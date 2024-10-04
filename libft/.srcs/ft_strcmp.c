/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:58:22 by lfaure            #+#    #+#             */
/*   Updated: 2024/09/29 17:17:43 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac != 3)
		return(0);
	printf("%d\n", ft_strcmp(av[1], av[2]));
}
*/