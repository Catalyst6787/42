/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:20:55 by lfaure            #+#    #+#             */
/*   Updated: 2024/10/07 18:53:29 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsigned_c(unsigned int n)
{
	int c;

	c = 0;
	if (n >= 10)
	{
		c += ft_putnbr_c(n / 10);
		n = n % 10;
	}
	return (c + ft_putchar_c((n) + '0'));
}