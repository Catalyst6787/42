/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:11:23 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/14 15:21:10 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo, unsigned int id)
{
	philo->id = id;
	philo->forks = sem_open("sem_forks", O_CREAT, 0777, philo->nbr_philo);
	if (philo->forks == SEM_FAILED)
		return((void)printf("sem failed\n"));
	while(philo->nbr_of_meal < (unsigned int)philo->nbr_eat)
	{
		if (philo->id % 2 && philo->nbr_of_meal == 0)
		{
			sem_wait(philo->forks);
			sem_post(philo->forks);
		}
		printf("%u tries to take fork1\n", philo->id);
		sem_wait(philo->forks);
		printf("%u has taken fork1\n", philo->id);
		printf("%u tries to take fork2\n", philo->id);
		sem_wait(philo->forks);
		printf("%u has taken fork2\n", philo->id);
		mysleep(philo->tt_eat);
		printf("%u, ate %i times\n", philo->id, philo->nbr_of_meal + 1);
		printf("%u, sleeps\n", philo->id);
		mysleep(philo->tt_sleep);
		sem_post(philo->forks);
		sem_post(philo->forks);
		philo->nbr_of_meal++;
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
	sem_unlink("sem_forks");
	start_processes(philo);
	free(philo);
	return (0);
}
