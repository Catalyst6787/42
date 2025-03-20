/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:17:06 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/20 17:01:44 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

# include <sys/types.h>
# include <signal.h>

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	*pids;
	sem_t			*forks;
	sem_t			*logs;
	sem_t			*is_done;
	sem_t			*is_over_sem;
	unsigned int	is_over;
	unsigned int	nbr_of_meal;
	sem_t			*last_meal_sem;
	unsigned int	last_meal;
	unsigned int	nbr_philo;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	int				nbr_eat;
	time_t			start_time_s;
	suseconds_t		start_time_us;
}	t_philo;

typedef enum s_log_action
{
	take_1_log,
	take_2_log,
	eat_log,
	sleep_log,
	think_log,
	die_log,
	custom_log
}	t_log_action;

# define USAGE "usage: nbr_of_philo \
time_to_die time_to_eat time_to_sleep \
[nbr_of_times_each_philosopher_must_eat]"

# define DEATH "\033[1;31m%lums, %u died. \
Last meal was %u. \
Time since last meal %lu \033[0m\n"

// INIT
void			init_args(int ac, char **av, t_philo *philo);
int				check_args(int ac, char **av);
void			init_start_time(t_philo *philo);

// LOGIC
void			*manager(t_philo	*philo);
void			init_philo_data(t_philo *philo, unsigned int id);
void			start_philo(t_philo *philo, unsigned int id);

// PHILO ACTIONS
unsigned int	if_first(t_philo *philo, unsigned int first);
unsigned int	take_forks(t_philo *philo);
unsigned int	eat(t_philo *philo);
unsigned int	philo_sleep_think(t_philo *philo);
void			philo_loop(t_philo *philo, unsigned int first);

// SEM UTILS
unsigned int	get_last_meal(t_philo *philo);
void			set_last_meal(t_philo *philo, unsigned int new_last_meal);
unsigned int	get_is_over(t_philo *philo);
void			set_is_over(t_philo *philo, unsigned int is_over);

// UTILS
void			mysleep(unsigned int ms);
unsigned long	spent_time_ms(t_philo *philo);
int				ft_atou(const char *str);
void			log_action(t_philo *philo, t_log_action action, char *custom);

#endif
