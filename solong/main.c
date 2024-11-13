#include "so_long.h"

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
    char *dst;
	if (x >= 0 && x <= d->win_l && y >= 0 && y <= d->win_h) // prevents putting pixel outside of window 
	{
		dst = d->img_addr + (y * d->line_length + x * (d->bits_per_pixel / 8)); // calculate offset in winlen
    	*(unsigned int*)dst = color;
	}
}
/*
int move_little_pixel(t_data *d, int direction)
{
	static int y;
	static int x;

	if (!y)
		y = 10;
	if (!x)
		x = 10;
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	if (direction == 0)
		my_mlx_pixel_put(d, x, y--, 0xf9f9f9);
	else if (direction == 2)
		my_mlx_pixel_put(d, x++, y, 0xf9f9f9);
	else if (direction == 1)
		my_mlx_pixel_put(d, x, y++, 0xf9f9f9);
	else if (direction == 3)
		my_mlx_pixel_put(d, x--, y, 0xf9f9f9);
	return(0);
}
*/
int	key_handler(int key, t_data *d)
{
	(void)d;
	printf("EVENT! Key pressed: %d\n", key);
	if (key == 53 || key == 12)
	{
		mlx_hook(d->win, 0, 0, close, &d);
		return(end_program(d));
	}
	/*
	if (key == 13)
		move_little_pixel(d, 0);
	else if (key == 0)
		move_little_pixel(d, 3);
	else if (key == 1)
		move_little_pixel(d, 1);
	else if (key == 2)
		move_little_pixel(d, 2);
	*/
	return(1);
}

//free everything here
int end_program(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
}



int	main(void)
{
    t_data  d;

	d.win_l = 1920;
	d.win_h = 1080;
	d.asset_width = 32;
	d.asset_height = 32;

    d.mlx = mlx_init();
    if (!d.mlx)
        return (1);

	d.graph = malloc(sizeof(t_graph));
	if (!d.graph)
    	return (free(d.mlx), 1);

    d.win = mlx_new_window(d.mlx, d.win_l, d.win_h, "Hello world!");
    if (!d.win)
        return (free(d.mlx), 1);

    d.img = mlx_new_image(d.mlx, d.win_l, d.win_h);
    d.img_addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, &d.endian);

    my_mlx_pixel_put(&d, 5, 5, 0xf9f9f9);
    my_mlx_pixel_put(&d, 5, 7, 0xf9f9f9);
    my_mlx_pixel_put(&d, 5, 9, 0xf9f9f9);
	
	d.graph->floor = mlx_xpm_file_to_image(d.mlx, "./assets/Floor1.xpm", &d.asset_width, &d.asset_height);
	if (!d.graph->floor)
	{
    	free(d.graph);
    	free(d.mlx);
    	return (1);
	}

	mlx_put_image_to_window(d.mlx, d.win, d.graph->floor, 0, 0);

	mlx_hook(d.win, ON_DESTROY, 0, end_program, &d); // end program on window close
	mlx_hook(d.win, 2, 0, key_handler, &d);

    mlx_loop(d.mlx);
    
    mlx_destroy_window(d.mlx, d.win);
    free(d.mlx);
    return 0;
}
