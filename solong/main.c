/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:19:56 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 15:10:02 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int key, t_data *d)
{
	if (key == 53 || key == 12)
	{
		mlx_hook(d->win, 0, 0, close, &d);
		return (end_program(d));
	}
	else if (key == UP)
		d->d2->total_moves += move(d, UP);
	else if (key == LEFT)
		d->d2->total_moves += move(d, LEFT);
	else if (key == DOWN)
		d->d2->total_moves += move(d, DOWN);
	else if (key == RIGHT)
		d->d2->total_moves += move(d, RIGHT);
	if (!get_events(d))
		return (end_program(d), 0);
	if (handle_monster(d))
		return (ft_printf("Eaten by monster! Game Over!"), end_program(d), 0);
	render_map(d);
	ft_printf("Nbr of moves: %d\n", d->d2->total_moves);
	mlx_string_put(d->mlx, d->win, 10, 10, 0, "NUMBER OF MOVES:");
	mlx_string_put(d->mlx, d->win, 10, 20, 0, ft_itoa(d->d2->total_moves));
	return (1);
}

void	free_assets(t_data *d)
{
	free(d->graph->floor);
	free(d->graph->player);
	free(d->graph->wall);
	free(d->graph->collect);
	free(d->graph->exit_closed);
	free(d->graph->exit_opened);
	free(d->graph->monster);
}

//free everything here
int	end_program(t_data *d)
{
	free_assets(d);
	free(d->graph);
	free(d->d2);
	free_map(d);
	mlx_destroy_window(d->mlx, d->win);
	free(d->mlx);
	free(d);
	exit(0);
}

int	start_hook(t_data *d)
{
	mlx_hook(d->win, ON_DESTROY, 0, end_program, d);
	mlx_hook(d->win, 2, 0, key_handler, d);
	mlx_loop(d->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (argc < 2)
		return (0);
	if (!d)
		return (end_program(d), 0);
	if (!init_all(d, argv))
		return (0);
	print_map_debug(d);
	if (!check_map(d))
		return (end_program(d), 0);
	render_map(d);
	start_hook(d);
	mlx_destroy_window(d->mlx, d->win);
	free(d->mlx);
	return (0);
}
