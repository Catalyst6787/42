/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:11:23 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/20 16:07:46 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_last_meal(t_philo *philo)
{
	unsigned int last_meal;
	sem_wait(philo->last_meal_sem);
	last_meal = philo->last_meal;
	sem_post(philo->last_meal_sem);
	return(last_meal);
}

void	set_last_meal(t_philo *philo, unsigned int new_last_meal)
{
	sem_wait(philo->last_meal_sem);
	philo->last_meal = new_last_meal;
	sem_post(philo->last_meal_sem);
}

unsigned int	get_is_over(t_philo *philo)
{
	unsigned int is_over;
	sem_wait(philo->is_over_sem);
	is_over = philo->is_over;
	sem_post(philo->is_over_sem);
	return(is_over);
}

void	set_is_over(t_philo *philo, unsigned int is_over)
{
	sem_wait(philo->is_over_sem);
	philo->is_over = is_over;
	sem_post(philo->is_over_sem);
}


void	*manager(t_philo	*philo)
{
	unsigned int	i;

	i = 0;
	mysleep(philo->tt_die);
	while (!philo->is_over && (philo->nbr_eat == -1 || (philo->nbr_of_meal < (unsigned int)philo->nbr_eat)))
	{
		if ((spent_time_ms(philo) - get_last_meal(philo)) >= philo->tt_die)
		{
			set_is_over(philo, 1);
			log_action(philo, die_log, NULL);
			while (i < philo->nbr_philo)
			{
				sem_post(philo->is_done);
				i++;
			}
			pthread_exit(0);
		}
		else
			mysleep(philo->tt_die - (spent_time_ms(philo) - get_last_meal(philo)));
	}
	return(NULL);
}

void	init_philo_data(t_philo *philo, unsigned int id)
{

	philo->id = id + 1;
	philo->logs = sem_open("logs", 0);
	philo->is_done = sem_open("sem_is_done", 0);
	// log_action(philo, custom_log,"WAIT is_done");
	sem_wait(philo->is_done);
	free(philo->pids);
	philo->pids = NULL;
	// philo->is_over = 0;
	philo->forks = sem_open("sem_forks", 0);
	// philo->last_meal_sem = sem_open("sem_last_meal", O_CREAT, 0777, 1)
	if (philo->forks == SEM_FAILED)
		return(log_action(philo, custom_log, "sem failed\n"));
}

unsigned int	if_first(t_philo *philo, unsigned int first)
{
	if (philo->id % 2 && first)
	{
		mysleep(1);
		first = 0;
	}
	if (get_is_over(philo))
	{
		sem_post(philo->is_done);
		return(1);
	}
	return(0);
}

unsigned int	take_forks(t_philo *philo)
{
	// log_action(philo, custom_log, "tries to take 1st fork");
	sem_wait(philo->forks);
	if (philo->is_over)
	{
		sem_post(philo->forks);
		sem_post(philo->is_done);
		return(1);
	}
	log_action(philo, take_1_log, NULL);
	// log_action(philo, custom_log, "tries to take 2nd fork");
	sem_wait(philo->forks);
	if (get_is_over(philo))
	{
		sem_post(philo->forks);
		sem_post(philo->forks);
		sem_post(philo->is_done);
		return(1);
	}
	log_action(philo, take_2_log, NULL);
	return(0);
}

unsigned int	eat(t_philo *philo)
{
	philo->nbr_of_meal++;
	set_last_meal(philo, spent_time_ms(philo));
	log_action(philo, eat_log, NULL);
	if (philo->nbr_eat != -1 && philo->nbr_of_meal >= (unsigned int)philo->nbr_eat)
		sem_post(philo->is_done);
	mysleep(philo->tt_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
	// log_action(philo, custom_log, "POST 2 FORKS");
	if (get_is_over(philo))
	{
		sem_post(philo->is_done);
		return(1);
	}
	return(0);
}

unsigned int	philo_sleep_think(t_philo *philo)
{
	log_action(philo, sleep_log, NULL);
	mysleep(philo->tt_sleep);
	if (get_is_over(philo))
	{
		sem_post(philo->is_done);
		return(1);
	}
	log_action(philo, think_log, NULL);
	usleep(200);
	return(0);
}

void	philo_loop(t_philo *philo, unsigned int first)
{
	while(!philo->is_over && (philo->nbr_eat == -1 || philo->nbr_of_meal < (unsigned int)philo->nbr_eat))
	{
		if (if_first(philo, first))
			break;
		if (take_forks(philo))
			break;
		if (eat(philo))
			break;
		if (philo_sleep_think(philo))
			break;
	}
}

void	start_philo(t_philo *philo, unsigned int id)
{
	unsigned int	first;
	pthread_t		manager_tid;

	first = 1;
	init_philo_data(philo, id);
	pthread_create(&manager_tid, NULL, (void *)manager, philo);
	philo_loop(philo, first);
	sem_close(philo->is_done);
	sem_close(philo->forks);
	sem_close(philo->logs);
	pthread_join(manager_tid, NULL);
	free(philo);
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
	if (philo->nbr_philo == 0 || philo->nbr_eat == 0)
		return (free(philo), 0);
	// init_start_time(philo);
	philo->pids = malloc(sizeof(unsigned int) * philo->nbr_philo);
	sem_unlink("sem_forks");
	sem_unlink("sem_is_done");
	sem_unlink("logs");
	sem_unlink("sem_last_meal");
	sem_unlink("sem_is_over");
	philo->forks = sem_open("sem_forks", O_CREAT, 0777, philo->nbr_philo);
	philo->is_done = sem_open("sem_is_done", O_CREAT, 0777, philo->nbr_philo);
	philo->logs = sem_open("logs", O_CREAT, 0777, 1);
	philo->last_meal_sem = sem_open("sem_last_meal", O_CREAT, 0777, 1);
	philo->is_over_sem = sem_open("sem_is_over", O_CREAT, 0777, 1);
	init_start_time(philo);
	start_processes(philo);
	usleep(60);
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
