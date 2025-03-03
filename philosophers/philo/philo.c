# include "philo.h"

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

	start_philo(state);
	wait_philo(state);

	free_philo(state);
	free(state);
	return(0);
}
