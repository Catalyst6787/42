#include "header.h"

t_stack	**swap(t_stack **st)
{
	t_stack *tail;
	t_stack *new_head;

	if (!st || !*st)
		return(NULL);
	tail = *st;
	new_head = (*st)->next;

	if (!tail || !tail->next)
		return(0);
	(*st) = new_head;
	tail->next = new_head->next;
	if (tail->next)
		tail->next->prev = tail;

	new_head->prev = NULL;
	new_head->next = tail;
	new_head->id = 0;

	tail->prev = new_head;
	tail->id = 1;

	return(st);
}

t_stack	**rotate(t_stack **st)
{
	t_stack *tail;
	t_stack *last;

	if(!st || !(*st))
		return(0);
	tail = *st;
	last = *st;
	if (!tail || !tail->next)
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
	return(st);
}

t_stack	**rev_rotate(t_stack **st)
{
	t_stack *tail;
	t_stack *last;
	
	if (!st || !(*st))
		return(0);
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
	return(st);
}

int push(t_stack **st_from, t_stack **st_to)
{
	if (!st_from || !(*st_from))
		return(0);
	t_stack *tail_from;

	tail_from = *st_from;
	if (!tail_from)
		return(ft_printf("\nNothing to push, NULL node\n"), 0);

	lst_add_front(st_to, copy_elem(tail_from));
	del_head(st_from);
	return(1);
}