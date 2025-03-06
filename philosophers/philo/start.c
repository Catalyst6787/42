/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:20:26 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/06 15:20:46 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(t_philo *philo)
{
	philo_logic(philo);
	return (NULL);
}

void	start_philo(t_state *state)
{
	t_philo	*current;

	current = state->first;
	while (current)
	{
		pthread_create(&(current->thread_id), NULL,
			(void *)start_routine, current);
		if (current->id < current->left->id)
			current = current->left;
		else
			current = NULL;
	}
}
