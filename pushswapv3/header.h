/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:40:05 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/11 16:56:29 by lfaure           ###   ########.fr       */
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

typedef struct s_tree
{
	int		lvl;
	int		*st_a;
	int		*st_a_optid;
	int		size_a;
	int		*st_b;
	int		*st_b_optid;
	int		size_b;
	unsigned long	diff;
	struct	s_tree *prev;
	struct	s_tree *sa;
	struct	s_tree *sb;
	struct	s_tree *ss;
	struct	s_tree *pa;
	struct	s_tree *pb;
	struct	s_tree *ra;
	struct	s_tree *rb;
	struct	s_tree *rr;
	struct	s_tree *rra;
	struct	s_tree *rrb;
	struct	s_tree *rrr;
} t_tree;

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

// UTILS
int		get_stack_av(int ac, char **av, int **st);
int		get_stack_split(char *s, int **st);
int		get_stack(int ac, char **av, int **st);
void	print_st(int size, int **st);
void	free_st(int **st);
int		check_st_double(int size, int **st);
int		check_args_numeric(int ac, char **av);

// DIFF
void	set_optid(int size, int **st, int **st_optid);
int	get_diff_a(int size, int **st_optid);
int	get_diff_b(int size, int **st_optid);
int get_tot_diff(int size_a, int size_b, int **st_a_optid, int **st_b_optid);

// TREE
void	init_tree(t_tree *branch, int ac, char **av);
void	free_branch(t_tree **branch);
void	print_branch(t_tree *branch);

#endif
