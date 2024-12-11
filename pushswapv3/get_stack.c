#include "header.h"

int	get_stack_av(int ac, char **av, int **st)
{
	int i;

	if (*st)
		return (0);
	i = 0;
	if (ac <= 1)
		return(0);
	*st = malloc(sizeof(int) * ac - 1);
	if (!st)
		return(0);
	while(i < ac - 1)
	{
		(*st)[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return(ac - 1);
}

static int get_stack_split_atoi(char **tab, int **st)
{
	int i;

	i = 0;
	while(tab[i])
		i++;
	*st = malloc(sizeof(int) * i);
	i = 0;
	while(tab[i])
	{
		(*st)[i] = ft_atoi(tab[i]);
		i++;
	}
	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (i);

}

int get_stack_split(char *s, int **st)
{
	return(get_stack_split_atoi(ft_split(s, ' '), st));
}

int get_stack(int ac, char **av, int **st)
{
	if (ac < 2)
		return (0);
	else if (ac == 2)
		return (get_stack_split(av[1], st));
	else
		return (get_stack_av(ac, av, st));

}