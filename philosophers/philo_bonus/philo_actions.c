/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:51:57 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/20 16:52:02 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	if_first(t_philo *philo, unsigned int first)
{
	if (philo->id % 2 && first)
	{
		mysleep(1);
		first = 0;
	}
	if (get_is_over(philo))
	{
		sem_post(philo->is_done);
		return (1);
	}
	return (0);
}

unsigned int	take_forks(t_philo *philo)
{
	sem_wait(philo->forks);
	if (philo->is_over)
	{
		sem_post(philo->forks);
		sem_post(philo->is_done);
		return (1);
	}
	log_action(philo, take_1_log, NULL);
	sem_wait(philo->forks);
	if (get_is_over(philo))
	{
		sem_post(philo->forks);
		sem_post(philo->forks);
		sem_post(philo->is_done);
		return (1);
	}
	log_action(philo, take_2_log, NULL);
	return (0);
}

unsigned int	eat(t_philo *philo)
{
	philo->nbr_of_meal++;
	set_last_meal(philo, spent_time_ms(philo));
	log_action(philo, eat_log, NULL);
	if (philo->nbr_eat != -1
		&& philo->nbr_of_meal >= (unsigned int)philo->nbr_eat)
		sem_post(philo->is_done);
	mysleep(philo->tt_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (get_is_over(philo))
	{
		sem_post(philo->is_done);
		return (1);
	}
	return (0);
}

unsigned int	philo_sleep_think(t_philo *philo)
{
	log_action(philo, sleep_log, NULL);
	mysleep(philo->tt_sleep);
	if (get_is_over(philo))
	{
		sem_post(philo->is_done);
		return (1);
	}
	log_action(philo, think_log, NULL);
	usleep(200);
	return (0);
}

void	philo_loop(t_philo *philo, unsigned int first)
{
	while (!philo->is_over && (philo->nbr_eat == -1
			|| philo->nbr_of_meal < (unsigned int)philo->nbr_eat))
	{
		if (if_first(philo, first))
			break ;
		if (take_forks(philo))
			break ;
		if (eat(philo))
			break ;
		if (philo_sleep_think(philo))
			break ;
	}
}
