/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:53 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/19 13:50:45 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aff_asset(t_data *d, int y, int x)
{
	if (d->map[y][x] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->graph->floor, x * d->asset_width, y * d->asset_height);
	else if (d->map[y][x] == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->graph->wall, x * d->asset_width, y * d->asset_height);
	else if (d->map[y][x] == 'C')
	{
		mlx_put_image_to_window(d->mlx, d->win, d->graph->floor, x * d->asset_width, y * d->asset_height);
		mlx_put_image_to_window(d->mlx, d->win, d->graph->collect, x * d->asset_width, y * d->asset_height);
	}
	else if (d->map[y][x] == 'E' && d->d2->nbr_of_c > 0)
		mlx_put_image_to_window(d->mlx, d->win, d->graph->exit_closed, x * d->asset_width, y * d->asset_height);
	else if (d->map[y][x] == 'E' && d->d2->nbr_of_c == 0)
		mlx_put_image_to_window(d->mlx, d->win, d->graph->exit_opened, x * d->asset_width, y * d->asset_height);
	else
		ft_printf("problem in aff asset");
}

int render_map(t_data *d) // test
{
	int	y = 0;
	int	x = 0;
	while(d->map[y])
	{
		while(d->map[y][x])
		{
			aff_asset(d, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->graph->player, d->d2->player_x * d->asset_width, d->d2->player_y * d->asset_height);
	return(1);
}