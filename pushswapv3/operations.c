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
	else if (op == SB)
	{
		swap(&(prev->st_b), &(*br)->st_b, prev->size_b);
		swap(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		(*br)->size_b = prev->size_b;
	}
	else if (op == SS)
	{
		do_op(prev, br, SA);
		do_op(prev, br, SB);
	}
	else
		do_op2(prev, br, op);
}

void	do_op2(t_tree *prev, t_tree **br, int op)
{
	if (op == PA)
	{
		push_a(prev->size_a, &(*br)->size_a, prev->st_b, (*br)->st_a);
		push_a(prev->size_a, &(*br)->size_a, prev->st_b_optid, (*br)->st_a_optid);
	}
	else if (op == PB)
	{
		push_a(prev->size_b, &(*br)->size_b, prev->st_a, (*br)->st_b);
		push_a(prev->size_b, &(*br)->size_b, prev->st_b_optid, (*br)->st_a_optid);
	}
	else if (op == RA)
	{
		rotate(&(prev->st_a), &(*br)->st_a, prev->size_a);
		rotate(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		(*br)->size_a = prev->size_a;
	}
	else if (op == RB)
	{
		rotate(&(prev->st_b), &(*br)->st_b, prev->size_b);
		rotate(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		(*br)->size_b = prev->size_b;
	}
	else
		do_op3(prev, br, op);
}

void	do_op3(t_tree *prev, t_tree **br, int op)
{
	if (op == RR)
	{
		do_op2(prev, br, RA);
		do_op2(prev, br, RB);
	}
	else if (op ==  RRA)
	{
		rev_rotate(&(prev->st_a), &(*br)->st_a, prev->size_a);
		rev_rotate(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		(*br)->size_a = prev->size_a;
	}
	else if (op ==  RRB)
	{
		rev_rotate(&(prev->st_b), &(*br)->st_b, prev->size_b);
		rev_rotate(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		(*br)->size_b = prev->size_b;
	}
	else if (op == RRR)
	{
		do_op3(prev, br, RRA);
		do_op3(prev, br, RRB);
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
	int tmp;

	if (!st_prev || !(*st_prev) || !st)
		return ((void)ft_printf("tried swap on NULL prev or NULL br\n"));
	copy_st_malloc(size, st_prev, st);
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
	i = size - 1;
	tmp = (*st)[size - 1];
	while(i > 0)
	{
		(*st)[i] =  (*st)[i - 1];
		i--;
	}
	(*st)[i] = tmp;
}
void	push_a(int size_prev, int *size, int **st, int **st_prev)
{
	int i;

	i = 1;
	*size = size_prev + 1;
	*st = malloc(sizeof(int) * (*size));
	(*st)[0] = (*st_prev)[0];
	while(i < *size)
	{
		(*st)[i] = (*st_prev)[i - 1];
		i++;
	}
}