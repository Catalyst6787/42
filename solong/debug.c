/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:14 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/18 10:20:16 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int print_key_debug(int key, t_data *d)
{
	(void)d;
	printf("EVENT! Key pressed: %d\n", key);
	if (key == 53 || key == 12)
	{
		mlx_hook(d->win, 0, 0, close, &d);
		return(end_program(d));
	}
	return(1);
}    

void	print_map_debug(t_data *d)
{
	int x = 0;
	int y = 0;
	while(d->map[y])
	{
		while(d->map[y][x])
			printf("%c", d->map[y][x++]); // TODO replace printf w ft_printf
		printf("\n");
		x = 0;
		y++;
	}
}
