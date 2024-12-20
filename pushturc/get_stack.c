#include "header.h"

int	get_stack_av(int ac, char **av, int **st, int *err)
{
	int i;

	if (*st)
		return (0);
	i = 0;
	if (ac <= 1)
		return(0);
	*st = malloc(sizeof(int) * (ac - 1));
	if (!(*st))
		return(0);
	while(i < ac - 1)
	{
		(*st)[i] = ft_long_atoi(av[i + 1], err);
		i++;
	}
	return(ac - 1);
}

int get_stack_split_atoi(char **tab, int **st, int *err)
{
	int i;

	i = 0;
	if (*st)
		return (0);
	while(tab[i])
		i++;
	*st = malloc(sizeof(int) * i);
	i = 0;
	while(tab[i])
	{
		(*st)[i] = ft_long_atoi(tab[i], err);
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

int get_stack_split(char *s, int **st, int *err)
{
	return(get_stack_split_atoi(ft_split(s, ' '), st, err));
}

int get_stack(int ac, char **av, int **st, int *err)
{
	if (ac < 2)
		return (0);
	else if (ac == 2)
		return (get_stack_split(av[1], st, err));
	else
		return (get_stack_av(ac, av, st, err));

}

int	ft_long_atoi(const char *str, int *error)
{
	long	r;
	int	i;
	int	n;

	i = 0;
	r = 0;
	n = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && str[i] == '+')
		i++;
	else if (str[i] && str[i] == '-')
	{
		n = -n;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	r *= n;

	if (r > INT_MAX || r < INT_MIN)
		return(*error = 1, 0);
	return ((int)r);
}