/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:57 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/20 16:29:09 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_min(int **st, int size)
{
	int i;
	int min;

	i = 1;
	min = 0;
	while(i < size)
	{
		if ((*st)[i] < (*st)[min])
			min = i;
		i++;
	}
	return(min);
}

int	get_max(int **st, int size)
{
	int i;
	int max;

	i = 1;
	max = 0;
	while(i < size)
	{
		if ((*st)[i] > (*st)[max])
			max = i;
		i++;
	}
	return(max);
}

int	find_cheapest(t_data *d)
{
	int i;
	int cheapest;
	int cheapest_cost;

	i = 0;
	cheapest = 0;
	cheapest_cost = INT_MAX;
	while(i < d->size_a)
	{
		if (cheapest_cost > get_full_cost(d, i))
		{
			cheapest = i;
			cheapest_cost = get_full_cost(d, i);
		}
		i++;
	}
	return(cheapest);
}

static int gfc_2(int op_to_top_a, int op_to_top_b, int fullres)
{
		while(op_to_top_a > 0)
	{
		op_to_top_a--;
		fullres++;
	}
	while(op_to_top_b > 0)
	{
		op_to_top_b--;
		fullres++;
	}
	while(op_to_top_a < 0)
	{
		op_to_top_a++;
		fullres++;
	}
	while(op_to_top_b < 0)
	{
		op_to_top_b++;
		fullres++;
	}
	return(fullres);
}

int get_full_cost(t_data *d, int id)
{
	int op_to_top_a;
	int op_to_top_b;
	int fullres;

	fullres = 0;
	op_to_top_a = op_to_top(&d->st_a, d->size_a, id);
	op_to_top_b = op_to_top(&d->st_b, d->size_b, find_spot_b(d->st_a[id], &d->st_b, d->size_b));
	while(op_to_top_a > 0 && op_to_top_b > 0)
	{
		op_to_top_a--;
		op_to_top_b--;
		fullres++;
	}
	while(op_to_top_a < 0 && op_to_top_b < 0)
	{
		op_to_top_a++;
		op_to_top_b++;
		fullres++;
	}
	return (gfc_2(op_to_top_a, op_to_top_b, fullres));
}
