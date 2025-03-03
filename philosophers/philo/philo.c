# include "philo.h"

// void	start_philo(t_state *state)
// {

// }


void	init_philo(t_state *state)
{
	t_philo	*current;
	t_philo	*next;

	current = malloc(sizeof(t_philo));
	current->id = 1;
	current->fork = 1;
	current->nbr_of_meal = 0;
	current->state = state;
	current->left = NULL;
	state->first = current;
	while(current->id < state->nbr_philo)
	{
		next = malloc(sizeof(t_philo));
		next->id = current->id + 1;
		next->fork = 1;
		next->nbr_of_meal = 0;
		next->state = state;
		next->left = NULL;
		current->left = next;

		current = next;
	}
	current->left = state->first;
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

void	debug_print_args(t_state *state)
{
	printf("args:\nis_over = %u\nnbr_philo = %u\ntt_die = %u\ntt_eat = %u\ntt_sleep = %u\nnbr_eat = %d\n",
		state->is_over, state->nbr_philo, state->tt_die, state->tt_eat, state->tt_sleep, state->nbr_eat);
}

void	debug_print_all_philo(t_state *state)
{
	t_philo			*tail;
	unsigned int	previd;

	tail = state->first;
	previd = 0;
	while(tail && tail->id > previd)
	{
		printf("philo nbr: %d\n", tail->id);
		previd = tail->id;
		tail = tail->left;

	}
}

static int	check_args(int ac, char **av)
{
	if ((atoi(av[1]) < 0) || (atoi(av[2]) < 0) || (atoi(av[3]) < 0) || (atoi(av[4]) < 0))
		return(1);
	if (ac == 6 && atoi(av[5]) < 0)
		return(1);
	return(0);
}

static void	init_args(int ac, char **av, t_state *state)
{
	state->is_over = 0;
	state->nbr_philo = (unsigned int)atoi(av[1]);
	state->tt_die = (unsigned int)atoi(av[2]);
	state->tt_eat = (unsigned int)atoi(av[3]);
	state->tt_sleep = (unsigned int)atoi(av[4]);
	if (ac == 6)
		state->nbr_eat = (unsigned int)atoi(av[5]);
	else
		state->nbr_eat = -1;
	state->first = NULL;
}

int	main(int ac, char **av)
{
	t_state	*state;

	if (ac < 5 || ac > 6)
		return(printf("\nusage: number_of_philosophers time_to_die time_to_eat time_to_sleep%s",
			" [number_of_times_each_philosopher_must_eat]\n"), 1);
	if (check_args(ac, av))
		return(printf("arguments must be positive integers\n"), 1);

	state = malloc(sizeof(t_state));
	init_args(ac, av, state);
	if (state->nbr_philo == 0)
		return 0;
	debug_print_args(state);

	init_philo(state);
	debug_print_all_philo(state);

	free_philo(state);
	free(state);

	return(0);
}
