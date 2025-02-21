# include "philo.h"

void	start_philo(t_state *state)
{
	
}

static void	loop_init(t_philo *first, unsigned int nbr_of_processes, t_state *state)
{
	t_philo			*next;
	t_philo			*prev;
	unsigned int	nbr_philo;

	nbr_philo = 2;
	next = NULL;
	prev = first;
	while (nbr_philo < nbr_of_processes)
	{
		next = malloc(sizeof(t_philo));
		next->id = nbr_philo;
		next->fork = 1;
		nbr_philo++;
		prev->left = next;
		next->left = NULL;
		next->state = state;
		nbr_philo++;
	}
	if (next)
		next->left = first;
}

void	init_philo(unsigned int nbr_of_processes, t_state *state)
{
	if (!nbr_of_processes)
		return ;
	t_philo			*first;

	first = malloc(sizeof(t_philo));
	first->id = 1;
	first->fork = 1;
	first->left = NULL;
	first->state = state;
	state->first = first;
	loop_init(first, nbr_of_processes, state);
}

int	main(void)
{
	t_state	*state;

	state = malloc(sizeof(t_state));
	state->is_over = 0;
	state->first = NULL;
	init_philo(20, state);
	return(0);
}
