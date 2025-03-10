#include "header.h"

int	main(int ac, char **av)
{
	// TODO -> SHOULD rewrite existing fn to use tail instaed of modyfing the stack

	int	i;

	if (ac < 2)
		return (ft_printf("Not enough arguments"), 0);
	t_stack	*st_og;
	st_og = lst_new(atoi(av[1]));
	if (!st_og)
		return (printf("Memory allocation failed\n"), 0);
	i = 2;
	while (av[i])
	{
		lst_add_back(st_og, lst_new(ft_atoi(av[i])));
		i++;
	}
	t_stack *st_a = copy_list(st_og);
	t_stack *st_b = NULL;
	
	//ft_printf("st_a:\n");
	//print_list(st_a);
	
	
	//swap_sort(&st_a, &st_b);
	dmb_sort(&st_a);
	
	//ft_printf("st_a:\n");
	//print_list(st_a);

	//ft_printf("\n\n\n");
	//ft_printf("st_og:\n");
	//print_list(st_og);
	//ft_printf("st_a:\n");
	//print_list(st_a);
	//ft_printf("st_b:\n");
	//print_list(st_b);

	//ft_printf("Check Sort\n");
	//ft_printf("st_og: %d\n", check_sort(st_og));
	//ft_printf("st_a: %d\n", check_sort(st_a));
	//ft_printf("st_b: %d\n", check_sort(st_b));


	//ft_printf("rev printed lists to debug:\n");
	//ft_printf("st_og:\n");
	//rev_print_list(st_og);
	//ft_printf("st_a:\n");
	//rev_print_list(st_a);
	//ft_printf("st_b:\n");
	//rev_print_list(st_b);

	free_list(st_og);
	free_list(st_a);
	free_list(st_b);
	return (1);
}