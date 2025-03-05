#include "philo.h"

void	init_args(int ac, char **av, t_state *state)
{
	pthread_mutex_init(&state->is_over_mutex, NULL);
	pthread_mutex_init(&state->log, NULL);
	state->is_over = 0;
	state->nbr_philo = (unsigned int)atoi(av[1]);
	state->tt_die = (unsigned int)atoi(av[2]);
	state->tt_eat = (unsigned int)atoi(av[3]) * 1000;
	state->tt_sleep = (unsigned int)atoi(av[4]) * 1000;
	if (ac == 6)
		state->nbr_eat = (unsigned int)atoi(av[5]);
	else
		state->nbr_eat = -1;
	state->first = NULL;
}

int	check_args(int ac, char **av)
{
	if ((atoi(av[1]) < 0) || (atoi(av[2]) < 0) || (atoi(av[3]) < 0) || (atoi(av[4]) < 0))
		return(1);
	if (ac == 6 && atoi(av[5]) < 0)
		return(1);
	return(0);
}

void	init_start_time(t_state *state)
{
	struct	timeval tv;

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	gettimeofday(&tv, NULL);
	state->start_time_s = tv.tv_sec;
	state->start_time_us = tv.tv_usec;
}

void	init_philo(t_state *state)
{
	t_philo	*current;
	t_philo	*next;

	current = malloc(sizeof(t_philo));
	current->id = 1;
	pthread_mutex_init(&current->fork, NULL);
	pthread_mutex_init(&current->nbr_of_meal_mutex, NULL);
	pthread_mutex_init(&current->last_meal_mutex, NULL);
	current->nbr_of_meal = 0;
	current->last_meal = 0;
	current->thread_id = 0;
	current->state = state;
	current->left = NULL;
	state->first = current;
	while(current->id < state->nbr_philo)
	{
		next = malloc(sizeof(t_philo));
		next->id = current->id + 1;
		pthread_mutex_init(&next->fork, NULL);
		pthread_mutex_init(&current->nbr_of_meal_mutex, NULL);
		pthread_mutex_init(&current->last_meal_mutex, NULL);
		next->nbr_of_meal = 0;
		next->last_meal = 0;
		next->thread_id = 0;
		next->state = state;
		next->left = NULL;
		current->left = next;

		current = next;
	}
	current->left = state->first;
}
