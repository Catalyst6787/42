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

typedef struct s_ops
{
	int	op;
	struct s_ops *next;
} t_ops;

typedef struct	s_data
{
	int *st_a;
	int size_a;
	int *st_b;
	int size_b;
	struct s_ops *ops;
} t_data;

// UTILS
int		get_stack_av(int ac, char **av, int **st);
int		get_stack_split(char *s, int **st);
int		get_stack(int ac, char **av, int **st);
void	print_st(int size, int **st);
void	free_st(int **st);
int		check_st_double(int size, int **st);
int		check_args_numeric(int ac, char **av);
void	copy_st(int size, int **st, int **st_copy);
void	copy_st_malloc(int size, int **st, int **st_copy);
void	printop(int op, t_data *d);
void	print_all_ops(t_data *d);
t_ops	*lstnew_ops(int op);
void	lstadd_back_ops(t_ops **lst, t_ops *new);
void	lst_printop(int op);
void	free_ops(t_data *d);

// OPTID
void	set_optid(int size, int **st, int **st_optid);


// OPERATIONS

void	swap(int **st, int size);
void	rotate(int **st, int size);
void	rev_rotate(int **st, int size);
void	push(int **st_from, int *size_from, int **st_to, int *size_to);

// SOLVE
void	push_to_b(t_data *d);
void	push_to_a(t_data *d);
//void	solve_for_3(int	**st_a, int *size_a);
int	get_min(int **st, int size);
int	get_max(int **st, int size);
int	find_cheapest(int **st_a, int size_a, int **st_b, int size_b);
int	cost_to_top(int **st, int size, int id);
int	op_to_top(int **st, int size, int id);
int	put_to_top_a(int **st, int size, int id, t_data *d);
int	put_to_top_b(int **st, int size, int id, t_data *d);
int	is_lower(int val, int **st, int size);
int	is_bigger(int val, int **st, int size);
int	find_spot_b(int val, int **st_b, int size);
void	push_cheapest_to_b(int cheapest, t_data *d);

#endif
