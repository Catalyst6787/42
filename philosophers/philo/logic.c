/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:57:18 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/06 15:10:01 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_left_fork(t_philo *philo)
{
	if (is_over(philo->state))
		return (1);
	pthread_mutex_lock(&philo->left->fork);
	pthread_mutex_lock(&philo->state->is_over_mutex);
	if (philo->state->is_over)
		return (pthread_mutex_unlock(&philo->left->fork),
			pthread_mutex_unlock(&philo->state->is_over_mutex), 1);
	log_action_mutex(philo, take_left_log);
	pthread_mutex_unlock(&philo->state->is_over_mutex);
	return (0);
}

static int	take_right_fork(t_philo *philo)
{
	if (is_over(philo->state))
		return (1);
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->state->is_over_mutex);
	if (philo->state->is_over)
		return (pthread_mutex_unlock(&philo->fork),
			pthread_mutex_unlock(&philo->state->is_over_mutex), 1);
	log_action_mutex(philo, take_right_log);
	pthread_mutex_unlock(&philo->state->is_over_mutex);
	return (0);
}

int	eat(t_philo *philo)
{
	if ((philo->id) % 2)
	{
		usleep(200);
		if (take_left_fork(philo))
			return (1);
		if (philo->left == philo)
			return (pthread_mutex_unlock(&philo->left->fork), 1);
		if (take_right_fork(philo))
			return (pthread_mutex_unlock(&philo->left->fork), 1);
	}
	else
	{
		if (take_right_fork(philo))
			return (1);
		if (take_left_fork(philo))
			return (pthread_mutex_unlock(&philo->fork), 1);
	}
	if (is_over(philo->state))
		return (1);
	log_action_mutex(philo, eat_log);
	set_mutex_nbr_meal(philo, get_mutex_nbr_meal(philo) + 1);
	set_mutex_last_meal(philo, spent_time_ms(philo->state));
	usleep(philo->state->tt_eat);
	return (pthread_mutex_unlock(&philo->left->fork),
		pthread_mutex_unlock(&philo->fork), 0);
}

int	philo_logic(t_philo *philo)
{
	if (!(philo->state->nbr_eat < 0)
		&& (unsigned int)philo->state->nbr_eat == get_mutex_nbr_meal(philo))
		return (0);
	while (!(is_over(philo->state)))
	{
		if (eat(philo))
			return (0);
		if (!(is_over(philo->state)))
		{
			log_action_mutex(philo, sleep_log);
			usleep(philo->state->tt_sleep);
		}
		if (!(is_over(philo->state)))
			log_action_mutex(philo, think_log);
	}
	return (0);
}
