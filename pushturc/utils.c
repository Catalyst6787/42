#include "header.h"

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

static int cm2(t_data *d, t_ops *tail, t_ops *prev)
{
	if ((tail->op == RA && tail->next->op == RB)
	|| (tail->op == RB && tail->next->op == RA))
	{
		del_node(tail, prev, d);
		prev->next->op = RR;
		prev = NULL;
		tail = d->ops;
		return (1);
	}
	else if ((tail->op == RRA && tail->next->op == RRB)
	|| (tail->op == RRB && tail->next->op == RRA))
	{
		del_node(tail, prev, d);
		prev->next->op = RRR;
		prev = NULL;
		tail = d->ops;
		return (1);
	}
	return(0);
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
		else if (cm2(d, tail, prev))
			continue;
		prev = tail;
		tail = tail->next;
	}
}
