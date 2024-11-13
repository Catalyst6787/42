#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
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

typedef struct s_graph
{
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit_closed;
	void	*exit_opned;
	void	*player;
}	t_graph;

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
	void	*floor;
	void	*wall;
	void	*player;
	int		asset_width;
	int		asset_height;
	char	**map;
	t_graph	*graph;
}	t_data;

void    my_mlx_pixel_put(t_data *d, int x, int y, int color);
int key_handler(int key, t_data *d);
int end_program(t_data *d);
int main(void);

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
