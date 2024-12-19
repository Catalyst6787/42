#include "header.h"
#include <time.h>

int	main(int ac, char **av)
{
	t_data *d;
	d =  (t_data *)malloc(sizeof(t_data));
	if (!d)
			return(ft_putstr_fd("Error\n", 2), 0);

	int *st_a_value;

	st_a_value = NULL;
	d->st_a = NULL;
	d->st_b = NULL;

	if (ac < 2)
		return(ft_putstr_fd("Error, no arguments\n", 2), 0); // TMP change error msg
	if (!check_args_numeric(ac, av))
		return(ft_putstr_fd("Error, non numeric argument\n", 2), 0); // TMP change error msg
	
	d->size_a = get_stack(ac, av, &st_a_value);
	if (!check_st_double(d->size_a, &st_a_value))
		return(free_st(&st_a_value), ft_putstr_fd("Error, doubles in list\n", 2), 0);
	set_optid(d->size_a, &st_a_value, &d->st_a);
	free_st(&st_a_value);
	d->size_b = 0;

	ft_printf("\n");

	ft_printf("st_a:\n");
	print_st(d->size_a, &d->st_a);
	ft_printf("size st_a: %d\n", d->size_a);
	ft_printf("st_b:\n");
	print_st(d->size_b, &d->st_b);
	ft_printf("size st_a: %d\n", d->size_b);

	ft_printf("\n");
	push_to_b(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
	push_to_a(&d->st_a, &d->size_a, &d->st_b, &d->size_b);
	ft_printf("\n");

	ft_printf("st_a:\n");
	print_st(d->size_a, &d->st_a);
	ft_printf("size st_a: %d\n", d->size_a);
	ft_printf("st_b:\n");
	print_st(d->size_b, &d->st_b);
	ft_printf("size st_a: %d\n", d->size_b);

	ft_printf("\n");

	free_st(&d->st_a);
	free_st(&d->st_b);
	free(d);
	return (0);
}
