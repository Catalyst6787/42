#include "header.h"

int	get_list(t_stack **st_og, char **av)
{
	int	i;

	i = 1;

	while(av[i])
	{
		lst_add_back(st_og, lst_new(ft_atoi(av[i])));
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return(ft_printf("Not enough arguments.\n"), 0);
	t_stack *st_og;
	t_stack *st_a;
	t_stack *st_b;

	if (!get_list(&st_og, av))
		return(0);
	print_lst(&st_og);
	set_optid(&st_og);
	ft_printf("\n");
	print_lst(&st_og);

	ft_printf("size of list is: %d\n", size_list(&st_og));

	free_lst(&st_og);

	print_lst(&st_og);
	(void)st_a;
	(void)st_b;


	return (1);
}