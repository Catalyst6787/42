/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:40:05 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/03 18:05:09 by lfaure           ###   ########.fr       */
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

typedef struct s_tree
{
	int lvl;
	struct s_tree	**prev;
	struct s_stack	**st_a;
	struct s_stack	**st_b;
	int diff;
	struct s_tree	**sa;
	struct s_tree	**sb;
	struct s_tree	**ss;
	struct s_tree	**pa;
	struct s_tree	**pb;
	struct s_tree	**ra;
	struct s_tree	**rb;
	struct s_tree	**rr;
	struct s_tree	**rra;
	struct s_tree	**rrb;
	struct s_tree	**rrr;
}	t_tree;

// UTILS
t_stack *lst_new(int nbr);
int	del_head(t_stack **st);
int	lst_add_back(t_stack **st, t_stack *elem);
int	lst_add_front(t_stack **st, t_stack *elem);
int	print_lst(t_stack **st);
int	rev_print_lst(t_stack **st);
int printf_elem(t_stack *elem);
int free_lst(t_stack **st);
int	size_list(t_stack **st);
int	set_optid(t_stack **st);
int check_doubles(t_stack **st);
t_stack *copy_elem(t_stack *elem);
int	lst_copy(t_stack **st, t_stack **st_copy);
t_stack **lst_copy_new(t_stack **st);


// MAIN
int	get_list(t_stack **st_og, char **av);
int	main(int ac, char **av);
//int	init_elem(t_stack **st);

//OPS
t_stack	**swap(t_stack **st);
t_stack	**rotate(t_stack **st);
t_stack	**rev_rotate(t_stack **st);
int push(t_stack **st_from, t_stack **st_to);

//BACKTRACKING
int	get_diff_a(t_stack **st);
int	get_diff_b(t_stack **st);
int get_tot_diff(t_stack **st_a, t_stack **st_b);
void	init_tree(t_tree **root, t_stack **st_a, t_stack **st_b);
void	free_tree(t_tree **branch);
t_tree	**init_branch(t_tree **prev, t_stack **st_a, t_stack **st_b);
void	branch_out(t_tree **branch, int max);
t_tree **get_best_branch(t_tree **branch);
void	print_branch(t_tree **branch);



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
