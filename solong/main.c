/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:19:56 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/18 15:58:41 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (key == 53 || key == 12)
	{
		mlx_hook(d->win, 0, 0, close, &d);
		return(end_program(d));
	}
	else if (key == UP)
		move(d, UP);
	else if (key == LEFT)
		move(d, LEFT);
	else if (key == DOWN)
		move(d, DOWN);
	else if (key == RIGHT)
		move(d, RIGHT);
	
	render_map(d);
	return(1);
}

//free everything here
int	end_program(t_data *d)
{
	free(d->graph);
	free(d->mlx);
	free_map(d);
	//mlx_destroy_image(d->mlx, d->img); Should destroy all created images
	mlx_destroy_window(d->mlx, d->win);
	free(d);
	exit(0);
}

int	start_hook(t_data *d)
{
	mlx_hook(d->win, ON_DESTROY, 0, end_program, d); // end program on window close
	mlx_hook(d->win, 2, 0, key_handler, d);
	mlx_loop(d->mlx);
	return(1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return(0);

	t_data	*d = malloc(sizeof(t_data)); // + (sizeof(void*) * 3) + (sizeof(int) * 15) + (sizeof(char**)) + sizeof(t_graph));
	if (!d)
		return(end_program(d), 0);
	if (!init_all(d, argv))
		return(0);

	print_map_debug(d);

	if (!check_map(d))
		return(end_program(d), 0);
	render_map(d);

	start_hook(d);

	mlx_destroy_window(d->mlx, d->win);
	free(d->mlx);
	return 0;
}