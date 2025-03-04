#include "philo.h"

int	eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		usleep(1000);
		pthread_mutex_lock(&philo->left->fork);
		printf("%lums %u has taken left fork\n", spent_time_ms(philo->state), philo->id);
		if (philo->left == philo)
			return(usleep(philo->state->tt_die), 1);
		pthread_mutex_lock(&philo->fork);
		printf("%lums %u has taken right fork\n", spent_time_ms(philo->state), philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		printf("%lums %u has taken right fork\n", spent_time_ms(philo->state), philo->id);
		pthread_mutex_lock(&philo->left->fork);
		printf("%lums %u has taken left fork\n", spent_time_ms(philo->state), philo->id);
	}
	printf("%lums %u is eating\n", spent_time_ms(philo->state), philo->id);
	philo->nbr_of_meal++;
	philo->last_meal = spent_time_ms(philo->state);
	if (philo->state->nbr_eat != -1 && philo->nbr_of_meal == (unsigned int)philo->state->nbr_eat)
		philo->state->is_over = 1;
	usleep(philo->state->tt_eat);
	pthread_mutex_unlock(&philo->left->fork);
	pthread_mutex_unlock(&philo->fork);
	return (0);
}

int	philo_logic(t_philo *philo)
{
	if (!(philo->state->nbr_eat < 0) && (unsigned int)philo->state->nbr_eat == philo->nbr_of_meal)
		return(0);
	while(!(philo->state->is_over) && (philo->state->nbr_eat == -1 || (philo->nbr_of_meal != (unsigned int)philo->state->nbr_eat)))
	{
		if (eat(philo))
			return(0);
		if (!(philo->state->is_over) && (philo->state->nbr_eat == -1 || (philo->nbr_of_meal != (unsigned int)philo->state->nbr_eat)))
		{
			printf("%lums %u is sleeping\n", spent_time_ms(philo->state), philo->id);
			usleep(philo->state->tt_sleep);
		}
		if (!(philo->state->is_over) && (philo->state->nbr_eat == -1 || (philo->nbr_of_meal != (unsigned int)philo->state->nbr_eat)))
			printf("%lums %u is thinking\n", spent_time_ms(philo->state), philo->id);
	}
	// printf("%u ate %u times, leaving\n", philo->id, philo->nbr_of_meal);
	return(0);
}

void	*manager(t_state *state)
{
	t_philo	*current;

	current = state->first;
	while(current && !state->is_over)
	{
		//printf("manager examining philo %u. last meal: %u, current ts: %lu, time since last meal: %u, ate %u time(s)\n", current->id, current->last_meal, spent_time_ms(state), ((unsigned int)spent_time_ms(state) - current->last_meal), current->nbr_of_meal);
		if ((unsigned long)state->tt_die <= (spent_time_ms(state) - (unsigned long)current->last_meal) && (state->nbr_eat == -1 || current->nbr_of_meal < (unsigned int)state->nbr_eat))
		{
			state->is_over = 1;
			printf("%lums %u died. last meal was %u\n", spent_time_ms(state), current->id, current->last_meal);
		}
		current = current->left;
		usleep(1);
	}
	return (NULL);
}
