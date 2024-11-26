#include "header.h"

int	swap(t_stack *st)
{
	int	tmp;

	tmp = 0;
	if(!st || !st->next)
		return (0);
	tmp = st->nbr;
	st->nbr = st->next->nbr;
	st->next->nbr = tmp;
	return(1);
}

int	sswap(t_stack *st_a, t_stack *st_b)
{
	if (!swap(st_a))
		return (0);
	if (!swap(st_b))
		return (0);
	return(1);
}

int	push(t_stack *st_from, t_stack *st_to)
{
	if (!st_from || !st_to)
		return (0);
	lst_add_front(st_to, lst_new(st_from->nbr));
	del_head(st_from);
	return(1);
}