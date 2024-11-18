/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:18 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/18 15:31:27 by lfaure           ###   ########.fr       */
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
	//printf("%d\n", (rand() % 5));
	(void)map;

	int y = 1;
	int x = 1;
	while(y < MAPH - 1)
	{
		while(x < MAPL - 1 && map[y][x] != 'P')
		{
			if ((rand() % 4) == 3)
				map[y][x] = '1';
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
	if (map[y][x] != 'P')
		map[y][x] = 'F';
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
			x++;
		}
		x = 0;
		y++;
	}
}

int	get_rnd_map(t_data *d)
{

	create_rnd_map(d);

	d->d2->exit_y = 5;
	d->d2->exit_x = 5;

	printf("exit is located at coordinates y = %d, x = %d.\n\n", d->d2->exit_y, d->d2->exit_x);
	//print_map(map);
	//printf("\n");
	fill_map_rnd(d->map);
	print_map_debug(d);
	printf("\n");
	fill_walls(d->map);
	print_map_debug(d);
	printf("\n");
	fill_rnd(d->map);
	print_map_debug(d);
	printf("\n");
	d->map[STARTY][STARTX] = 'P';
	d->map[MAPH - STARTY - 1][MAPL - STARTX - 1] = 'E'; // Exit in bottom right
	d->map[STARTY + 2][STARTX + 2] = 'C';
	//d->map[MAPL / 2)][MAPH / 2)] = 'E'; // exit in middle
	print_map_debug(d);
	
	printf("%d\n", floodfill(d->map, STARTY, STARTX));
	replace_f(d);
	print_map_debug(d);
	d->map_h = MAPH;
	d->map_l = MAPL;
	return(1);
}