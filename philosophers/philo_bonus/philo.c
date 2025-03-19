/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:11:23 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/19 17:49:17 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*manager(t_philo	*philo)
{
	unsigned int	i;

	i = 0;
	mysleep(philo->tt_die);
	while (!philo->is_over)
	{
		if ((spent_time_ms(philo) - philo->last_meal) >= philo->tt_die)
		{
			philo->is_over = 1;
			log_action(philo, die_log, NULL);
			while (i < philo->nbr_philo)
			{
				sem_post(philo->is_done);
				i++;
			}
			pthread_exit(0);
		}
		else
			mysleep(philo->tt_die - (spent_time_ms(philo) - philo->last_meal));
	}
	return(NULL);
}

void	start_philo(t_philo *philo, unsigned int id)
{
	unsigned int	first;
	pthread_t		manager_tid;

	first = 1;
	philo->id = id + 1;
	philo->logs = sem_open("logs", 0);
	philo->is_done = sem_open("sem_is_done", 0);
	// log_action(philo, custom_log,"WAIT is_done");
	sem_wait(philo->is_done);
	free(philo->pids);
	philo->pids = NULL;

	philo->forks = sem_open("sem_forks", 0);


	if (philo->forks == SEM_FAILED)
		return(log_action(philo, custom_log, "sem failed\n"));
	pthread_create(&manager_tid, NULL, (void *)manager, philo);
	while(!philo->is_over && (philo->nbr_eat == -1 || philo->nbr_of_meal < (unsigned int)philo->nbr_eat))
	{
		if (philo->id % 2 && first)
		{
			mysleep(1);
			first = 0;
		}
		// log_action(philo, custom_log, "tries to take 1st fork");
		sem_wait(philo->forks);
		log_action(philo, take_1_log, NULL);
		// log_action(philo, custom_log, "tries to take 2nd fork");
		sem_wait(philo->forks);
		log_action(philo, take_2_log, NULL);
		philo->nbr_of_meal++;
		philo->last_meal = spent_time_ms(philo);
		if (philo->nbr_eat != -1 && philo->nbr_of_meal >= (unsigned int)philo->nbr_eat)
			sem_post(philo->is_done);
		log_action(philo, eat_log, NULL);
		mysleep(philo->tt_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		// log_action(philo, custom_log, "POST 2 FORKS");
		log_action(philo, sleep_log, NULL);
		mysleep(philo->tt_sleep);
		log_action(philo, think_log, NULL);
		usleep(200);
	}
	sem_close(philo->is_done);
	sem_close(philo->forks);
	sem_close(philo->logs);
	free(philo);
	pthread_join(manager_tid, NULL);
	(void)first;
	exit(0);
}

void	start_processes(t_philo *philo)
{
	unsigned int id;
	unsigned int pid;

	id = 0;
	pid = 0;
	while(id < philo->nbr_philo)
	{
		pid = fork();
		if (pid == 0)
			return(start_philo(philo, id));
		else
		{
			philo->pids[id] = pid;
			id++;
		}
	}
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	unsigned int	nbr_done;
	unsigned int	i;

	nbr_done = 0;
	i = 0;
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
	// init_start_time(philo);
	philo->pids = malloc(sizeof(unsigned int) * philo->nbr_philo);
	sem_unlink("sem_forks");
	sem_unlink("sem_is_done");
	sem_unlink("logs");
	philo->forks = sem_open("sem_forks", O_CREAT, 0777, philo->nbr_philo);
	philo->is_done = sem_open("sem_is_done", O_CREAT, 0777, 0);
	philo->logs = sem_open("logs", O_CREAT, 0777, 1);
	init_start_time(philo);
	start_processes(philo);
	nbr_done = philo->nbr_philo;
	while(nbr_done) // ensures all philosophers lock their is_done semaphore before the main thread starts to wait for them
	{
		// printf("main process POST is_done\n");
		sem_post(philo->is_done);
		nbr_done--;
	}
	sleep(1);
	while(nbr_done < philo->nbr_philo)
	{
		// printf("main process WAIT is_done\n");
		sem_wait(philo->is_done);
		nbr_done++;
	}
	while (i < philo->nbr_philo)
	{
		kill(philo->pids[i], SIGINT);
		i++;
	}
	free(philo->pids);
	free(philo);
	return (0);
}
