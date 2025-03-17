’p/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:11:23 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/14 16:17:27 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo, unsigned int id)
{
	free(philo->pids);
	philo->pids = NULL;
	philo->id = id + 1;
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
		printf("%u, ate %i times\n", philo->id, philo->nbr_of_meal + 1);
		mysleep(philo->tt_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		printf("%u, sleeps\n", philo->id);
		mysleep(philo->tt_sleep);
		philo->nbr_of_meal++;
	}
	sem_post(&philo->is_done);
	free(philo);
}

void	start_processes(t_philo *philo)
{
	unsigned int id;
	unsigned int pid;

	id = 0;
	pid = 0;
	philo->ppid = get
	while(id < philo->nbr_philo)
	{
		pid = fork();
		if (pid == 0)
			return(start_philo(philo, id));
		else
		{
			id++;
			philo->pids[id] = pid;
		}
	}
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	unsigned int	nbr_done;

	nbr_done = 0;
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
	while(nbr_done < philo->nbr_philo)
		sem_wait(philo->is_done);
	free(philo->pids);
	free(philo);
	return (0);
}
