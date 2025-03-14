/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:44:10 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/12 18:25:28 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mysleep(unsigned int ms)
{
	unsigned int us;

	us = 1000 * ms;
	usleep(us);
}

unsigned long	spent_time_ms(t_state *state)
{
	struct timeval	current_tv;
	unsigned long	spent_time;

	current_tv.tv_sec = 0;
	current_tv.tv_usec = 0;
	gettimeofday(&current_tv, NULL);
	spent_time = 0;
	spent_time += ((current_tv.tv_sec - state->start_time_s) * 1000);
	spent_time += ((current_tv.tv_usec - state->start_time_us) / 1000);
	return (spent_time);
}

// void	set_mutex_nbr_meal(t_philo *philo, unsigned int nbr_meal)
// {
// 	pthread_mutex_lock(&philo->nbr_of_meal_mutex);
// 	philo->nbr_of_meal = nbr_meal;
// 	pthread_mutex_unlock(&philo->nbr_of_meal_mutex);
// }

// void	log_action_mutex(t_philo *philo, t_log_action log)
// {
// 	pthread_mutex_lock(&philo->state->log);
// 	if (log == take_left_log)
// 		printf("%lums %u has taken left fork\n",
// 			spent_time_ms(philo->state), philo->id);
// 	else if (log == take_right_log)
// 		printf("%lums %u has taken right fork\n",
// 			spent_time_ms(philo->state), philo->id);
// 	else if (log == eat_log)
// 		printf("%lums %u is eating\n",
// 			spent_time_ms(philo->state), philo->id);
// 	else if (log == sleep_log)
// 		printf("%lums %u is sleeping\n",
// 			spent_time_ms(philo->state), philo->id);
// 	else if (log == think_log)
// 		printf("%lums %u is thinking\n",
// 			spent_time_ms(philo->state), philo->id);
// 	else if (log == die_log)
// 		printf("\033[1;31m%lums %u died. last meal was %u\033[0m\n",
// 			spent_time_ms(philo->state), philo->id, philo->last_meal);
// 	pthread_mutex_unlock(&philo->state->log);
// }
