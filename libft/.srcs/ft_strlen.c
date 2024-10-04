/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:17:59 by lfaure            #+#    #+#             */
/*   Updated: 2024/09/29 17:17:44 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if (ac < 2)
		return(0);
	printf("%d\n", ft_strlen(av[1]));
}
*/