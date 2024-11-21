/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:29:47 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/21 14:30:51 by lfaure           ###   ########.fr       */
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
