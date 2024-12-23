#include "header.h"

t_stack	*lst_new(int content)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->nbr = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_stack	*lst_add_back(t_stack *list, t_stack *elem)
{
	t_stack *temp;

	if (!list)
		return (elem);
	temp = list;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = elem;
	elem->prev = temp;
	elem->next = NULL;
	return (list);
}

void	lst_add_front(t_stack **lst, t_stack *new)
{
	if (new)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
		new->prev = NULL;
	}
}

t_stack	*del_head(t_stack *list)
{
	if (!list || !list->next)
		return(NULL);
	t_stack	*tmp;
	tmp = list;
	list = list->next;
	free(tmp);
	tmp = NULL;
	return (list);
}

void free_list(t_stack *list)
{
	t_stack *tmp;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void print_list(t_stack *list)
{
	while (list)
	{
		ft_printf("%d -> ", list->nbr);
		list = list->next;
	}
	ft_printf("NULL\n");
}

void rev_print_list(t_stack *list)
{
	while (list && list->next)
		list = list->next;
	while (list)
	{
		ft_printf("%d -> ", list->nbr);
		list = list->prev;
	}
	ft_printf("NULL\n");
}

t_stack *copy_list(t_stack *list)
{
	t_stack *copy = NULL;
	t_stack *tail = NULL;

	while (list)
	{
		t_stack *new_elem = lst_new(list->nbr);
		if (!new_elem)
		{
			free_list(copy);
			return NULL;
		}
		if (copy == NULL)
		{
			copy = new_elem;
			tail = new_elem;
		}
		else
		{
			tail->next = new_elem;
			new_elem->prev = tail;
			tail = new_elem;
		}
		list = list->next;
		}
	return (copy);
}

int	check_sort(t_stack *st)
{
	int last;
	
	if (!st)
		return(-1);
	last = st->nbr;
	while(st)
	{
		if (st->nbr < last)
			return(0);
		last = st->nbr;
		st = st->next;
	}
	return (1);
}

int	is_highest(t_stack *st, int n)
{
	if (!st)
		return(-1);
	while(st)
	{
		if (st->nbr > n)
			return(0);
		st = st->next;
	}
	return(1);
}

int	is_lowest(t_stack *st, int n)
{
	if (!st)
		return(-1);
	while(st)
	{
		if (st->nbr < n)
			return(0);
		st = st->next;
	}
	return(1);
}

int	align(t_stack **st)
{
	int i;
	t_stack *tail;

	tail = *st;
	i = 0;
	if (!st)
		return(-1);
	while (tail && tail->next)
	{
		if (tail->nbr < tail->next->nbr)
			break;
		tail = tail->next;
	}
	tail = tail->next;
	while (tail)
	{
		tail = tail->next;
		i++;
	}
	while(i)
	{
		ft_printf("rrb\n");
		rev_rotate(st);
		i--;
	}
	return(1);
}
