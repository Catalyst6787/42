/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:44:52 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/14 14:13:06 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int ac, char **av, t_philo *philo)
{
	philo->nbr_philo = (unsigned int)ft_atou(av[1]);
	philo->tt_die = (unsigned int)ft_atou(av[2]);
	philo->tt_eat = (unsigned int)ft_atou(av[3]);
	philo->tt_sleep = (unsigned int)ft_atou(av[4]);
	if (ac == 6)
		philo->nbr_eat = (unsigned int)ft_atou(av[5]);
	else
		philo->nbr_eat = -1;
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

// static	t_philo	*create_philo(t_philo *philo, unsigned int id)
// {
// 	t_philo	*philo;

// 	philo = malloc(sizeof(t_philo));
// 	philo->id = id;
// 	pthread_mutex_init(&philo->fork, NULL);
// 	pthread_mutex_init(&philo->nbr_of_meal_mutex, NULL);
// 	pthread_mutex_init(&philo->last_meal_mutex, NULL);
// 	philo->nbr_of_meal = 0;
// 	philo->last_meal = 0;
// 	philo->thread_id = 0;
// 	philo->philo = philo;
// 	philo->left = NULL;
// 	return (philo);
// }

// void	init_philo(t_philo *philo)
// {
// 	t_philo	*current;
// 	t_philo	*next;

// 	current = create_philo(philo, 1);
// 	philo->first = current;
// 	while (current->id < philo->nbr_philo)
// 	{
// 		next = create_philo(philo, current->id + 1);
// 		current->left = next;
// 		current = next;
// 	}
// 	current->left = philo->first;
// }
