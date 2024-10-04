/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:18:59 by lfaure            #+#    #+#             */
/*   Updated: 2024/09/29 16:50:36 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void    ft_swap(int *a, int *b)
{
	int swp;
	
	swp = *a;
	*a = *b;
	*b = swp; 
}
/*
#include <stdio.h>
int main(void)
{
	int a = 12;
	int b = 21;
	ft_swap(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
}
*/