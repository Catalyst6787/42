/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:44:20 by lfaure            #+#    #+#             */
/*   Updated: 2025/03/06 14:44:40 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atou(const char *str)
{
	unsigned long	r;
	int				i;
	int				n;

	i = 0;
	r = 0;
	n = 1;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	r *= n;
	if (r > 2147483647)
		return (-1);
	return ((int)r);
}
