/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:17:06 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/17 17:06:29 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	*ppid;
	unsigned int	*pids;
	sem_t			*forks;
	sem_t			*logs;
	sem_t			*nbr_of_meal_sem;
	sem_t			*is_done;
	unsigned int	nbr_of_meal;
	sem_t			*last_meal_mutex;
	unsigned int	last_meal;
	struct s_state	*state;
	struct s_philo	*left;
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
	take_left_log,
	take_right_log,
	eat_log,
	sleep_log,
	think_log,
	die_log
}	t_log_action;

# define USAGE "usage: nbr_of_philo \
time_to_die time_to_eat time_to_sleep \
[nbr_of_times_each_philosopher_must_eat]"

// INIT
void			init_args(int ac, char **av, t_philo *philo);
int				check_args(int ac, char **av);
void			init_start_time(t_philo *philo);

// LOGIC
int				eat(t_philo *philo);
int				philo_logic(t_philo *philo);

// UTILS
void			mysleep(unsigned int ms);
unsigned long	spent_time_ms(t_philo *philo);
// void			set_mutex_isover(t_state *state, unsigned int isover);
// unsigned int	is_over(t_state *state);
// unsigned int	get_mutex_last_meal(t_philo *philo);
// void			set_mutex_last_meal(t_philo *philo, unsigned int last_meal);
// unsigned int	get_mutex_nbr_meal(t_philo *philo);
// void			set_mutex_nbr_meal(t_philo *philo, unsigned int nbr_meal);
// void			log_action_mutex(t_philo *philo, t_log_action log);
int				ft_atou(const char *str);

#endif
