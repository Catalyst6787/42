/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:48 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/19 13:50:43 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_data *d, int way)
{
	if (way == UP && d->map[d->d2->player_y - 1][d->d2->player_x] != '1')
		return(d->d2->player_y--, 1);
	else if (way == DOWN && d->map[d->d2->player_y + 1][d->d2->player_x] != '1')
		return(d->d2->player_y++, 1);
	else if(way == LEFT && d->map[d->d2->player_y][d->d2->player_x - 1] != '1')
		return(d->d2->player_x--, 1);
	else if(way == RIGHT && d->map[d->d2->player_y][d->d2->player_x + 1] != '1')
		return(d->d2->player_x++, 1);
	else
		return(0);
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
		return(ft_printf("--- You Win!! ---\n--- Game Over ---\n"), 0);
	}
	return(1);
}