/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:19:56 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/06 15:19:57 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philo(t_state *state)
{
	t_philo	*current;

	current = state->first;
	while (current)
	{
		pthread_join(current->thread_id, NULL);
		if (current->left && current->id < current->left->id)
			current = current->left;
		else
			current = NULL;
	}
}

void	free_philo(t_state *state)
{
	t_philo			*tail;
	t_philo			*next;
	unsigned int	id;

	tail = state->first;
	id = 0;
	while (tail && tail->id <= state->nbr_philo)
	{
		id = tail->id;
		if (tail->id < state->nbr_philo)
			next = tail->left;
		pthread_mutex_destroy(&tail->fork);
		pthread_mutex_destroy(&tail->last_meal_mutex);
		pthread_mutex_destroy(&tail->nbr_of_meal_mutex);
		free(tail);
		if (id < state->nbr_philo)
			tail = next;
		else
			tail = NULL;
	}
}
