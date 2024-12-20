/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:07:02 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/20 17:11:50 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_to_b(t_data *d)
{
	int	cheapest;

	if ((d->size_a) == 0)
		return ;
	if ((d->size_b) == 0)
	{
		printop(PB, d);
		printop(PB, d);
		push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
		push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
		if (d->st_b[1] > d->st_b[0])
		{
			printop(SB, d);
			swap(&d->st_b, d->size_b);
		}
	}
	cheapest = find_cheapest(d);
	push_cheapest_to_b(cheapest, d);
	push_to_b(d);
}

void	push_to_a(t_data *d)
{
	while ((d->size_b) > 0)
	{
		printop(PA, d);
		push(&d->st_b, &d->size_b, &d->st_a, &d->size_a);
	}
}

void	solve_for_3(int	**st_a, int *size_a, t_data *d)
{
	if ((*size_a) == 0)
		return ;
	if ((*size_a) == 2 && ((*st_a)[0] > (*st_a)[1]))
		return (printop(SA, d), swap(st_a, *size_a));
	else if (*size_a == 2)
		return ;
	if ((*st_a)[0] < (*st_a)[1] && (*st_a)[1] < (*st_a)[2])
		return ;
	else if ((*st_a)[0] < (*st_a)[1] && (*st_a)[0] < (*st_a)[2])
		return (printop(RRA, d),
			rev_rotate(st_a, *size_a), printop(SA, d), swap(st_a, *size_a));
	else if ((*st_a)[0] > (*st_a)[1] && (*st_a)[0] > (*st_a)[2])
	{
		if ((*st_a)[1] < (*st_a)[2])
			return (printop(RA, d), rotate(st_a, *size_a));
		else
			return (printop(RA, d),
				rotate(st_a, *size_a), printop(SA, d), swap(st_a, *size_a));
	}
	if ((*st_a)[1] > (*st_a)[2])
		return (printop(RRA, d), rev_rotate(st_a, *size_a));
	else
		return (printop(SA, d), swap(st_a, *size_a));
}

void	solve_for_less_than_6(t_data *d)
{
	if (d->size_a == 3)
		return (solve_for_3(&d->st_a, &d->size_a, d));
	else if (d->size_a == 2)
		return (printop(SA, d), swap(&d->st_a, d->size_a));
	else if (d->size_a >= 4)
	{
		put_to_top_a(&d->st_a, d->size_a, get_min(&d->st_a, d->size_a), d);
		printop(PB, d);
		push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
	}
	if (d->size_a == 4)
	{
		put_to_top_a(&d->st_a, d->size_a, get_min(&d->st_a, d->size_a), d);
		printop(PB, d);
		push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
	}
	solve_for_3(&d->st_a, &d->size_a, d);
	push_to_a(d);
}

int	cost_to_top(int **st, int size, int id)
{
	int	op;

	op = op_to_top(st, size, id);
	if (op < 0)
		return (-op);
	else
		return (op);
}
