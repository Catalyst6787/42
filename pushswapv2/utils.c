#include "header.h"

t_stack *lst_new(int nbr)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return(ft_printf("Malloc error in lst_new.\n"), NULL);
	elem->nbr = nbr;
	elem->id = 0;
	elem->optid = 0;
	elem->next = NULL;
	elem->prev = NULL;

	return(elem);
}

int	lst_add_back(t_stack **st, t_stack *elem)
{
	if (!elem)
		return(0);
	t_stack *tail;

	tail = *st;

	if (!tail)
		return (*st = elem, elem->id = 0, 1);
	while(tail->next)
		tail = tail->next;

	elem->prev = tail;
	tail->next = elem;
	elem->id = (tail->id + 1);

	return(1);
}

int	print_lst(t_stack **st)
{
	t_stack *tail;

	
	tail = *st;
	if (!tail)
		return(ft_printf("\nNULL node\n"), 0);
	while(tail)
	{
		printf_elem(tail);
		tail = tail->next;
	}
	return (1);
}

int printf_elem(t_stack *elem)
{
	if (!elem)
		return(ft_printf("element doesn't exist.\n"), 0);
	ft_printf("Node n°%d, optid: %d, value: %d\n", elem->id, elem->optid, elem->nbr);
	return(1);
}

int free_lst(t_stack **st)
{
	t_stack	*tail;
	t_stack	*tmp;

	tail = *st;
	while(tail)
	{
		//ft_printf("attempt free on:\n");
		//printf_elem(tail);
		tmp = tail->next;
		free(tail);
		tail = tmp;
	}
	(*st) = NULL;
	return (1);
}

// return actual siye so if last id is 4 return 5 (id start at 0)
int	size_list(t_stack **st)
{
	t_stack *tail;

	tail = *st;
	while(tail->next)
		tail = tail->next;
	return(tail->id + 1);
}

int	set_optid(t_stack **st)
{
	t_stack	*tail;
	t_stack	*smallest;
	t_stack	*biggest;
	int listsize;
	int optid;
	int nbr;

	nbr = 1;
	optid = 0;
	tail = *st;
	if (!tail)
		return(0);
	smallest = tail;
	biggest = tail;
	listsize = size_list(st);
	while(tail)
	{
		if (tail->nbr < smallest->nbr)
			smallest = tail;
		else if (tail->nbr > biggest->nbr)
			biggest = tail;
		tail = tail->next;
	}
	smallest->optid = optid;
	optid++;
	biggest->optid = listsize - 1;

	tail = *st;
	nbr = smallest->nbr + 1;
	while(nbr < biggest->nbr)
	{
		while(tail)
		{
			if (tail->nbr == nbr)
			{
				tail->optid = optid;
				optid++;
			}
			tail = tail->next;
		}
		tail = *st;
		nbr++;
	}
	return(1);
}