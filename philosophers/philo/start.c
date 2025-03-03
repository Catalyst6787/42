#include "philo.h"

void	*start_routine(t_philo *philo)
{
	printf("philo nbr: %u, thread id: %lu.\n", philo->id, philo->thread_id);
	return(NULL);
}

void	start_philo(t_state *state)
{
	t_philo	*current;

	current = state->first;
	while(current)
	{
		printf("starting philo nbr: %u\n", current->id);

		pthread_create(&(current->thread_id), NULL, (void *)start_routine, current);
		usleep(10);
		if (current->id < current->left->id)
			current = current->left;
		else
			current = NULL;
	}
}
