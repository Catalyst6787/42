#include "philo.h"

int	eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->left->fork);
		printf("timestamp_in_ms %u has taken left fork\n", philo->id);
		pthread_mutex_lock(&philo->fork);
		printf("timestamp_in_ms %u has taken right fork\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		printf("timestamp_in_ms %u has taken right fork\n", philo->id);
		pthread_mutex_lock(&philo->left->fork);
		printf("timestamp_in_ms %u has taken left fork\n", philo->id);
	}
	printf("timestamp_in_ms %u is eating\n", philo->id);
	usleep(philo->state->tt_eat);
	pthread_mutex_unlock(&philo->left->fork);
	pthread_mutex_unlock(&philo->fork);
	return (0);
}

int	philo_logic(t_philo *philo)
{
	if (!(philo->state->nbr_eat < 0) && (unsigned int)philo->state->nbr_eat == philo->nbr_of_meal)
		return(0);
	while(!(philo->state->is_over))
	{
		eat(philo);
		printf("timestamp_in_ms %u is sleeping\n", philo->id);
		usleep(philo->state->tt_sleep);
		printf("timestamp_in_ms %u is thinking\n", philo->id);
	}
	return(0);
}

void	*start_routine(t_philo *philo)
{
	philo_logic(philo);
	pthread_mutex_destroy(&philo->fork);
	return(NULL);
}

void	start_philo(t_state *state)
{
	t_philo	*current;

	current = state->first;
	while(current)
	{
		// printf("starting philo nbr: %u\n", current->id);
		pthread_create(&(current->thread_id), NULL, (void *)start_routine, current);
		if (current->id < current->left->id)
			current = current->left;
		else
			current = NULL;
	}
}
