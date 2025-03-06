/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:09:54 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/06 15:10:23 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_ate_enough(t_philo *first)
{
	t_philo	*current;

	current = first;
	if ((int)get_mutex_nbr_meal(current) >= first->state->nbr_eat)
	{
		current = current->left;
		while (current != first)
		{
			if ((int)get_mutex_nbr_meal(current) < current->state->nbr_eat)
				return (0);
			current = current->left;
		}
		return (1);
	}
	return (0);
}

void	*manager(t_state *state)
{
	t_philo	*current;

	current = state->first;
	while (current && !state->is_over)
	{
		if ((unsigned long)state->tt_die
			<= (spent_time_ms(state)
				- (unsigned long)get_mutex_last_meal(current))
			&& (state->nbr_eat == -1 || get_mutex_nbr_meal(current)
				< (unsigned int)state->nbr_eat))
			return (set_mutex_isover(state, 1),
				log_action_mutex(current, die_log), NULL);
		current = current->left;
		if (current == state->first)
		{
			if (state->nbr_eat != -1 && all_ate_enough(state->first))
				return (set_mutex_isover(state, 1), NULL);
			usleep(1000);
		}
	}
	return (NULL);
}
