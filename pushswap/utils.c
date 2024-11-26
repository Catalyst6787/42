#include "header.h"

t_stack	*lst_new(int content)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->nbr = content;
	elem->next = NULL;
	return (elem);
}

t_stack	*lst_add_back(t_stack *list, t_stack *elem)
{
	t_stack *temp;

	if (!list)
		return (elem);
	temp = list;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next->prev = temp;
	temp->next = elem;
	return (list);
}

void	lst_add_front(t_stack **lst, t_stack *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
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
		printf("%d -> ", list->nbr);
		list = list->next;
	}
	printf("NULL\n");
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
			tail = new_elem;
		}
		list = list->next;
		}
	return (copy);
}