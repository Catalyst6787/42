/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:18 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/19 13:50:29 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void fill_walls(char **map)
{
	int y = 0;
	int x = 0;
	while(y < MAPH)
		map[y++][0] = '1';
	y = 0;
	while(y < MAPH)
		map[y++][MAPL - 1] = '1';
	y = 0;
	while(x < MAPL)
		map[0][x++] = '1';
	x = 0;
	while(x < MAPL)
		map[MAPH - 1][x++] = '1';
}

void fill_map_rnd(char **map)
{
	int x = 0;
	int y = 0;
	while(y < MAPH)
	{
		while(x < MAPL && map[y][x] != 'P')
			map[y][x++] = '0';
		x = 0;
		y++;
	}
}

void fill_rnd(char **map)
{
	srand(time(NULL));   // Initialization, should only be called once.
	//ft_printf("%d\n", (rand() % 5));
	(void)map;

	int y = 1;
	int x = 1;
	while(y < MAPH - 1)
	{
		while(x < MAPL - 1 && map[y][x] != 'P')
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

int floodfill(char **map,int  y,int x)
{
	//print_map(map);
	if (map[y][x] == 'E')
		return(1);
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
	else if ((map[y][x - 1] == '0') && (floodfill(map, y, x - 1)))
		return (1);
	else if ((map[y + 1][x] == 'C') && (floodfill(map, y + 1, x)))
		return (1);
	else if ((map[y][x + 1] == 'C') && (floodfill(map, y, x + 1)))
		return (1);
	else if ((map[y - 1][x] == 'C') && (floodfill(map, y - 1, x)))
		return (1);
	else if ((map[y][x - 1] == 'C') && (floodfill(map, y, x - 1)))
		return (1);
	return(0);
}

int	create_rnd_map(t_data *d)
{
	int y = 0;
	
	d->map = malloc(sizeof(char*) * (MAPH + 1));
	if (!d->map)
		return(0);
	d->map[MAPH] = NULL;
	while(d->map[y])
	{
		d->map[y] = malloc(sizeof(char) * MAPL + 1);
		if (!d->map[y])
			return(0);
		d->map[y][MAPL] = '\0';
		y++;
	}
	return(1);
}

void replace_f(t_data *d)
{
	int x = 0;
	int y = 0;
	while(d->map[y])
	{
		while(d->map[y][x])
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

int	get_rnd_map(t_data *d)
{

	if(!create_rnd_map(d))
		return(ft_printf("Couldnt malloc the map"), 0);

	d->d2->exit_y = 5;
	d->d2->exit_x = 5;

	ft_printf("exit is located at coordinates y = %d, x = %d.\n\n", d->d2->exit_y, d->d2->exit_x);
	fill_map_rnd(d->map);
	//print_map_debug(d);
	//ft_printf("\n");
	fill_walls(d->map);
	//print_map_debug(d);
	//ft_printf("\n");
	fill_rnd(d->map);
	//print_map_debug(d);
	//ft_printf("\n");
	
	//d->map[MAPL / 2)][MAPH / 2)] = 'E'; // exit in middle
	//print_map_debug(d);
	
	ft_printf("%d\n", floodfill(d->map, STARTY, STARTX));
	replace_f(d);
	d->map[STARTY][STARTX] = 'P';
	d->map[MAPH - 2][MAPL - 2] = 'E'; // Exit in bottom right
	d->map[STARTY + 2][STARTX + 2] = 'C';
	//print_map_debug(d);
	d->map_h = MAPH;
	d->map_l = MAPL;
	return(1);
}

int get_rnd_loop(t_data *d)
{
	while(get_rnd_map(d) && !check_map(d))
	{
		free_map(d);
		d->d2->exit_found = 0;
		d->d2->nbr_of_c = 0;
		d->d2->player_found = 0;
	}
	d->d2->exit_found = 0;
	d->d2->nbr_of_c = 0;
	return(1);
}