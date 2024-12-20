/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:31:20 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/20 17:19:23 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	op_to_top(int **st, int size, int id)
{
	(void)st;
	if (id < size - id)
		return (id);
	else
		return (-(size - id));
}

int	put_to_top_a(int **st, int size, int id, t_data *d)
{
	int	op;
	int	res;

	op = op_to_top(st, size, id);
	res = op;
	while (op > 0)
	{
		printop(RA, d);
		rotate(st, size);
		op--;
	}
	while (op < 0)
	{
		printop(RRA, d);
		rev_rotate(st, size);
		op++;
	}
	return (res);
}

int	put_to_top_b(int **st, int size, int id, t_data *d)
{
	int	op;
	int	res;

	if (id == size)
		return (-1);
	op = op_to_top(st, size, id);
	res = op;
	while (op > 0)
	{
		printop(RB, d);
		rotate(st, size);
		op--;
	}
	while (op < 0)
	{
		printop(RRB, d);
		rev_rotate(st, size);
		op++;
	}
	if (res < 0)
		return (res - 1);
	return (res);
}

int	is_lower(int val, int **st, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*st)[i] < val)
			return (0);
		i++;
	}
	return (1);
}

int	is_bigger(int val, int **st, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*st)[i] > val)
			return (0);
		i++;
	}
	return (1);
}
