#include "header.h"

int	op_possible(t_tree *prev, int op)
{
	if (!prev)
		return(ft_printf("tried op_possible on NULL branch\n"), 0);
	if ((op == SA || op == PB || op == RA || op == RRA) && !prev->st_a)
		return(0);
	if ((op == SB || op == PA || op == RB || op == RRB) && !prev->st_b)
		return(0);
	if ((op == SS || op == RR || op == RRR) && (!prev->st_a || !prev->st_b))
		return(0);
	return(1);
}

void	swap(int **st_prev, int **st, int size)
{
	int tmp;

	if (!st_prev || !(*st_prev) || !st)
		return ((void)ft_printf("tried swap on NULL prev or NULL br\n"));
	copy_st_malloc(size, st_prev, st);
	if (size < 2)
		return ;
	tmp = (*st)[0];
	(*st)[0] = (*st)[1];
	(*st)[1] = tmp;
}

void	rotate(int **st_prev, int **st, int size)
{
	int tmp;
	int i;

	i = 0;
	if (!st_prev || !(*st_prev) || !st)
		return ((void)ft_printf("tried rotate on NULL prev or NULL br\n"));
	copy_st_malloc(size, st_prev, st);
	if (size < 2)
		return ;
	tmp = (*st)[0];
	while(i < size - 1)
	{
		(*st)[i] = (*st)[i + 1];
		i++;
	}
	(*st)[size - 1] = tmp;
}

void	rev_rotate(int **st_prev, int **st, int size)
{
	int tmp;
	int i;

	if (!st_prev || !(*st_prev) || !st)
		return ((void)ft_printf("tried rev_rotate on NULL prev or NULL br\n"));
	copy_st_malloc(size, st_prev, st);
	if (size < 2)
		return ;
	i = size - 1;
	tmp = (*st)[size - 1];
	while(i > 0)
	{
		(*st)[i] =  (*st)[i - 1];
		i--;
	}
	(*st)[i] = tmp;
}
