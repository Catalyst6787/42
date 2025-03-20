/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:44:52 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/20 14:07:40 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int ac, char **av, t_philo *philo)
{
	philo->nbr_philo = (unsigned int)ft_atou(av[1]);
	philo->tt_die = (unsigned int)ft_atou(av[2]);
	philo->tt_eat = (unsigned int)ft_atou(av[3]);
	philo->tt_sleep = (unsigned int)ft_atou(av[4]);
	philo->nbr_of_meal = 0;
	if (ac == 6)
		philo->nbr_eat = (unsigned int)ft_atou(av[5]);
	else
		philo->nbr_eat = -1;
	philo->is_over = 0;
	philo->last_meal = 0;
}

int	check_args(int ac, char **av)
{
	if ((ft_atou(av[1]) < 0) || (ft_atou(av[2]) < 0)
		|| (ft_atou(av[3]) < 0) || (ft_atou(av[4]) < 0))
		return (1);
	if (ac == 6 && ft_atou(av[5]) < 0)
		return (1);
	return (0);
}

void	init_start_time(t_philo *philo)
{
	struct timeval	tv;

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	gettimeofday(&tv, NULL);
	philo->start_time_s = tv.tv_sec;
	philo->start_time_us = tv.tv_usec;
}
