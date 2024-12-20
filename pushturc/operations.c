/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:27:30 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/20 16:29:28 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(int **st, int size)
{
	int tmp;

	if (size < 2)
		return ;
	tmp = (*st)[0];
	(*st)[0] = (*st)[1];
	(*st)[1] = tmp;
}

void	rotate(int **st, int size)
{
	int tmp;
	int i;

	i = 0;
	if (size < 2)
		return ;
	tmp = (*st)[0];
	while(i < size - 1)
	{
		(*st)[i] = (*st)[i + 1];
		i++;
	}
	(*st)[size - 1] = tmp;
}

void	rev_rotate(int **st, int size)
{
	int tmp;
	int i;

	if (size < 2)
		return ;
	i = size - 1;
	tmp = (*st)[size - 1];
	while(i > 0)
	{
		(*st)[i] =  (*st)[i - 1];
		i--;
	}
	(*st)[i] = tmp;
}

static void push2(int *size_from, int **st_from, int i)
{
	int	*new_st_from;

	new_st_from = malloc(sizeof(int) * (*size_from));
	while(i < (*size_from))
	{
		new_st_from[i] = (*st_from)[i + 1];
		i++;
	}
	return(free_st(st_from), (void)(*st_from = new_st_from));
}

void	push(int **st_from, int *size_from, int **st_to, int *size_to)
{
	int *new_st_to;
	int i;

	i = 1;
	if (*size_from < 1)
		return ;
	(*size_to) += 1;
	new_st_to = malloc(sizeof(int) * (*size_to ));
	new_st_to[0] = *st_from[0];
	while(i < *size_to)
	{
		new_st_to[i] = (*st_to)[i - 1];
		i++;
	}
	free_st(st_to);
	*st_to = new_st_to;
	i = 0;
	(*size_from)--;
	if ((*size_from) == 0)
		return(free_st(st_from));
	return(push2(size_from, st_from, i));
}

