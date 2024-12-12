#include "header.h"

void	do_op(t_tree *prev, t_tree **br, int op)
{
	if (!prev || !br)
		return((void)ft_printf("Tried do_op on non existant branch / previous branch"));
	if (op == SA)
	{
		swap(&(prev->st_a), &(*br)->st_a, prev->size_a);
		swap(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		(*br)->size_a = prev->size_a;
	}
	if (op == SB)
	{
		swap(&(prev->st_b), &(*br)->st_b, prev->size_b);
		swap(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		(*br)->size_b = prev->size_b;
	}

}

int	op_possible(t_tree *prev, int op)
{
	if (!prev)
		return(ft_printf("tried op_possible on NULL branch\n"), 0);
	if ((op == SA || op == PB || op == RA || op == RRA) && !prev->st_a)
		return(ft_printf("op_possible: tried op on st_a but st_a doesnt exist\n"), 0);
	if ((op == SB || op == PA || op == RB || op == RRB) && !prev->st_b)
		return(ft_printf("op_possible: tried op on st_b but st_a doesnt exist\n"), 0);
	if ((op == SS || op == RR || op == RRR) && (!prev->st_a || !prev->st_b))
		return(ft_printf("op_possible: tried op on both stack but one doesnt exist.\n"), 0);
	return(1);
}

void	swap(int **st_prev, int **st, int size)
{
	if (!st_prev || !(*st_prev) || !st)
		return ((void)ft_printf("tried swap on NULL prev or NULL br\n"));
	copy_st_malloc(size, st_prev, st);
	int tmp = (*st)[0];
	(*st)[0] = (*st)[1];
	(*st)[1] = tmp;
}