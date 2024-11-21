/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:18 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 17:19:40 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	floodfill2(char **map, int y, int x)
{
	if ((map[y][x - 1] == '0') && (floodfill(map, y, x - 1)))
		return (1);
	else if ((map[y + 1][x] == 'C') && (floodfill(map, y + 1, x)))
		return (1);
	else if ((map[y][x + 1] == 'C') && (floodfill(map, y, x + 1)))
		return (1);
	else if ((map[y - 1][x] == 'C') && (floodfill(map, y - 1, x)))
		return (1);
	else if ((map[y][x - 1] == 'C') && (floodfill(map, y, x - 1)))
		return (1);
	return (0);
}

int	floodfill(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] != 'P' && map[y][x] != 'C')
		map[y][x] = 'F';
	else if (map[y][x] == 'C')
		map[y][x] = 'X';
	if ((map[y + 1][x] == 'E') && (floodfill(map, y + 1, x)))
		return (1);
	else if ((map[y][x + 1] == 'E') && (floodfill(map, y, x + 1)))
		return (1);
	else if ((map[y - 1][x] == 'E') && (floodfill(map, y - 1, x)))
		return (1);
	else if ((map[y][x - 1] == 'E') && (floodfill(map, y, x - 1)))
		return (1);
	else if ((map[y + 1][x] == '0') && (floodfill(map, y + 1, x)))
		return (1);
	else if ((map[y][x + 1] == '0') && (floodfill(map, y, x + 1)))
		return (1);
	else if ((map[y - 1][x] == '0') && (floodfill(map, y - 1, x)))
		return (1);
	else
		return (floodfill2(map, y, x));
}

int	get_rnd_map(t_data *d)
{
	if (!create_rnd_map(d))
		return (ft_printf("Couldnt malloc the map"), 0);
	fill_map_rnd(d->map);
	fill_walls(d->map);
	fill_rnd(d->map);
	floodfill(d->map, STARTY, STARTX);
	replace_f(d);
	d->map[STARTY][STARTX] = 'P';
	d->map[rand() % (MAPH - 2)][rand() % (MAPL - 2)] = 'E';
	d->map[rand() % (MAPH - 2)][rand() % (MAPL - 2)] = 'M';
	d->map_h = MAPH;
	d->map_l = MAPL;
	return (1);
}

int	get_rnd_loop(t_data *d)
{
	while (get_rnd_map(d) && !check_map(d))
	{
		free_map(d);
		d->d2->exit_found = 0;
		d->d2->nbr_of_c = 0;
		d->d2->player_found = 0;
	}
	d->d2->exit_found = 0;
	d->d2->nbr_of_c = 0;
	return (1);
}
