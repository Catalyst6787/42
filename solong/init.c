#include "so_long.h"

int	init_struct(t_data *d)
{
	d->mlx = NULL;
	d->win = NULL;
	d->img = NULL;
	d->img_addr = NULL;
	d->bits_per_pixel = 0;
	d->line_length = 0;
	d->endian =0;
	d->win_l = 1920;
	d->win_h = 1080;
	d->asset_width = 32;
	d->asset_height = 32;
	d->map = NULL;
	d->map_h = 0;
	d->map_l = 0;
	d->player_y = 0;
	d->player_x = 0;
	return(init_graph(d));
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
	return(1);
}