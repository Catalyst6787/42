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

