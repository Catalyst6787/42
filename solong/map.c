/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:44 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 14:19:47 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_all_rows2(t_data *d, char *map_str, int rl, int rn)
{
	int	i;

	i = 0;
	while (map_str && map_str[i])
	{
		while (map_str[i] && map_str[i] != '\n')
		{
			i++;
			rl++;
		}
		if (rn == 0)
			d->map_l = rl;
		else if (d->map_l != rl)
			return (ft_printf("mismatched row length"), 0);
		rn++;
		if (map_str[i])
			i++;
		rl = 0;
	}
	d->map_h = rn;
	return (1);
}

int	count_all_rows(t_data *d, char *map_str)
{
	int	rl;
	int	rn;

	rl = 0;
	rn = 0;
	d->map_l = 0;
	return (count_all_rows2(d, map_str, rl, rn));
}

int	fill_map(t_data *d, int y, int x, char c)
{
	if (c && c != '\n')
		return (d->map[y][x] = c, 1);
	else
		return (0);
}

static int	create_map2(t_data *d, char *map_str, int y, int x)
{
	int	i;

	i = 0;
	while (d->map[y])
	{
		while (d->map[y][x] && map_str[i] && d->map[y][x] != '\n')
		{
			fill_map(d, y, x, map_str[i]);
			x++;
			i++;
		}
		if (map_str[i] == '\n')
			i++;
		x = 0;
		y++;
	}
	return (1);
}

int	create_map(t_data *d, char *map_str)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!map_str)
		return (0);
	d->map = malloc(sizeof(char *) * (d->map_h + 1));
	if (!d->map)
		return (0);
	d->map[d->map_h] = NULL;
	while (d->map[y])
	{
		d->map[y] = malloc(sizeof(char) * d->map_l + 1);
		if (!d->map[y])
			return (0);
		d->map[y][d->map_l] = '\0';
		y++;
	}
	y = 0;
	return (create_map2(d, map_str, y, x));
}

int	get_map(t_data *d, char *map_name)
{
	char	*tmp;
	char	*map_str;
	char	*addr;
	int		fd;

	tmp = NULL;
	map_str = NULL;
	addr = NULL;
	fd = open(map_name, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		return (0);
	while (tmp)
	{
		addr = map_str;
		map_str = ft_strjoin(map_str, tmp);
		free(addr);
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (!count_all_rows(d, map_str))
		return (0);
	return (create_map(d, map_str));
}

void	free_map(t_data *d)
{
	int	y;

	y = 0;
	while (d->map[y])
	{
		free(d->map[y]);
		y++;
	}
	free(d->map);
}

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
	else if (c != '1' && c != '0' && c != 'M')
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
