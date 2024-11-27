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
		return (0);  // Nothing to push
	tmp = *st_a;
	*st_a = (*st_a)->next;
	tmp->next = *st_b;
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

int revrotate(t_stack *st)
{
	int tmp;

	if (!st || !st->next)
		return (0);
	while (st->next)
		st = st->next;
	tmp = st->nbr;
	while(st->prev)
	{
		st->nbr = st->prev->nbr;
		st = st->prev;
	}
	st->nbr = tmp;
	return (1);
}

