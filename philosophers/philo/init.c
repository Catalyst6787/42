/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:44:52 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/20 16:30:12 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int ac, char **av, t_state *state)
{
	pthread_mutex_init(&state->is_over_mutex, NULL);
	pthread_mutex_init(&state->log, NULL);
	state->is_over = 0;
	state->nbr_philo = (unsigned int)ft_atou(av[1]);
	state->tt_die = (unsigned int)ft_atou(av[2]);
	state->tt_eat = (unsigned int)ft_atou(av[3]);
	state->tt_sleep = (unsigned int)ft_atou(av[4]);
	if (ac == 6)
		state->nbr_eat = (unsigned int)ft_atou(av[5]);
	else
		state->nbr_eat = -1;
	state->first = NULL;
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

void	init_start_time(t_state *state)
{
	struct timeval	tv;

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	gettimeofday(&tv, NULL);
	state->start_time_s = tv.tv_sec;
	state->start_time_us = tv.tv_usec;
}

static	t_philo	*create_philo(t_state *state, unsigned int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->id = id;
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->nbr_of_meal_mutex, NULL);
	pthread_mutex_init(&philo->last_meal_mutex, NULL);
	philo->nbr_of_meal = 0;
	philo->last_meal = 0;
	philo->thread_id = 0;
	philo->state = state;
	philo->left = NULL;
	return (philo);
}

void	init_philo(t_state *state)
{
	t_philo	*current;
	t_philo	*next;

	current = create_philo(state, 1);
	state->first = current;
	while (current->id < state->nbr_philo)
	{
		next = create_philo(state, current->id + 1);
		current->left = next;
		current = next;
	}
	current->left = state->first;
}
