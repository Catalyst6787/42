#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
#include <unistd.h>

typedef	struct s_philo
{
	unsigned int	id;
	unsigned int	fork;
	t_state			*state;
	t_philo			*left;
}	t_philo;

typedef	struct s_state
{
	unsigned int	is_over;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	
	t_philo			*first;
}	t_state;


#endif