/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:44 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 14:29:35 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		return (printf("Provided map does not exist\n"), 0);
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
