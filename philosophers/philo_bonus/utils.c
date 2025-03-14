/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:44:10 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/14 14:29:04 by lfaure           ###   ########.fr       */
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
