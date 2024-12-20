/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:32:30 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/20 17:05:56 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_spot_b(int val, int **st_b, int size)
{
	int	res;

	res = 0;
	if (is_lower(val, st_b, size))
		res = get_min(st_b, size);
	else if (is_bigger(val, st_b, size))
		res = get_max(st_b, size) - 1;
	else
		res = get_smallest_bigger(val, st_b, size);
	if (res == size)
		return (0);
	else
		return (res + 1);
}

void	push_cheapest_to_b(int cheapest, t_data *d)
{
	put_to_top_a(&d->st_a, d->size_a, cheapest, d);
	put_to_top_b(&d->st_b, d->size_b,
		find_spot_b((d->st_a)[0], &d->st_b, d->size_b), d);
	printop(PB, d);
	push(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
}

int	get_smallest_bigger(int val, int **st, int size)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = 0;
	while (i < size)
	{
		if (((*st)[i] < (*st)[smallest] && (*st)[i] > val)
		|| ((*st)[smallest] < val && (*st)[i] > val))
			smallest = i;
		i++;
	}
	return (smallest);
}

int	get_bigest_smaller(int val, int **st, int size)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = 0;
	while (i < size)
	{
		if (((*st)[i] > (*st)[biggest] && (*st)[i] < val)
		|| ((*st)[biggest] > val && (*st)[i] < val))
			biggest = i;
		i++;
	}
	return (biggest);
}

void	align_stack(t_data *d)
{
	put_to_top_b(&d->st_a, d->size_a, get_max(&d->st_b, d->size_b), d);
}
