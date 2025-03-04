# include "philo.h"

void	debug_print_args(t_state *state)
{
	printf("args:\nis_over = %u\nnbr_philo = %u\ntt_die = %u\ntt_eat = %u\ntt_sleep = %u\nnbr_eat = %d\n",
		state->is_over, state->nbr_philo, state->tt_die, state->tt_eat, state->tt_sleep, state->nbr_eat);
	printf("start_time: %lds, %ldμs\n", state->start_time_s, state->start_time_us);
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
