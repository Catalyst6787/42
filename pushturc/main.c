#include "header.h"
#include <time.h>

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
		return(0); // TMP change error msg
	if (!check_args_numeric(ac, av))
		return(free(d), ft_putstr_fd("Error, non numeric argument\n", 2), 0); // TMP change error msg
	d->size_a = get_stack(ac, av, &st_a_value, &error);
	if (error)
		return(free_st(&st_a_value), free(d), ft_putstr_fd("Error, outside of int\n", 2), 0); // TMP change error msg
	if (!check_st_double(d->size_a, &st_a_value))
		return(free_st(&st_a_value), free(d), ft_putstr_fd("Error, doubles in list\n", 2), 0);
	set_optid(d->size_a, &st_a_value, &d->st_a);
	free_st(&st_a_value);
	d->size_b = 0;

	if (is_sorted_a(&d->st_a, d->size_a))
		return(free_st(&st_a_value), free(d), 0);
	
	if (d->size_a < 6)
		solve_for_less_than_6(d);
	else
	{
		push_to_b(d);
		align_stack(d);
		push_to_a(d);
	}
	ft_printf("\n");

	ft_printf("st_a:\n");
	print_st(d->size_a, &d->st_a);
	ft_printf("size st_a: %d\n", d->size_a);
	ft_printf("st_b:\n");
	print_st(d->size_b, &d->st_b);
	ft_printf("size st_a: %d\n", d->size_b);

	ft_printf("\n");
	
	
	clean_moves(d);
	combine_moves(d);
	print_all_ops(d);

	free_ops(d);
	free_st(&d->st_a);
	free_st(&d->st_b);
	free(d);
	return (0);
}


