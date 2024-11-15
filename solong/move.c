#include "so_long.h"

void	move(t_data *d, char way)
{
	if (way == 'U' && d->map[d->player_y - 1][d->player_x] != '1')
		d->player_y--;
	else if (way == 'D' && d->map[d->player_y + 1][d->player_x] != '1')
		d->player_y++;
	else if(way == 'L' && d->map[d->player_y][d->player_x - 1] != '1')
		d->player_x--;
	else if(way == 'R' && d->map[d->player_y][d->player_x + 1] != '1')
		d->player_x++;
}