/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:26 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/18 12:17:21 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_all(t_data *d, char **argv)
{
	if(!init_struct(d))
		return(end_program(d), 0);
	if(!get_map(d, argv[1]))
		return(0);
	d->win_h = d->map_h * d->asset_height;
	d->win_l = d->map_l * d->asset_width;
	if(!init_mlx(d))
		return(end_program(d), 0);
	
	if(!init_assets(d))
		return(end_program(d), 0);
	return(1);
}

int	init_struct(t_data *d)
{
	if(!init_graph(d))
		return(end_program(d), 0);
	if(!init_data2(d))
		return(end_program(d), 0);
	d->mlx = NULL;
	d->win = NULL;
	d->img = NULL;
	d->img_addr = NULL;
	d->bits_per_pixel = 0;
	d->line_length = 0;
	d->endian =0;
	d->win_l = 0;
	d->win_h = 0;
	d->asset_width = 32;
	d->asset_height = 32;
	d->map = NULL;
	d->map_h = 0;
	d->map_l = 0;
	return(1);
}

int	init_data2(t_data *d)
{
	d->d2 = malloc(sizeof(t_data2));
	if (!d->d2)
		return (0);
	d->d2->player_y = 0;
	d->d2->player_x = 0;
	d->d2->all_c_found = 0;
	d->d2->nbr_of_c = 0;
	d->d2->player_found = 0;
	d->d2->exit_found = 0;
	return(1);
}

int	init_graph(t_data *d)
{
	d->graph = malloc(sizeof(t_graph));
	if (!d->graph)
		return (0);
	d->graph->wall = NULL;
	d->graph->floor = NULL;
	d->graph->collect = NULL;
	d->graph->exit_closed = NULL;
	d->graph->exit_opened = NULL;
	d->graph->player = NULL;
	return(1);
}

int init_mlx(t_data *d)
{
	d->mlx = mlx_init();
	if (!d->mlx)
		return (0);
	d->win = mlx_new_window(d->mlx, d->win_l, d->win_h, "Hello world!");
	if (!d->win)
		return (free(d->mlx), 0);
	return(1);
}

int	init_assets(t_data *d)
{
	d->graph->floor = mlx_xpm_file_to_image(d->mlx, "./assets/Floor1.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->floor)
		return (0);
	d->graph->player = mlx_xpm_file_to_image(d->mlx, "./assets/Player.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->player)
		return (0);
	d->graph->wall = mlx_xpm_file_to_image(d->mlx, "./assets/Wall1.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->wall)
		return (0);
	d->graph->collect = mlx_xpm_file_to_image(d->mlx, "./assets/Collect.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->wall)
		return (0);
	d->graph->exit_closed = mlx_xpm_file_to_image(d->mlx, "./assets/Exit_closed.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->wall)
		return (0);
	d->graph->exit_opened = mlx_xpm_file_to_image(d->mlx, "./assets/Exit_opened.xpm", &d->asset_width, &d->asset_height);
	if (!d->graph->wall)
		return (0);
	return(1);
}