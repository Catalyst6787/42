/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:23:29 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/06 15:24:32 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_mutex_isover(t_state *state, unsigned int isover)
{
	pthread_mutex_lock(&state->is_over_mutex);
	state->is_over = isover;
	pthread_mutex_unlock(&state->is_over_mutex);
}

unsigned int	is_over(t_state *state)
{
	unsigned int	isover;

	pthread_mutex_lock(&state->is_over_mutex);
	isover = state->is_over;
	pthread_mutex_unlock(&state->is_over_mutex);
	return (isover);
}

unsigned int	get_mutex_last_meal(t_philo *philo)
{
	unsigned int	last_meal;

	pthread_mutex_lock(&philo->last_meal_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (last_meal);
}

void	set_mutex_last_meal(t_philo *philo, unsigned int last_meal)
{
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = last_meal;
	pthread_mutex_unlock(&philo->last_meal_mutex);
}

unsigned int	get_mutex_nbr_meal(t_philo *philo)
{
	unsigned int	nbr_meal;

	pthread_mutex_lock(&philo->nbr_of_meal_mutex);
	nbr_meal = philo->nbr_of_meal;
	pthread_mutex_unlock(&philo->nbr_of_meal_mutex);
	return (nbr_meal);
}
