/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:31:02 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 15:03:04 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_assets2(t_data *d)
{
	d->graph->exit_closed = mlx_xpm_file_to_image(d->mlx,
			"./assets/Exit_closed.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->exit_closed)
		return (0);
	d->graph->exit_opened = mlx_xpm_file_to_image(d->mlx,
			"./assets/Exit_opened.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->exit_opened)
		return (0);
	d->graph->monster = mlx_xpm_file_to_image(d->mlx,
			"./assets/Monster.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->monster)
		return (0);
	return (1);
}

int	init_assets(t_data *d)
{
	d->graph->floor = mlx_xpm_file_to_image(d->mlx,
			"./assets/Floor1.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->floor)
		return (0);
	d->graph->player = mlx_xpm_file_to_image(d->mlx,
			"./assets/Player1.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->player)
		return (0);
	d->graph->wall = mlx_xpm_file_to_image(d->mlx,
			"./assets/Wall1.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->wall)
		return (0);
	d->graph->collect = mlx_xpm_file_to_image(d->mlx,
			"./assets/Collect.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->collect)
		return (0);
	return (init_assets2(d));
}
