/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:57:18 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/06 16:35:46 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	if (philo->left == philo)
		return(log_action_mutex(philo, take_fork1_log), 1);
	if (philo->id % 2)
		usleep(200);
	sem_wait(philo->state->forks_sem);
	log_action_mutex(philo, take_fork1_log);
	if (is_over(philo->state))
		return (sem_post(philo->state->forks_sem), 1);
	sem_wait(philo->state->forks_sem);
	log_action_mutex(philo, take_fork2_log);
	if (is_over(philo->state))
		return (sem_post(philo->state->forks_sem), sem_post(philo->state->forks_sem), 1);
	log_action_mutex(philo, eat_log);
	set_mutex_nbr_meal(philo, get_mutex_nbr_meal(philo) + 1);
	set_mutex_last_meal(philo, spent_time_ms(philo->state));
	usleep(philo->state->tt_eat);
	sem_post(philo->state->forks_sem);
	sem_post(philo->state->forks_sem);
	return (0);
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
