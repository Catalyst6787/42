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

int	push(t_stack **st_a, t_stack **st_b)
{
	t_stack *tmp;

	if (*st_a == NULL)
		return (0);
	tmp = *st_a;
	*st_a = (*st_a)->next;
	if (*st_a)
		(*st_a)->prev = NULL;
	tmp->next = *st_b;
	if (*st_b)
		(*st_b)->prev = tmp;
	tmp->prev = NULL;
	*st_b = tmp;
	return (1);
}

int	rotate(t_stack *st)
{
	int	tmp;

	tmp = st->nbr;
	if (!st || !st->next)
		return (0); 
	while (st->next)
	{
		st->nbr = st->next->nbr;
		st = st->next;
	}
	st->nbr = tmp;
	return (1);
}

int	r_rotate(t_stack *st_a, t_stack *st_b)
{
	if (!rotate(st_a))
		return (0);
	if (!rotate(st_b))
		return (0);
	return(1);
}

int rev_rotate(t_stack **st)
{
	int tmp;
	t_stack *tail;

	if (!(*st) || !(*st)->next)
		return (0);

	tail = *st;
	while (tail->next)
		tail = tail->next;
	tmp = tail->nbr;
	while(tail->prev)
	{
		tail->nbr = tail->prev->nbr;
		tail = tail->prev;
	}
	(*st)->nbr = tmp;
	return (1);
}

int r_rev_rotate(t_stack *st_a, t_stack *st_b)
{
	if (!rev_rotate(&st_a))
		return (0);
	if (!rev_rotate(&st_b))
		return (0);
	return(1);
}

