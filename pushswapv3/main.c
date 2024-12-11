#include "header.h"

int	main(int ac, char **av)
{
	int *st;
	int *st_optid;
	int size;
	st = NULL;
	size = 0;

	if (ac < 2)
		return(ft_putstr_fd("Error, no arguments\n", 2), 0); // TMP change error msg
	if (!check_args_numeric(ac, av))
		return(ft_putstr_fd("Error, non numeric argument\n", 2), 0); // TMP change error msg
	size = get_stack(ac, av, &st);
	if (!check_st_double(size, &st))
		return(free_st(&st), ft_putstr_fd("Error, double in list\n", 2), 0); // TMP change error msg
	st_optid = malloc(sizeof(int) * size);
	set_optid(size, &st, &st_optid);
	


	ft_printf("st_optid:\n");
	print_st(size, &st_optid);
	ft_printf("diff:\n");
	ft_printf("%d\n", get_diff_b(size, &st_optid));
	free_st(&st_optid);

	ft_printf("st:\n");
	print_st(size, &st);
	free_st(&st);
}
