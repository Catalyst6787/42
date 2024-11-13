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

int	key_handler(int key, t_data *d)
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

//free everything here
int end_program(t_data *d)
{
	free(d->graph);
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
}

int	get_map(t_data *d, char *map_name)
{
	char	*tmp;
	int 	i = 0;
	int 	x = 0;
	int 	y = 0;
	int		fd;

	fd = open(map_name, O_RDONLY);
	d->map = malloc(sizeof(char**));
	tmp = get_next_line(fd);
	while(tmp[i])
	{
		if(tmp[i] == '\n')
		{
			y++;
			d->map[y] = malloc(sizeof(char*));
			if (!d->map[y])
				return(free(d->map), end_program(d), 0);
			x = 0;
		}
		else
		{
			x++;
			d->map[x][y] = (char)malloc(sizeof(char));
			if (!d->map[y][x])
				return(free(d->map), end_program(d), 0);
			d->map[x][y] = tmp[i];
		}
		i++;
		if(!tmp[i])
		{
			free(tmp);
			tmp = get_next_line(fd);
			i = 0;
		}
	}
	return(free(tmp), 1);
}

void	print_map(t_data *d)
{
	int x = 0;
	int y = 0;
	while(d->map[y])
	{
		while(d->map[y][x])
			printf("%d", d->map[x++][y]); // TODO replace printf w ft_printf
		x = 0;
		y++;
	}
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
	
	get_map(&d, "assets/map1.ber");
	print_map(&d);

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
