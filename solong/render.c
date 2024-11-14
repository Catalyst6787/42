#include "so_long.h"

void	aff_asset(t_data *d, int y, int x)
{
	if (d->map[y][x] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->graph->floor, y * d->asset_height, x * d->asset_width);
	if (d->map[y][x] == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->graph->wall, y * d->asset_height, x * d->asset_width);
	if (d->map[y][x] == 'P')
		mlx_put_image_to_window(d->mlx, d->win, d->graph->player, y * d->asset_height, x * d->asset_width);
}

int render_map(t_data *d)
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
	return(1);
}