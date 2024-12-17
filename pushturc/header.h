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

// OPTID
void	set_optid(int size, int **st, int **st_optid);


// OPERATIONS

void	swap(int **st, int size);
void	rotate(int **st, int size);
void	rev_rotate(int **st, int size);
void	push(int **st_from, int *size_from, int **st_to, int *size_to);


#endif
