#include "header.h"

void	print_st(int size, int **st)
{
	int i;

	i = 0;
	if (!st || !(*st))
		return(ft_printf("NULL stack\n"), (void)NULL);
	while(i < size)
	{
		ft_printf("element n: %d, value: %d\n", i, (*st)[i]);
		i++;
	}
}

void	free_st(int **st)
{
	if (!st || !(*st))
		return ;
	free(*st);
	(*st) = NULL;
	st = NULL;
}

void	copy_st(int size, int **st, int **st_copy)
{
	if (!st || !(*st))
		return ;
	if (!st_copy)
		return ;
	int i;

	i = 0;
	while(i < size)
	{
		(*st_copy)[i] = (*st)[i];
		i++;
	}
}

void	copy_st_malloc(int size, int **st, int **st_copy)
{
	if (!st || !(*st))
		return ;
	if (!st || !(*st))
		return((void)ft_printf("tried copy_st_malloc on NULL st_copy"));
	*st_copy = malloc(sizeof(int) * size);
	if (!(*st_copy))
		return (*st_copy = NULL, (void)ft_printf("malloc error in copy_st_malloc"));
	copy_st(size, st, st_copy);
}

void	set_subbranches_to_NULL(t_tree **br)
{
	(*br)->sa = NULL;
	(*br)->sb = NULL;
	(*br)->ss = NULL;
	(*br)->pa = NULL;
	(*br)->pb = NULL;
	(*br)->ra = NULL;
	(*br)->rb = NULL;
	(*br)->rr = NULL;
	(*br)->rra = NULL;
	(*br)->rrb = NULL;
	(*br)->rrr = NULL;
}

void	print_op(int op)
{
	if (op == -1)
		ft_printf("NULL\n");
	else if (op == 0)
		ft_printf("SA\n");
	else if (op == 1)
		ft_printf("SB\n");
	else if (op == 2)
		ft_printf("SS\n");
	else if (op == 3)
		ft_printf("PA\n");
	else if (op == 4)
		ft_printf("PB\n");
	else if (op == 5)
		ft_printf("RA\n");
	else if (op == 6)
		ft_printf("RB\n");
	else if (op == 7)
		ft_printf("RR\n");
	else if (op == 8)
		ft_printf("RRA\n");
	else if (op == 9)
		ft_printf("RRB\n");
	else if (op == 10)
		ft_printf("RRR\n");
}
