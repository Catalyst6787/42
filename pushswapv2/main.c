#include "header.h"

int	get_list(t_stack **st, char **av)
{
	int	i;

	i = 1;

	while(av[i])
	{
		lst_add_back(st, lst_new(ft_atoi(av[i])));
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
	t_tree **tree;

	st_og = NULL;
	st_a = NULL;
	st_b = NULL;
	if (!get_list(&st_og, av))
		return(0);
	set_optid(&st_og);
	ft_printf("\nst_og:\n");
	print_lst(&st_og);

	lst_copy(&st_og, &st_a);
	ft_printf("\nst_a:\n");
	print_lst(&st_a);
	ft_printf("\ndiff: %d\n", get_diff_a(&st_a));

	
	tree = init_branch(NULL, &st_a, &st_b);
	branch_out(tree, 1);
	ft_printf("best branch:\n");
	print_branch(get_best_branch(tree));
	
	free_tree(tree);
	//free(tree);
	free_lst(&st_og);
	free_lst(&st_a);
	free_lst(&st_b);
	return (1);
}
