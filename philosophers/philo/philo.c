/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:11:23 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/06 15:14:27 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_state		*state;
	pthread_t	manager_id;

	if (ac < 5 || ac > 6)
		return (printf("%s\n", USAGE), 1);
	if (check_args(ac, av))
		return (printf("arguments must be positive integers\n"), 1);
	state = malloc(sizeof(t_state));
	init_args(ac, av, state);
	if (state->nbr_philo == 0)
		return (free(state), 0);
	init_philo(state);
	init_start_time(state);
	start_philo(state);
	pthread_create(&manager_id, NULL, (void *)manager, state);
	wait_philo(state);
	pthread_join(manager_id, NULL);
	free_philo(state);
	pthread_mutex_destroy(&state->log);
	pthread_mutex_destroy(&state->is_over_mutex);
	free(state);
	return (0);
}
