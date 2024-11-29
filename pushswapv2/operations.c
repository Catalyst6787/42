#include "header.h"

int	swap(t_stack **st)
{
	t_stack *first;
	t_stack *second;
	
	if (!(*st) || !((*st)->next))
		return(0);
	first = *st;
	second = first->next;

	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;

	second->id = 0;
	first->id = 1;

	(*st) = second;
	return(1);
}

int rotate(t_stack **st)
{
	t_stack *tail;
	t_stack *last;
	
	tail = *st;
	last = *st;
	if(!tail || !tail->next)
		return(0);
	while(last->next)
		last = last->next;

	(*st) = tail->next;
	tail->next->prev = NULL;

	tail->prev = last;
	last->next = tail;
	tail->next = NULL;
	tail->id = (tail->prev->id + 1);

	tail = *st;
	tail->id = 0;
	tail = tail->next;
	while(tail)
	{
		tail->id = (tail->prev->id + 1);
		tail = tail->next;
	}
	return(1);
}

int rev_rotate(t_stack **st)
{
	t_stack *tail;
	t_stack *last;
	
	tail = *st;
	last = *st;
	if(!tail || !tail->next)
		return(0);
	while(last->next)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = tail;
	tail->prev = last;

	(*st) = last;
	tail = *st;
	tail->id = 0;
	tail = tail->next;	
	while(tail)
	{
		tail->id = (tail->prev->id + 1);
		tail = tail->next;
	}
	return(1);
}