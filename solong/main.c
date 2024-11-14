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
	free(d->mlx);
	free_map(d);
	//mlx_destroy_image(d->mlx, d->img); Should destroy all created images
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
}

int	main(void)
{
    t_data  d;
	if(!init_struct(&d))
		return(end_program(&d), 0);
	if(!init_mlx(&d))
		return(end_program(&d), 0);
	if(!get_map(&d, "maps/map1.ber"))
		return(end_program(&d), 0);
	if(!init_assets(&d))
		return(end_program(&d), 0);
	
	render_map(&d);

	mlx_hook(d.win, ON_DESTROY, 0, end_program, &d); // end program on window close
	mlx_hook(d.win, 2, 0, print_key_debug, &d);

    mlx_loop(d.mlx);
    
    mlx_destroy_window(d.mlx, d.win);
    free(d.mlx);
    return 0;
}
