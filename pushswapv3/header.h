/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:40:05 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/10 12:27:26 by lfaure           ###   ########.fr       */
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
	int *st_a;
	int *st_a_optid;
	int size_a;
	int *st_b;
	int *st_b_optid;
	int size_b;
	struct s_tree *prev;
	struct s_tree *sa;
	struct s_tree *sb;
	struct s_tree *ss;
	struct s_tree *pa;
	struct s_tree *pb;
	struct s_tree *ra;
	struct s_tree *rb;
	struct s_tree *rr;
	struct s_tree *rra;
	struct s_tree *rrb;
	struct s_tree *rrr;
} t_tree;

// UTILS
int	get_stack_av(int ac, char **av, int *st);
int get_stack_split(char *s, int *st);
int get_stack(int ac, char **av, int *st);
void	print_st(int size, int *st);

#endif
