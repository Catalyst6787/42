/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:40:05 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/27 17:57:58 by lfaure           ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


// UTILS
t_stack	*lst_new(int content);
t_stack	*lst_add_back(t_stack *st, t_stack *elem);
void free_list(t_stack *list);
void print_list(t_stack *list);
t_stack *copy_list(t_stack *list);
void	lst_add_front(t_stack **lst, t_stack *new);
t_stack	*del_head(t_stack *list);
void rev_print_list(t_stack *list);
int	check_sort(t_stack *st);
int	is_highest(t_stack *st, int n);
int	is_lowest(t_stack *st, int n);
int	align(t_stack **st);


//OPERATIONS
int	swap(t_stack *st);
int	sswap(t_stack *st_a, t_stack *st_b);
int	push(t_stack **st_a, t_stack **st_b);
int	rotate(t_stack *st);
int	r_rotate(t_stack *st_a, t_stack *st_b);
int	rev_rotate(t_stack **st);
int r_rev_rotate(t_stack *st_a, t_stack *st_b);

// SORT
int swap_sort(t_stack **st_a, t_stack **st_b);
int	dmb_sort(t_stack **st_a);

// MAIN
int		main(int ac, char **av);


// GNL

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
