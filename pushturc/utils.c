#include "header.h"

void	print_st(int size, int **st)
{
	int i;

	i = 0;
	if (!st || !(*st))
		return(ft_printf("NULL stack\n"), (void)NULL);
	while(i < size)
	{
		ft_printf("element n: %d, value: %d\n", i, (*st)[i]);
		i++;
	}
}

void	free_st(int **st)
{
	if (!st || !(*st))
		return ;
	free(*st);
	(*st) = NULL;
	st = NULL;
}

void	copy_st(int size, int **st, int **st_copy)
{
	if (!st || !(*st))
		return ;
	if (!st_copy)
		return ;
	int i;

	i = 0;
	while(i < size)
	{
		(*st_copy)[i] = (*st)[i];
		i++;
	}
}

void	copy_st_malloc(int size, int **st, int **st_copy)
{
	if (!st || !(*st))
		return ;
	if (!st || !(*st))
		return((void)ft_printf("tried copy_st_malloc on NULL st_copy"));
	*st_copy = malloc(sizeof(int) * size);
	if (!(*st_copy))
		return (*st_copy = NULL, (void)ft_printf("malloc error in copy_st_malloc"));
	copy_st(size, st, st_copy);
}

void	lst_printop(int op)
{
	if (op == SA)
		ft_printf("sa\n");
	if (op == SB)
		ft_printf("sb\n");
	if (op == SS)
		ft_printf("ss\n");
	if (op == PA)
		ft_printf("pa\n");
	if (op == PB)
		ft_printf("pb\n");
	if (op == RA)
		ft_printf("ra\n");
	if (op == RB)
		ft_printf("rb\n");
	if (op == RR)
		ft_printf("rr\n");
	if (op == RRA)
		ft_printf("rra\n");
	if (op == RRB)
		ft_printf("rrb\n");
	if (op == RRR)
		ft_printf("rrr\n");
}

void	lstadd_back_ops(t_ops **lst, t_ops *new)
{
	t_ops	*last;

	last = *lst;

	if (!new)
		return ;
	while(last && last->next)
		last = last->next;
	if (!last)
		*lst = new;
	else
		last->next = new;
}

t_ops	*lstnew_ops(int op)
{
	t_ops	*elem;

	elem = malloc(sizeof(t_ops));
	if (!elem)
		return (NULL);
	elem->op = op;
	elem->next = NULL;
	return (elem);
}

void	print_all_ops(t_data *d)
{
	t_ops *tail;

	tail = d->ops;
	while(tail)
	{
		lst_printop(tail->op);
		tail = tail->next;
	}
}

void	printop(int op, t_data *d)
{
	lstadd_back_ops(&d->ops, lstnew_ops(op));
}

void	free_ops(t_data *d)
{
	t_ops *tail;
	t_ops *tmp;

	tail = d->ops;
	while(tail)
	{
		tmp = tail->next;
		free(tail);
		tail = tmp;
	}
}
void	del_node(t_ops *node, t_ops *prev, t_data *d)
{
	if (!prev)
		d->ops = node->next;
	else
		prev->next = node->next;
	free(node);
}

void	clean_moves(t_data *d)
{
	t_ops *tail;
	t_ops *prev;

	tail = d->ops;
	prev = NULL;
	while(tail && tail->next)
	{
		if ((tail->op == PB && tail->next->op == PA)
		|| (tail->op == PA && tail->next->op == PB)
		|| (tail->op == SA && tail->next->op == SA)
		|| (tail->op == SB && tail->next->op == SB)
		|| (tail->op == RB && tail->next->op == RRB)
		|| (tail->op == RRB && tail->next->op == RB)
		|| (tail->op == RA && tail->next->op == RRA)
		|| (tail->op == RRA && tail->next->op == RA))
		{
			del_node(tail, prev, d);
			del_node(prev->next, prev, d);
			prev = NULL;
			tail = d->ops;
			continue;
		}
		prev = tail;
		tail = tail->next;
	}
}

void	combine_moves(t_data *d)
{
	t_ops *tail;
	t_ops *prev;

	tail = d->ops;
	prev = NULL;
	while(tail && tail->next)
	{
		if ((tail->op == SA && tail->next->op == SB)
		|| (tail->op == SB && tail->next->op == SA))
		{
			del_node(tail, prev, d);
			prev->next->op = SS;
			prev = NULL;
			tail = d->ops;
			continue;
		}
		else if ((tail->op == RA && tail->next->op == RB)
		|| (tail->op == RB && tail->next->op == RA))
		{
			del_node(tail, prev, d);
			prev->next->op = RR;
			prev = NULL;
			tail = d->ops;
			continue;
		}
		else if ((tail->op == RRA && tail->next->op == RRB)
		|| (tail->op == RRB && tail->next->op == RRA))
		{
			del_node(tail, prev, d);
			prev->next->op = RRR;
			prev = NULL;
			tail = d->ops;
			continue;
		}
		prev = tail;
		tail = tail->next;
	}
}

int	is_sorted_a(int **st_a, int size_a)
{
	int i;

	i = 0;
	while(i < size_a - 1)
	{
		if ((*st_a)[i] > (*st_a)[i + 1])
			return(0);
		i++;
	}
	return(1);
}

