/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:44:10 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/19 13:31:45 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mysleep(unsigned int ms)
{
	unsigned int us;

	us = 1000 * ms;
	usleep(us);
}

unsigned long	spent_time_ms(t_philo *philo)
{
	struct timeval	current_tv;
	unsigned long	spent_time;

	current_tv.tv_sec = 0;
	current_tv.tv_usec = 0;
	gettimeofday(&current_tv, NULL);
	spent_time = 0;
	spent_time += ((current_tv.tv_sec - philo->start_time_s) * 1000);
	spent_time += ((current_tv.tv_usec - philo->start_time_us) / 1000);
	return (spent_time);
}

void	log_action(t_philo *philo, t_log_action action, char *custom)
{
	// printf("log action with code %d\n", action);
	sem_wait(philo->logs);
	if (action == take_1_log)
		printf("%lu, %u, has taken 1st fork\n", spent_time_ms(philo), philo->id);
	else if (action == take_2_log)
		printf("%lu, %u, has taken 2nd fork\n", spent_time_ms(philo), philo->id);
	else if (action == eat_log)
		printf("%lu, %u, is eating\n", spent_time_ms(philo), philo->id);
	else if (action == sleep_log)
		printf("%lu, %u, is sleeping\n", spent_time_ms(philo), philo->id);
	else if (action == think_log)
		printf("%lu, %u, is thinking\n", spent_time_ms(philo), philo->id);
	else if (action == die_log)
		printf("\033[1;31m%lums %u died. last meal was %u\033[0m\n",
			spent_time_ms(philo), philo->id, philo->last_meal);
	else if (action == custom_log)
		printf("%lu, %u, %s\n", spent_time_ms(philo), philo->id, custom);
	sem_post(philo->logs);
}
