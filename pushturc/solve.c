#include "header.h"

void	push_to_b(int **st_a, int *size_a, int **st_b, int *size_b)
{
	//int max;
	//int min;
	int cheapest;
	if ((*size_a) <= 3)
		return(solve_for_3(st_a, size_a));
	if ((*size_b) == 0)
	{
		printop(PB);
		printop(PB);
		push(st_a, size_a, st_b, size_b);
		push(st_a, size_a, st_b, size_b);
		if ((*st_b)[1] > (*st_b)[0])
		{
		printop(SB);
		swap(st_b, *size_b);
		}
	}
	//max = get_max(st_b, *size_b);
	//min = get_min(st_b, *size_b);
	cheapest = find_cheapest(st_a, *size_a, st_b, *size_b);
	push_cheapest_to_b(cheapest, st_a, size_a, st_b, size_b);
	push_to_b(st_a, size_a, st_b, size_b);
}

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
	(void)st;
	if (id <= (size - id))
		return(id);
	else
		return(size - id);
}

int	op_to_top(int **st, int size, int id)
{
	(void)st;
	if (id < size - id)
		return(id);
	else
		return(-(size - id));
}
/*
int	find_spot_b(int val, int **st_b, int size)
{
	int i;

	i = 0;
	while(i < size && (*st_b)[i] > val)
		i++;
	return(i);
}


int	find_spot_a(int val, int **st_b, int size)
{
	int i;
	while(i < size && (*st_b)[i] < val)
		i++;
	return(i);
}
*/

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
		return(get_min(st_b, size) + 1);
	else if (is_bigger(val, st_b, size))
		return(get_max(st_b, size) - 1);
	while((i < size - 1) && !((*st_b)[i] > val && (*st_b)[i + 1] < val))
		i++;
	return (i);
}

void	push_cheapest_to_b(int cheapest, int **st_a, int *size_a, int **st_b, int *size_b)
{
	int op_to_top_a;
	int op_to_top_b;

	op_to_top_a = op_to_top(st_a, *size_a, cheapest);
	op_to_top_b = op_to_top(st_b, *size_b, find_spot_b((*st_a)[cheapest], st_b, *size_b));

	// if (op_to_top_a == 0 && op_to_top_b == 0)
	//	return ;
	if (op_to_top_a > 0 && op_to_top_b > 0)
	{
		while(op_to_top_a && op_to_top_b)
		{
			printop(RR);
			rotate(st_a, *size_a);
			rotate(st_b, *size_b);
			op_to_top_a--;
			op_to_top_b--;
		}
	}
	else if (op_to_top_a < 0 && op_to_top_b < 0)
	{
		while(op_to_top_a < 0 && op_to_top_b < 0)
		{
			printop(RRR);
			rev_rotate(st_a, *size_a);
			rev_rotate(st_b, *size_b);
			op_to_top_a++;
			op_to_top_b++;
		}
	}
	while(op_to_top_a != 0)
	{
		if (op_to_top_a > 0)
		{
			printop(RA);
			rotate(st_a, *size_a);
			op_to_top_a--;
		}
		else if (op_to_top_a < 0)
		{
			printop(RRA);
			rev_rotate(st_a, *size_a);
			op_to_top_a++;
		}
	}
	while(op_to_top_b != 0)
	{
		if (op_to_top_b > 0)
		{
			printop(RB);
			rotate(st_b, *size_b);
			op_to_top_b--;
		}
		else if (op_to_top_b < 0)
		{
			printop(RRB);
			rev_rotate(st_b, *size_b);
			op_to_top_b++;
		}
	}
	printop(PB);
	push(st_a, size_a, st_b, size_b);
}
