#include "philo.h"

static int	take_left_fork(t_philo *philo)
{
	if (is_over(philo->state))
		return(1);
	pthread_mutex_lock(&philo->left->fork);
	if (is_over(philo->state))
		return(pthread_mutex_unlock(&philo->left->fork), 1);
	printf("%lums %u has taken left fork\n", spent_time_ms(philo->state), philo->id);
	return(0);
}

static int	take_right_fork(t_philo *philo)
{
	if (is_over(philo->state))
		return(1);
	pthread_mutex_lock(&philo->fork);
	if (is_over(philo->state))
		return(pthread_mutex_unlock(&philo->fork), 1);
	printf("%lums %u has taken right fork\n", spent_time_ms(philo->state), philo->id);
	return(0);
}

int	eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		usleep(1000);
		if (take_left_fork(philo))
			return(1);
		if (philo->left == philo)
			return(pthread_mutex_unlock(&philo->left->fork), 1);
		if (take_right_fork(philo))
			return(pthread_mutex_unlock(&philo->left->fork), 1);
	}
	else
	{
		if (take_right_fork(philo))
			return(1);
		if (take_left_fork(philo))
			return(pthread_mutex_unlock(&philo->fork), 1);
	}
	if (is_over(philo->state))
		return(1);
	printf("%lums %u is eating\n", spent_time_ms(philo->state), philo->id);
	set_mutex_nbr_meal(philo, get_mutex_nbr_meal(philo) + 1);
	set_mutex_last_meal(philo, spent_time_ms(philo->state));
	usleep(philo->state->tt_eat);
	pthread_mutex_unlock(&philo->left->fork);
	pthread_mutex_unlock(&philo->fork);
	return (0);
}

int	philo_logic(t_philo *philo)
{
	if (!(philo->state->nbr_eat < 0) && (unsigned int)philo->state->nbr_eat == get_mutex_nbr_meal(philo))
		return(0);
	while(!(is_over(philo->state)))
	{
		if (eat(philo))
			return(0);
		if (!(is_over(philo->state)))
		{
			printf("%lums %u is sleeping\n", spent_time_ms(philo->state), philo->id);
			usleep(philo->state->tt_sleep);
		}
		if (!(is_over(philo->state)))
			printf("%lums %u is thinking\n", spent_time_ms(philo->state), philo->id);
	}
	return(0);
}

static int	all_ate_enough(t_philo *first)
{
	t_philo *current;

	current = first;
	if ((int)get_mutex_nbr_meal(current) >= first->state->nbr_eat)
	{
		current = current->left;
		while(current != first)
		{
			if ((int)get_mutex_nbr_meal(current) < current->state->nbr_eat)
				return(0);
			current = current->left;
		}
		return(1);
	}
	return(0);
}

void	*manager(t_state *state)
{
	t_philo	*current;

	current = state->first;
	while(current && !state->is_over)
	{
		if ((unsigned long)state->tt_die <= (spent_time_ms(state) - (unsigned long)get_mutex_last_meal(current)) && (state->nbr_eat == -1 || get_mutex_nbr_meal(current) < (unsigned int)state->nbr_eat))
			return (set_mutex_isover(state, 1), printf("\033[1;31m%lums %u died. last meal was %u\n\033[0m", spent_time_ms(state), current->id, current->last_meal), NULL);
		current = current->left;
		if (current == state->first)
		{
			if (state->nbr_eat != -1 && all_ate_enough(state->first))
				return (set_mutex_isover(state, 1), NULL);
			//usleep(1000);
		}
	}
	return (NULL);
}

