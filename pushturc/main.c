#include "header.h"
#include <time.h>

int	main(int ac, char **av)
{
	int *st_a_value;
	int *st_a;
	int size_a;
	int *st_b;
	int size_b;

	st_a = NULL;
	st_a_value = NULL;
	st_b = NULL;

	if (ac < 2)
		return(ft_putstr_fd("Error, no arguments\n", 2), 0); // TMP change error msg
	if (!check_args_numeric(ac, av))
		return(ft_putstr_fd("Error, non numeric argument\n", 2), 0); // TMP change error msg
	
	size_a = get_stack(ac, av, &st_a_value);
	if (!check_st_double(size_a, &st_a_value))
		return(free_st(&st_a_value), ft_putstr_fd("Error, doubles in list\n", 2), 0);
	set_optid(size_a, &st_a_value, &st_a);
	free_st(&st_a_value);
	size_b = 0;

	ft_printf("\n");

	ft_printf("st_a:\n");
	print_st(size_a, &st_a);
	ft_printf("size st_a: %d\n", size_a);
	ft_printf("st_b:\n");
	print_st(size_b, &st_b);
	ft_printf("size st_a: %d\n", size_b);

	ft_printf("\n");
	push_to_b(&st_a, &size_a, &st_b, &size_b);
	push_to_a(&st_a, &size_a, &st_b, &size_b);
	ft_printf("\n");

	ft_printf("st_a:\n");
	print_st(size_a, &st_a);
	ft_printf("size st_a: %d\n", size_a);
	ft_printf("st_b:\n");
	print_st(size_b, &st_b);
	ft_printf("size st_a: %d\n", size_b);

	ft_printf("\n");

	free_st(&st_a);
	free_st(&st_b);
	(void)size_b;
	(void)st_b;
	return (0);
}
