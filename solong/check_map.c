/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:27:44 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 16:58:14 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	which_feature(t_data *d, char c, int y, int x)
{
	if (c == 'P')
	{
	d->d2->player_found++;
	d->d2->player_y = y;
	d->d2->player_x = x;
	d->map[y][x] = '0';
	}
	else if (c == 'E')
		d->d2->exit_found++;
	else if (c == 'C')
		d->d2->nbr_of_c++;
	else if (c == 'M')
		d->d2->monster_found++;
	else if (c != '1' && c != '0')
		return (0);
	return (1);
}

int	count_features(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			if (!which_feature(d, d->map[y][x], y, x))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

static int	check_edges2(t_data *d, int x)
{
	while (d->map[0] && d->map[0][x])
	{
		if (d->map[0][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (d->map[d->map_h - 1] && d->map[d->map_h - 1][x])
	{
		if (d->map[d->map_h - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_edges(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (d->map[y] && d->map[y][0])
	{
		if (d->map[y][0] != '1')
			return (0);
		y++;
	}
	y = 0;
	while (d->map[y] && d->map[y][d->map_l - 1])
	{
		if (d->map[y][d->map_l - 1] != '1')
			return (0);
		y++;
	}
	if (!check_edges2(d, x))
		return (0);
	return (1);
}

int	check_map(t_data *d)
{
	if (!count_features(d))
		return (ft_printf("map contains unknow char\n"), 0);
	else if (!d->d2->player_found)
		return (ft_printf("no player was found\n"), 0);
	else if (d->d2->player_found > 1)
		return (ft_printf("too many players\n"), 0);
	else if (!d->d2->exit_found)
		return (ft_printf("no exit was found\n"), 0);
	else if (d->d2->monster_found > 1)
		return (ft_printf("More than one Monster\n"), 0);
	else if (d->d2->exit_found > 1)
		return (ft_printf("too many exits\n"), 0);
	else if (d->d2->nbr_of_c <= 0)
		return (ft_printf("no collectibles on map\n"), 0);
	else if (!check_edges(d))
		return (ft_printf("Missing Wall around map\n"), 0);
	else if (!floodfill(d->map, d->d2->player_y, d->d2->player_x))
		return (ft_printf("Player can't reach exit\n"), 0);
	else
	{
		replace_f(d);
		return (1);
	}
}
