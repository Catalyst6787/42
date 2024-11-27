#include "header.h"

int	main(int ac, char **av)
{
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
	
	//swap(st_a);
	//sswap(st_a, st_b);
	//push(&st_a, &st_b);
	//rotate(st_a);
	//rev_print_list(st_og);
	revrotate(st_a);


	ft_printf("st_og:\n");
	print_list(st_og);
	ft_printf("st_a:\n");
	print_list(st_a);
	ft_printf("st_b:\n");
	print_list(st_b);

	free_list(st_og);
	free_list(st_a);
	free_list(st_b);
	return (1);
}