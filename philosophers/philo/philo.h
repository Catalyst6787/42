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
	unsigned int	nbr_of_meal;
	struct s_state	*state;
	struct s_philo	*left;
}	t_philo;

typedef	struct s_state
{
	unsigned int	is_over;
	unsigned int	nbr_philo;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	int				nbr_eat;
	struct s_philo	*first;
}	t_state;


#endif
