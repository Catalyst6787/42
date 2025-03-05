#include "philo.h"

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
