/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:13:20 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 15:18:50 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_walls(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < MAPH)
		map[y++][0] = '1';
	y = 0;
	while (y < MAPH)
		map[y++][MAPL - 1] = '1';
	y = 0;
	while (x < MAPL)
		map[0][x++] = '1';
	x = 0;
	while (x < MAPL)
		map[MAPH - 1][x++] = '1';
}

void	fill_map_rnd(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < MAPH)
	{
		while (x < MAPL && map[y][x] != 'P')
			map[y][x++] = '0';
		x = 0;
		y++;
	}
}

void	fill_rnd(char **map)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (y < MAPH - 1)
	{
		while (x < MAPL - 1 && map[y][x] != 'P')
		{
			if ((rand() % 4) == 1)
				map[y][x] = '1';
			else if ((rand() % 100) == 1)
				map[y][x] = 'C';
			x++;
		}
		x = 1;
		y++;
	}
}

int	create_rnd_map(t_data *d)
{
	int	y;

	y = 0;
	d->map = malloc(sizeof(char *) * (MAPH + 1));
	if (!d->map)
		return (0);
	d->map[MAPH] = NULL;
	while (d->map[y])
	{
		d->map[y] = malloc(sizeof(char) * MAPL + 1);
		if (!d->map[y])
			return (0);
		d->map[y][MAPL] = '\0';
		y++;
	}
	return (1);
}

void	replace_f(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			if (d->map[y][x] == 'F')
				d->map[y][x] = '0';
			else if (d->map[y][x] == 'X')
				d->map[y][x] = 'C';
			x++;
		}
		x = 0;
		y++;
	}
}
