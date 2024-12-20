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
	cheapest = find_cheapest(d);
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

void	solve_for_3(int	**st_a, int *size_a, t_data *d)
{
	if ((*size_a) == 0)
		return ;
	if ((*size_a) == 2)
	{
		if ((*st_a)[0] > (*st_a)[1])
			return(printop(SA, d), swap(st_a, *size_a));
		else
			return ;
	}
	if ((*st_a)[0] < (*st_a)[1] && (*st_a)[1] < (*st_a)[2])
		return ;
	else if ((*st_a)[0] < (*st_a)[1] && (*st_a)[0] < (*st_a)[2])
		return(printop(RRA, d), rev_rotate(st_a, *size_a), printop(SA, d), swap(st_a, *size_a));
	else if ((*st_a)[0] > (*st_a)[1] && (*st_a)[0] > (*st_a)[2])
	{
		if ((*st_a)[1] < (*st_a)[2])
			return (printop(RA, d), rotate(st_a, *size_a));
		else
			return (printop(RA, d), rotate(st_a, *size_a), printop(SA, d), swap(st_a, *size_a));
	}
	if ((*st_a)[1] > (*st_a)[2])
		return (printop(RRA, d), rev_rotate(st_a, *size_a));
	else
		return(printop(SA, d), swap(st_a, *size_a));
}

void	solve_for_less_than_6(t_data *d)
{
	if (d->size_a == 3)
		return(solve_for_3(&d->st_a, &d->size_a, d));
	else if (d->size_a == 2)
		return(printop(SA, d), swap(&d->st_a, d->size_a));
	else if (d->size_a >= 4)
	{
		put_to_top_a(&d->st_a, d->size_a, get_min(&d->st_a, d->size_a), d);
		printop(PB, d);
		push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
	}
	if (d->size_a == 4)
	{
		put_to_top_a(&d->st_a, d->size_a, get_min(&d->st_a, d->size_a), d);
		printop(PB, d);
		push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
	}
	solve_for_3(&d->st_a, &d->size_a, d);
	push_to_a(d);
}

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

int	find_cheapest(t_data *d)
{
	int i;
	int cheapest;
	int cheapest_cost;

	i = 0;
	cheapest = 0;
	cheapest_cost = INT_MAX;
	while(i < d->size_a)
	{
		if (cheapest_cost > get_full_cost(d, i))
		{
			cheapest = i;
			cheapest_cost = get_full_cost(d, i);
		}
		i++;
	}
	return(cheapest);
}

int get_full_cost(t_data *d, int id)
{
	int op_to_top_a;
	int op_to_top_b;
	int fullres;

	fullres = 0;
	op_to_top_a = op_to_top(&d->st_a, d->size_a, id);
	op_to_top_b = op_to_top(&d->st_b, d->size_b, find_spot_b(d->st_a[id], &d->st_b, d->size_b));
	while(op_to_top_a > 0 && op_to_top_b > 0)
	{
		op_to_top_a--;
		op_to_top_b--;
		fullres++;
	}
	while(op_to_top_a < 0 && op_to_top_b < 0)
	{
		op_to_top_a++;
		op_to_top_b++;
		fullres++;
	}
	while(op_to_top_a > 0)
	{
		op_to_top_a--;
		fullres++;
	}
	while(op_to_top_b > 0)
	{
		op_to_top_b--;
		fullres++;
	}
	while(op_to_top_a < 0)
	{
		op_to_top_a++;
		fullres++;
	}
	while(op_to_top_b < 0)
	{
		op_to_top_b++;
		fullres++;
	}
	return(fullres);
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
		printop(RRA, d);
		rev_rotate(st, size);
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
	int res;

	res = 0;
	if (is_lower(val, st_b, size))
		res = get_min(st_b, size);
	else if (is_bigger(val, st_b, size))
		res = get_max(st_b, size) - 1;
	else
		res = get_smallest_bigger(val, st_b, size);
	if (res == size)
		return(0);
	else
		return(res + 1);
}

void	push_cheapest_to_b(int cheapest, t_data *d)
{
	put_to_top_a(&d->st_a, d->size_a, cheapest, d);
	put_to_top_b(&d->st_b, d->size_b, find_spot_b((d->st_a)[0], &d->st_b, d->size_b), d);
	printop(PB, d);
	push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
}

int	get_smallest_bigger(int val, int **st, int size)
{
	int i;
	int smallest;

	i = 0;
	smallest = 0;
	while(i < size)
	{
		if (((*st)[i] < (*st)[smallest] && (*st)[i] > val)
		|| ((*st)[smallest] < val && (*st)[i] > val))
			smallest = i;
		i++;
	}
	return(smallest);
}

int	get_bigest_smaller(int val, int **st, int size)
{
	int i;
	int biggest;

	i = 0;
	biggest = 0;
	while(i < size)
	{
		if (((*st)[i] > (*st)[biggest] && (*st)[i] < val)
		|| ((*st)[biggest] > val && (*st)[i] < val))
			biggest = i;
		i++;
	}
	return(biggest);
}

void	align_stack(t_data *d)
{
	put_to_top_b(&d->st_a, d->size_a, get_max(&d->st_b, d->size_b), d);
}

