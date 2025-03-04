#include "philo.h"

void	wait_philo(t_state *state)
{
	t_philo	*current;

	current = state->first;
	while(current)
	{
		printf("waiting for philo nbr: %u\n", current->id);
		pthread_join(current->thread_id, NULL);

		if (current->left && current->id < current->left->id)
			current = current->left;
		else
			current = NULL;
	}
}

void	free_philo(t_state *state)
{
	t_philo	*tail;
	t_philo	*next;
	unsigned int	id;

	tail = state->first;
	id = 0;
	while(tail && tail->id <= state->nbr_philo)
	{
		id = tail->id;
		if(tail->id < state->nbr_philo)
			next = tail->left;
		free(tail);
		if(id < state->nbr_philo)
			tail = next;
		else
			tail = NULL;
	}
}
