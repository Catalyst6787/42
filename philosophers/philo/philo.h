#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef	struct s_philo
{
	unsigned int	id;
	pthread_mutex_t	fork;
	unsigned int	nbr_of_meal;
	unsigned int	last_meal;
	pthread_t		thread_id;
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
	time_t			start_time_s;
	suseconds_t		start_time_us;
	struct s_philo	*first;
}	t_state;

// DEBUG
void	debug_print_args(t_state *state);
void	debug_print_all_philo(t_state *state);

// INIT
void	init_args(int ac, char **av, t_state *state);
int		check_args(int ac, char **av);
void	init_start_time(t_state *state);
void	init_philo(t_state *state);

// LOGIC
int	eat(t_philo *philo);
int	philo_logic(t_philo *philo);

// QUIT
void	wait_philo(t_state *state);
void	free_philo(t_state *state);

// START
void	*start_routine(t_philo *philo);
void	start_philo(t_state *state);
void	*manager(t_state *state);

// UTILS
unsigned long	spent_time_ms(t_state *state);



#endif
