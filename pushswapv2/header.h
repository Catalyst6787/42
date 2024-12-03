/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:40:05 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/03 11:11:56 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include "printf/include/ft_printf.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				id;
	int				optid;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// UTILS
t_stack *lst_new(int nbr);
int	del_head(t_stack **st);
int	lst_add_back(t_stack **st, t_stack *elem);
int	lst_add_front(t_stack **st, t_stack *elem);
int	print_lst(t_stack **st);
int printf_elem(t_stack *elem);
int free_lst(t_stack **st);
int	size_list(t_stack **st);
int	set_optid(t_stack **st);
int check_doubles(t_stack **st);
t_stack *copy_elem(t_stack *elem);
int	lst_copy(t_stack **st, t_stack **st_copy);


// MAIN
int	get_list(t_stack **st_og, char **av);
int	main(int ac, char **av);
int	init_elem(t_stack **st);

//OPS
int	swap(t_stack **st);
int rotate(t_stack **st);
int rev_rotate(t_stack **st);
int push(t_stack **st_from, t_stack **st_to);

//BACKTRACKING
int	get_diff(t_stack **st);


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
