#include "so_long.h"

int count_all_rows(t_data *d, char *map_str)
{
	int i = 0;
	int row_length = 0;
	int	row_nbr = 0;
	d->map_l = 0;
	while(map_str[i])
	{
		while(map_str[i] && map_str[i] != '\n')
		{
			i++;
			row_length++;
		}
		if (row_nbr == 0)
			d->map_l = row_length;
		else if (d->map_l != row_length)
			return(0);
		row_nbr++;
		i++;
		row_length = 0;
	}
	d->map_h = row_nbr;
	return(1);
}

int	create_map(t_data *d, char *map_str)
{
	int i = 0;
	int y = 0;
	int x = 0;
	d->map = malloc(sizeof(char*) * (d->map_h + 1));
	if (!d->map)
		return(0);
	while(y < d->map_h)
	{
		d->map[y] = malloc(sizeof(char) * (d->map_l + 1)); // Segfault here on sd pass TODO
		if (!d->map[y])
			return(free_map(d), 0);
		y++;
	}
	d->map[y] = malloc(1);
	if (!d->map[y])
		return(free_map(d), 0);
	d->map[y] = 0;
	y = 0;
	while(map_str[i] && d->map[y] && d->map[y][x])
	{
		if (map_str[i] != '\n')
			d->map[y][x++] = map_str[i];
		else
		{
			d->map[y][x] = 0;
			y++;
			x = 0;
		}
		i++;
	}
	free(map_str);
	map_str = NULL;
	return(1);
}

int get_map(t_data *d, char *map_name)
{
	char *tmp = NULL;
	char *map_str = NULL;
	char *addr = NULL;
	int fd = open(map_name, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		return(0);
	while(tmp)
	{
		addr = map_str;
		map_str = ft_strjoin(map_str, tmp);
		free(addr);
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (!count_all_rows(d, map_str))
		return(free(map_str), 0);
	return(create_map(d, map_str));
}

void free_map(t_data *d)
{
    int y = 0;
    while (d->map[y])
    {
        free(d->map[y]);  // Free each row
        y++;
    }
    free(d->map);  // Free the map array
}

int	check_map(t_data *d)
{
	int y = 0;
	int x = 0;
	int player_found;
	player_found = 0;
	while(d->map[y]) // find loc of player add more checks TODO
	{
		while(d->map[y][x])
		{
			if (d->map[y][x] == 'P')
			{
				player_found++;
				d->player_y = y;
				d->player_x = x;
				d->map[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (!player_found)
		return(printf("no player was found"), 0);
	else if (player_found > 1)
		return(printf("too many players"), 0);
	else
		return(1);
}
