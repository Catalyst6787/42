/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:48 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 14:35:01 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_data *d, int way)
{
	if (way == UP && d->map[d->d2->player_y - 1][d->d2->player_x] != '1')
		return (d->d2->player_y--, 1);
	else if (way == DOWN && d->map[d->d2->player_y + 1][d->d2->player_x] != '1')
		return (d->d2->player_y++, 1);
	else if (way == LEFT && d->map[d->d2->player_y][d->d2->player_x - 1] != '1')
		return (d->d2->player_x--, 1);
	else if (way == RIGHT
		&& d->map[d->d2->player_y][d->d2->player_x + 1] != '1')
		return (d->d2->player_x++, 1);
	else
		return (0);
}

int	get_events(t_data *d)
{
	if (d->map[d->d2->player_y][d->d2->player_x] == 'C')
	{
		d->map[d->d2->player_y][d->d2->player_x] = '0';
		d->d2->nbr_of_c--;
	}
	if (d->map[d->d2->player_y][d->d2->player_x] == 'E' && d->d2->nbr_of_c == 0)
	{
		return (ft_printf("--- You Win!! ---\n--- Game Over ---\n"), 0);
	}
	return (1);
}

int	move_monster(t_data *d, int y, int x)
{
	if (d->d2->player_y == y && d->d2->player_x == x)
		return (1);
	else if ((d->d2->player_y - 1 == y && d->d2->player_x == x)
		|| (d->d2->player_x - 1 == x && d->d2->player_y == y)
		|| (d->d2->player_y + 1 == y && d->d2->player_x == x)
		|| (d->d2->player_x + 1 == x && d->d2->player_y == y))
		return (1);
	else if (d->d2->player_y > y && d->map[y + 1][x] == '0')
		return (d->map[y + 1][x] = 'M', d->map[y][x] = '0', 0);
	else if (d->d2->player_y < y && d->map[y - 1][x] == '0')
		return (d->map[y - 1][x] = 'M', d->map[y][x] = '0', 0);
	else if (d->d2->player_x > x && d->map[y][x + 1] == '0')
		return (d->map[y][x + 1] = 'M', d->map[y][x] = '0', 0);
	else if (d->d2->player_x < x && d->map[y][x - 1] == '0')
		return (d->map[y][x - 1] = 'M', d->map[y][x] = '0', 0);
	return (0);
}

int	handle_monster(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			if (d->map[y][x] == 'M')
				return (move_monster(d, y, x));
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
