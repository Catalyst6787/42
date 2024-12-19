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

void	printop(int op, t_data *d)
{
	(void)d;
	if (op == SA)
		ft_printf("sa\n");
	if (op == SB)
		ft_printf("sb\n");
	if (op == SS)
		ft_printf("ss\n");
	if (op == PA)
		ft_printf("pa\n");
	if (op == PB)
		ft_printf("pb\n");
	if (op == RA)
		ft_printf("ra\n");
	if (op == RB)
		ft_printf("rb\n");
	if (op == RR)
		ft_printf("rr\n");
	if (op == RRA)
		ft_printf("rra\n");
	if (op == RRB)
		ft_printf("rrb\n");
	if (op == RRR)
		ft_printf("rrr\n");
}
