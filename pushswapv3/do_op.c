#include "header.h"

void	do_op(t_tree *prev, t_tree **br, int op)
{
	if (!prev || !br)
		return((void)ft_printf("Tried do_op on non existant branch / previous branch"));
	else if (op == SA)
	{
		swap(&(prev->st_a), &(*br)->st_a, prev->size_a);
		swap(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		copy_st_malloc(prev->size_b, &prev->st_b, &(*br)->st_b);
		copy_st_malloc(prev->size_b, &prev->st_b_optid, &(*br)->st_b_optid);
		(*br)->size_a = prev->size_a;
		(*br)->size_b = prev->size_b;
	}
	else if (op == SB)
	{
		swap(&(prev->st_b), &(*br)->st_b, prev->size_b);
		swap(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		copy_st_malloc(prev->size_a, &prev->st_a, &(*br)->st_a);
		copy_st_malloc(prev->size_a, &prev->st_a_optid, &(*br)->st_a_optid);
		(*br)->size_b = prev->size_b;
		(*br)->size_a = prev->size_a;
	}
	else if (op == SS)
	{
		swap(&(prev->st_a), &(*br)->st_a, prev->size_a);
		swap(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		swap(&(prev->st_b), &(*br)->st_b, prev->size_b);
		swap(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		(*br)->size_b = prev->size_b;
		(*br)->size_a = prev->size_a;
	}
	else
		do_op2(prev, br, op);
}

void	do_op2(t_tree *prev, t_tree **br, int op)
{
	if (op == PA)
	{
		push_a(prev, br);
		push_a_optid(prev, br);
	}
	else if (op == PB)
	{
		push_b(prev, br);
		push_b_optid(prev, br);
	}
	else if (op == RA)
	{
		rotate(&(prev->st_a), &(*br)->st_a, prev->size_a);
		rotate(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		copy_st_malloc(prev->size_b, &prev->st_b, &(*br)->st_b);
		copy_st_malloc(prev->size_b, &prev->st_b_optid, &(*br)->st_b_optid);
		(*br)->size_a = prev->size_a;
		(*br)->size_b = prev->size_b;
	}
	else if (op == RB)
	{
		rotate(&(prev->st_b), &(*br)->st_b, prev->size_b);
		rotate(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		copy_st_malloc(prev->size_a, &prev->st_a, &(*br)->st_a);
		copy_st_malloc(prev->size_a, &prev->st_a_optid, &(*br)->st_a_optid);
		(*br)->size_b = prev->size_b;
		(*br)->size_a = prev->size_a;
	}
	else
		do_op3(prev, br, op);
}

void	do_op3(t_tree *prev, t_tree **br, int op)
{
	if (op == RR)
	{
		rotate(&(prev->st_a), &(*br)->st_a, prev->size_a);
		rotate(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		rotate(&(prev->st_b), &(*br)->st_b, prev->size_b);
		rotate(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		(*br)->size_b = prev->size_b;
		(*br)->size_a = prev->size_a;
	}
	else if (op ==  RRA)
	{
		rev_rotate(&(prev->st_a), &(*br)->st_a, prev->size_a);
		rev_rotate(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		copy_st_malloc(prev->size_b, &prev->st_b, &(*br)->st_b);
		copy_st_malloc(prev->size_b, &prev->st_b_optid, &(*br)->st_b_optid);
		(*br)->size_a = prev->size_a;
		(*br)->size_b = prev->size_b;
	}
	else if (op ==  RRB)
	{
		rev_rotate(&(prev->st_b), &(*br)->st_b, prev->size_b);
		rev_rotate(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		copy_st_malloc(prev->size_a, &prev->st_a, &(*br)->st_a);
		copy_st_malloc(prev->size_a, &prev->st_a_optid, &(*br)->st_a_optid);
		(*br)->size_b = prev->size_b;
		(*br)->size_a = prev->size_a;
	}
	else if (op == RRR)
	{
		rev_rotate(&(prev->st_a), &(*br)->st_a, prev->size_a);
		rev_rotate(&(prev->st_a_optid), &(*br)->st_a_optid, prev->size_a);
		rev_rotate(&(prev->st_b), &(*br)->st_b, prev->size_b);
		rev_rotate(&(prev->st_b_optid), &(*br)->st_b_optid, prev->size_b);
		(*br)->size_b = prev->size_b;
		(*br)->size_a = prev->size_a;
	}
}
