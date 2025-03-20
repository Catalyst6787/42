/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:54:11 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/20 17:01:58 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*manager(t_philo	*philo)
{
	unsigned int	i;

	i = 0;
	mysleep(philo->tt_die);
	while (!philo->is_over
		&& (philo->nbr_eat == -1
			|| (philo->nbr_of_meal < (unsigned int)philo->nbr_eat)))
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
			mysleep(philo->tt_die
				- (spent_time_ms(philo) - get_last_meal(philo)));
	}
	return (NULL);
}

void	init_philo_data(t_philo *philo, unsigned int id)
{
	philo->id = id + 1;
	philo->logs = sem_open("logs", 0);
	philo->is_done = sem_open("sem_is_done", 0);
	sem_wait(philo->is_done);
	free(philo->pids);
	philo->pids = NULL;
	philo->forks = sem_open("sem_forks", 0);
	if (philo->forks == SEM_FAILED)
		return (log_action(philo, custom_log, "sem failed\n"));
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
	exit (0);
}
