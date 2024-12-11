#include "header.h"

static int get_abs(int nbr)
{
	if (nbr <= -2147483648)
		return(ft_putstr_fd("Error\n", 2), ft_printf("get_abs encountered INT_MIN, returning 0"), 0);
	if (nbr < 0)
		return (-nbr);
	return(nbr);
}

int	get_diff_a(int size, int **st_optid)
{
	int i;
	unsigned long diff;

	i = 0;
	diff = 0;
	while(i < size)
	{
		diff += get_abs(i - (*st_optid)[i]);
		i++;
	}
	return(diff);
}

int	get_diff_b(int size, int **st_optid)
{
	int i;
	unsigned long diff;

	i = 0;
	diff = 0;
	while(i < size)
	{
		diff += get_abs((size - i - 1) - (*st_optid)[i]);
		i++;
	}
	return(diff);
}

int get_tot_diff(int size_a, int size_b, int **st_a_optid, int **st_b_optid)
{
	unsigned long diff_a;
	unsigned long diff_b;

	diff_a = get_diff_a(size_a, st_a_optid);
	diff_b = get_diff_b(size_b, st_b_optid);

	return(diff_a + diff_b);
}