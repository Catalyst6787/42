/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:14 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 12:19:49 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_key_debug(int key, t_data *d)
{
	(void)d;
	ft_printf("EVENT! Key pressed: %d\n", key);
	if (key == 53 || key == 12)
	{
		mlx_hook(d->win, 0, 0, close, &d);
		return (end_program(d));
	}
	return (1);
}

void	print_map_debug(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (d->map[y])
	{
		while (d->map[y][x])
			ft_printf("%c", d->map[y][x++]);
		ft_printf("\n");
		x = 0;
		y++;
	}
}
