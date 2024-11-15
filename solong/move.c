#include "so_long.h"

void	move(t_data *d, int way)
{
	if (way == UP && d->map[d->player_y - 1][d->player_x] != '1')
		d->player_y--;
	else if (way == DOWN && d->map[d->player_y + 1][d->player_x] != '1')
		d->player_y++;
	else if(way == LEFT && d->map[d->player_y][d->player_x - 1] != '1')
		d->player_x--;
	else if(way == RIGHT && d->map[d->player_y][d->player_x + 1] != '1')
		d->player_x++;
}