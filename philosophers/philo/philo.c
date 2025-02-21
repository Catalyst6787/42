# include "philo.h"

void	*print_odd_to_goal(void *ptr)
{
	printf("entered print odd\n\n");
	t_philo	*node = ptr;
	int goal = node->nbr;
	int c = 0;
	while(c < goal)
	{
		usleep(25);
		if (c % 2)
			printf("%d\n", c);
		c++;
	}
	printf("\n");
	free(ptr);
	pthread_exit(0);
	return((void *)42);
}

void	*print_even_to_goal(void *ptr)
{
	printf("entered print even\n\n");
	t_philo	*node = ptr;
	int goal = node->nbr;
	int c = 0;
	while(c < goal)
	{
		usleep(25);
		if (!(c % 2))
			printf("%d\n", c);
		c++;
	}
	printf("\n");
	free(ptr);
	pthread_exit(0);
	return((void *)42);
}

int	main(void)
{
	pthread_t	id_odd;
	pthread_t	id_even;

	t_philo *node_odd = malloc(sizeof(t_philo));
	node_odd->nbr = 50;
	t_philo *node_even = malloc(sizeof(t_philo));
	node_even->nbr = 50;

	pthread_create(&id_even, NULL, *print_even_to_goal, node_even);
	usleep(25);
	pthread_create(&id_odd, NULL, *print_odd_to_goal, node_odd);
	
	pthread_join(id_even, NULL);
	pthread_join(id_odd, NULL);

	return(0);
}
