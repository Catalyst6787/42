/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:11:23 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/14 14:47:22 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo, unsigned int id)
{
	int	i;

	i = 0;
	philo->id = id;
	while(i < 10)
	{
		usleep(20000);
		printf("philo nbr: %u, ate %i times\n", philo->id, i);
		i++;
	}
}

void	start_processes(t_philo *philo)
{
	unsigned int id;
	unsigned int pid;

	id = 1;
	pid = 0;
	while(id <= philo->nbr_philo)
	{
		pid = fork();
		if (pid == 0)
			return(start_philo(philo, id));
		else
			philo->pids[id - 1] = pid;
		id++;
	}
}

int	main(int ac, char **av)
{
	t_philo		*philo;

	if (ac < 5 || ac > 6)
		return (printf("%s\n", USAGE), 1);
	if (check_args(ac, av))
		return (printf("arguments must be positive integers\n"), 1);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return(printf("malloc error\n"), 1);
	init_args(ac, av, philo);
	if (philo->nbr_philo == 0)
		return (free(philo), 0);
	init_start_time(philo);
	philo->pids = malloc(sizeof(unsigned int) * philo->nbr_philo);
	start_processes(philo);
	free(philo);
	return (0);
}
