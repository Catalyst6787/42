/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:48 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/18 12:03:10 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *d, int way)
{
	if (way == UP && d->map[d->d2->player_y - 1][d->d2->player_x] != '1')
		d->d2->player_y--;
	else if (way == DOWN && d->map[d->d2->player_y + 1][d->d2->player_x] != '1')
		d->d2->player_y++;
	else if(way == LEFT && d->map[d->d2->player_y][d->d2->player_x - 1] != '1')
		d->d2->player_x--;
	else if(way == RIGHT && d->map[d->d2->player_y][d->d2->player_x + 1] != '1')
		d->d2->player_x++;
}