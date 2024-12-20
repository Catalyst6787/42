/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:33:33 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/20 16:34:17 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
