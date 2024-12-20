/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:03:37 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/20 15:04:40 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int main2(t_data *d)
{
	d->size_b = 0;
	if (is_sorted_a(&d->st_a, d->size_a))
		return(free_st(&d->st_a), free(d), 0);
	if (d->size_a < 6)
		solve_for_less_than_6(d);
	else
	{
		push_to_b(d);
		align_stack(d);
		push_to_a(d);
	}
	clean_moves(d);
	combine_moves(d);
	print_all_ops(d);
	free_ops(d);
	free_st(&d->st_a);
	free_st(&d->st_b);
	free(d);
	return (0);
}

int	main(int ac, char **av)
{
	t_data *d;
	d =  (t_data *)malloc(sizeof(t_data));
	if (!d)
		return(ft_putstr_fd("Error\n", 2), 0);
	int *st_a_value;
	int error;

	error = 0;
	st_a_value = NULL;
	d->st_a = NULL;
	d->st_b = NULL;
	d->ops = NULL;
	if (ac < 2)
		return(0);
	if (!check_args_numeric(ac, av))
		return(free(d), ft_putstr_fd("Error\n", 2), 0);
	d->size_a = get_stack(ac, av, &st_a_value, &error);
	if (error)
		return (free_st(&st_a_value), free(d), ft_putstr_fd("Error\n", 2), 0);
	if (!check_st_double(d->size_a, &st_a_value))
		return (free_st(&st_a_value), free(d), ft_putstr_fd("Error\n", 2), 0);
	set_optid(d->size_a, &st_a_value, &d->st_a);
	free_st(&st_a_value);
	return (main2(d));	
}


