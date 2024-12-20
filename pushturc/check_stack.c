#include "header.h"

int	check_st_double(int size, int **st)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if ((*st)[i] == (*st)[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return(1);
}

static int check_for_string(char **av)
{
	int i;
	int has_digit;

	i = 0;
	has_digit = 0;
	while(av[1][i])
		{
			if (!ft_isdigit(av[1][i]) && (av[1][i] != ' ' && av[1][i] != '-'))
				return (0);
			else if (ft_isdigit(av[1][i]))
				has_digit = 1;
			i++;
		}
		if (!has_digit)
			return (0);
		else
			return (1);
}

static int check_for_array(char **av)
{
	int i;
	int j;
	int has_digit;

	i = 0;
	j = 1;
	has_digit = 0;
	while(av[j])
	{
		while(av[j][i])
		{
			if (!ft_isdigit(av[j][i]) && (av[j][i] != ' ' && av[j][i] != '-'))
				return (0);
			else if (ft_isdigit(av[j][i]))
				has_digit = 1;
			i++;
		}
		if (!has_digit)
			return(0);
		i = 0;
		has_digit = 0;
		j++;
	}
	return (1);
}

int check_args_numeric(int ac, char **av)
{
	if (ac == 2)
		return (check_for_string(av));
	else
		return(check_for_array(av));
}
