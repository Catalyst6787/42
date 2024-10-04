/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:07:48 by lfaure            #+#    #+#             */
/*   Updated: 2024/09/29 17:17:42 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
void    ft_putchar(char c)
{
	write(1, &c, 1);
}
*/

void    ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*
int main(int ac, char **av)
{
	if (ac < 2)
		return(0);
	ft_putstr(av[1]);
	write(1, "\n", 1);
}
*/