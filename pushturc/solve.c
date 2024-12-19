#include "header.h"

void	push_to_b(t_data *d)
{
	int cheapest;
	if ((d->size_a) == 0)
		return ;
	if ((d->size_b) == 0)
	{
		printop(PB, d);
		printop(PB, d);
		push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
		push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
		if (d->st_b[1] > d->st_b[0])
		{
		printop(SB, d);
		swap(&d->st_b, d->size_b);
		}
	}
	cheapest = find_cheapest(&d->st_a, d->size_a, &d->st_b, d->size_b);
	push_cheapest_to_b(cheapest, d);
	push_to_b(d);
}

void	push_to_a(t_data *d)
{
	while((d->size_b) > 0)
	{
		printop(PA, d);
		push(&d->st_b, &d->size_b, &d->st_a, &d->size_a);
	}
}
/*
void	solve_for_3(int	**st_a, int *size_a)
{
	if ((*size_a) == 0)
		return ;
	if ((*size_a) == 2)
	{
		if ((*st_a)[0] > (*st_a)[1])
			return(printop(SA), swap(st_a, *size_a));
		else
			return ;
	}
	if ((*st_a)[0] < (*st_a)[1] && (*st_a)[1] < (*st_a)[2])
		return ;
	else if ((*st_a)[0] < (*st_a)[1] && (*st_a)[0] < (*st_a)[2])
		return(printop(RRA), rev_rotate(st_a, *size_a), printop(SA), swap(st_a, *size_a));
	else if ((*st_a)[0] > (*st_a)[1] && (*st_a)[0] > (*st_a)[2])
	{
		if ((*st_a)[1] < (*st_a)[2])
			return (printop(RA), rotate(st_a, *size_a));
		else
			return (printop(RA), rotate(st_a, *size_a), printop(SA), swap(st_a, *size_a));
	}
	if ((*st_a)[1] > (*st_a)[2])
		return (printop(RRA), rev_rotate(st_a, *size_a));
	else
		return(printop(SA), swap(st_a, *size_a));
}
*/

int	get_min(int **st, int size)
{
	int i;
	int min;

	i = 1;
	min = 0;
	while(i < size)
	{
		if ((*st)[i] < (*st)[min])
			min = i;
		i++;
	}
	return(min);
}

int	get_max(int **st, int size)
{
	int i;
	int max;

	i = 1;
	max = 0;
	while(i < size)
	{
		if ((*st)[i] > (*st)[max])
			max = i;
		i++;
	}
	return(max);
}

int	find_cheapest(int **st_a, int size_a, int **st_b, int size_b)
{
	int i;
	int cheapest;
	int cheapest_cost;

	i = 0;
	cheapest = 0;
	cheapest_cost = INT_MAX;
	while(i < size_a)
	{
		if (cheapest_cost > (cost_to_top(st_a, size_a, i) + cost_to_top(st_b, size_b, find_spot_b((*st_a)[i], st_b, size_b))))
		{
			cheapest = i;
			cheapest_cost = (cost_to_top(st_a, size_a, i) + cost_to_top(st_b, size_b, find_spot_b((*st_a)[i], st_b, size_b)));
		}
		i++;
	}
	return(cheapest);
}

int	cost_to_top(int **st, int size, int id)
{
	int op;

	op = op_to_top(st, size, id);
	if (op < 0)
		return(-op);
	else
		return(op);
}

int	op_to_top(int **st, int size, int id)
{
	(void)st;
	if (id < size - id)
		return(id);
	else
		return(-(size - id));
}

int	put_to_top_a(int **st, int size, int id, t_data *d)
{
	int op;
	int res;
	
	op = op_to_top(st, size, id);
	res = op;
	while(op > 0)
	{
		printop(RA, d);
		rotate(st, size);
		op--;
	}
	while(op < 0)
	{
		printop(RA, d);
		rotate(st, size);
		op++;
	}
	return(res);

}

int	put_to_top_b(int **st, int size, int id, t_data *d)
{
	int op;
	int res;
	
	if (id == size)
		return(-1);
	op = op_to_top(st, size, id);
	res = op;
	while(op > 0)
	{
		printop(RB, d);
		rotate(st, size);
		op--;
	}
	while(op < 0)
	{
		printop(RRB, d);
		rev_rotate(st, size);
		op++;
	}
	if (res < 0)
		return(res - 1);
	return(res);
}

int	is_lower(int val, int **st, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if ((*st)[i] < val)
			return(0);
		i++;
	}
	return(1);
}

int	is_bigger(int val, int **st, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if ((*st)[i] > val)
			return(0);
		i++;
	}
	return(1);
}

int find_spot_b(int val, int **st_b, int size)
{
	int i;

	i = 0;
	if (is_lower(val, st_b, size))
		return(size/*get_min(st_b, size)*/);
	else if (is_bigger(val, st_b, size))
		return(0);
	while((i < size - 1))
	{
		if (((*st_b)[i] > val && (*st_b)[i + 1] < val))
			return(i + 1);
		i++;
	}
	return (i);
}

void	push_cheapest_to_b(int cheapest, t_data *d)
{
	int op_to_top_b;

	put_to_top_a(&d->st_a, d->size_a, cheapest, d);
	op_to_top_b = put_to_top_b(&d->st_b, d->size_b, find_spot_b((d->st_a)[0], &d->st_b, d->size_b), d);
	printop(PB, d);
	push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
	while(op_to_top_b != 0)
	{
		if (op_to_top_b > 0)
		{
			printop(RRB, d);
			rev_rotate(&d->st_b, d->size_b);
			op_to_top_b--;
		}
		else if (op_to_top_b < 0)
		{
			printop(RB, d);
			rotate(&d->st_b, d->size_b);
			op_to_top_b++;
		}
	}
}
