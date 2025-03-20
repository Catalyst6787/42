/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:49:57 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/20 16:50:01 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_last_meal(t_philo *philo)
{
	unsigned int	last_meal;

	sem_wait(philo->last_meal_sem);
	last_meal = philo->last_meal;
	sem_post(philo->last_meal_sem);
	return (last_meal);
}

void	set_last_meal(t_philo *philo, unsigned int new_last_meal)
{
	sem_wait(philo->last_meal_sem);
	philo->last_meal = new_last_meal;
	sem_post(philo->last_meal_sem);
}

unsigned int	get_is_over(t_philo *philo)
{
	unsigned int	is_over;

	sem_wait(philo->is_over_sem);
	is_over = philo->is_over;
	sem_post(philo->is_over_sem);
	return (is_over);
}

void	set_is_over(t_philo *philo, unsigned int is_over)
{
	sem_wait(philo->is_over_sem);
	philo->is_over = is_over;
	sem_post(philo->is_over_sem);
}
