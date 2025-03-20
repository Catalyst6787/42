/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:11:23 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/20 16:55:11 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_processes(t_philo *philo)
{
	unsigned int	id;
	unsigned int	pid;

	id = 0;
	pid = 0;
	while (id < philo->nbr_philo)
	{
		pid = fork();
		if (pid == 0)
			return (start_philo(philo, id));
		else
		{
			philo->pids[id] = pid;
			id++;
		}
	}
}

unsigned int	init_semaphores(t_philo *philo)
{
	sem_unlink("sem_forks");
	sem_unlink("sem_is_done");
	sem_unlink("logs");
	sem_unlink("sem_last_meal");
	sem_unlink("sem_is_over");
	philo->forks = sem_open("sem_forks", O_CREAT, 0777, philo->nbr_philo);
	if (philo->forks == SEM_FAILED)
		return (1);
	philo->is_done = sem_open("sem_is_done", O_CREAT, 0777, philo->nbr_philo);
	if (philo->is_done == SEM_FAILED)
		return (sem_close(philo->forks), 1);
	philo->logs = sem_open("logs", O_CREAT, 0777, 1);
	if (philo->logs == SEM_FAILED)
		return (sem_close(philo->forks), sem_close(philo->is_done), 1);
	philo->last_meal_sem = sem_open("sem_last_meal", O_CREAT, 0777, 1);
	if (philo->last_meal_sem == SEM_FAILED)
		return (sem_close(philo->forks),
			sem_close(philo->is_done), sem_close(philo->logs), 1);
	philo->is_over_sem = sem_open("sem_is_over", O_CREAT, 0777, 1);
	if (philo->is_over_sem == SEM_FAILED)
		return (sem_close(philo->forks), sem_close(philo->is_done),
			sem_close(philo->logs), sem_close(philo->last_meal_sem), 1);
	return (0);
}

void	wait_and_kill_philos(t_philo *philo)
{
	unsigned int	nbr_done;
	unsigned int	i;

	i = 0;
	nbr_done = 0;
	usleep(200);
	while (nbr_done < philo->nbr_philo)
	{
		sem_wait(philo->is_done);
		nbr_done++;
	}
	while (i < philo->nbr_philo)
	{
		kill(philo->pids[i], SIGINT);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo			*philo;

	if (ac < 5 || ac > 6)
		return (printf("%s\n", USAGE), 1);
	if (check_args(ac, av))
		return (printf("arguments must be positive integers\n"), 1);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (printf("malloc error\n"), 1);
	init_args(ac, av, philo);
	if (philo->nbr_philo == 0 || philo->nbr_eat == 0)
		return (free(philo), 0);
	philo->pids = malloc(sizeof(unsigned int) * philo->nbr_philo);
	if (init_semaphores(philo))
		return (free(philo), 1);
	init_start_time(philo);
	start_processes(philo);
	wait_and_kill_philos(philo);
	free(philo->pids);
	free(philo);
	return (0);
}
