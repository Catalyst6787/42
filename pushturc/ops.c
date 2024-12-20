/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:36:11 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/20 17:02:16 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	while (last && last->next)
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
	t_ops	*tail;

	tail = d->ops;
	while (tail)
	{
		lst_printop(tail->op);
		tail = tail->next;
	}
}

void	printop(int op, t_data *d)
{
	lstadd_back_ops(&d->ops, lstnew_ops(op));
}
