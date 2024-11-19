/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:20:58 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/19 14:19:01 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "printf/include/ft_printf.h"
#include "printf/libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2

// RND

# ifndef MAPL
#  define MAPL 40 //  max  80 recommended 40
# endif

# ifndef MAPH
#  define MAPH 40 // max 43 recommended 40
#endif

# ifndef STARTX
#  define STARTX 2
#endif

# ifndef STARTY
#  define STARTY 2
#endif

// DATA

typedef struct s_graph
{
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit_closed;
	void	*exit_opened;
	void	*player;
	void	*monster;
}	t_graph;

typedef struct s_data2 {
	int		player_y;
	int		player_x;
	int		all_c_found;
	int		nbr_of_c;
	int		player_found;
	int		exit_found;
	int		exit_y;
	int		exit_x;
	int		total_moves;
}	t_data2;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_l;
	int		win_h;
	int		asset_width;
	int		asset_height;
	char	**map;
	int		map_h;
	int		map_l;

	t_data2	*d2;
	t_graph	*graph;
}	t_data;

// MAIN
void	my_mlx_pixel_put(t_data *d, int x, int y, int color);
int		key_handler(int key, t_data *d);
int		end_program(t_data *d);
int		start_hook(t_data *d);
int		main(int argc, char **argvs);

// INIT
int	init_data2(t_data *d);
int		init_all(t_data *d, char **argv);
int		init_struct(t_data *d);
int		init_graph(t_data *d);
int		init_mlx(t_data *d);
int		init_assets(t_data *d);

// MAP
int		count_all_rows(t_data *d, char *map_str);
int		create_map(t_data *d, char *map_str);
int		get_map(t_data *d, char *map_name);
void	free_map(t_data *d);
int		check_map(t_data *d);
int		fill_map(t_data *d, int y, int x, char c);

// RENDER
void	aff_asset(t_data *d, int y, int x);
int render_map(t_data *d);

// MOVE
int	get_events(t_data *d);
int	move(t_data *d, int way);

// RND
int get_rnd_loop(t_data *d);
int	get_rnd_map(t_data *d);
int	create_rnd_map(t_data *d);
int floodfill(char **map,int  x,int y);
void fill_rnd(char **map);
void fill_map_rnd(char **map);
void fill_walls(char **map);
void replace_f(t_data *d);

// DEBUG
int		print_key_debug(int key, t_data *d);
void	print_map_debug(t_data *d);

// UTILS
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_itoa(int n);

// GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_stat(char *s1, int c);
char		*until_nl(char *line, int freeline);
char		*after_nl(char *line);
char		*get_next_line2(int chars_read, char *tmp);
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			checkline(char *line);

#endif
