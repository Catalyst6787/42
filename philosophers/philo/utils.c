#include "philo.h"

unsigned long	spent_time_ms(t_state *state)
{
	struct	timeval current_tv;
	unsigned long	spent_time;

	current_tv.tv_sec = 0;
	current_tv.tv_usec = 0;
	gettimeofday(&current_tv, NULL);
	spent_time = 0;
	spent_time += ((current_tv.tv_sec - state->start_time_s) * 1000);
	spent_time += ((current_tv.tv_usec - state->start_time_us) / 1000);
	return (spent_time);
}
