#include "header.h"

int	main(int ac, char **av)
{
	int tmp;

	if (ac < 2)
		return(ft_putstr_fd("Error, no arguments\n", 2), 0); // TMP change error msg
	if (!check_args_numeric(ac, av))
		return(ft_putstr_fd("Error, non numeric argument\n", 2), 0); // TMP change error msg
	t_tree	*tree;
	tree =  (t_tree *)malloc(sizeof(t_tree));
	if (!tree)
		return(ft_putstr_fd("Error\n", 2), 0);
	tmp = init_tree(tree, ac, av);
	if (tmp == -1)
		return (free_st(&tree->st_a), free(tree), 0);
	else if (tmp == 0)
		return(free(tree), 0);
	if (tree->size_a < 2)
		return(free_tree(&tree), ft_printf("only one element in list\n"), 0);
	
	//ft_printf("\nROOT:\n\n");
	//print_branch(tree);
	//init_branch(tree, &tree->sa, PB);
	//ft_printf("\nTEST SA:\n\n");
	//print_branch(tree->sa);
	
	branch_out(&tree, 1);

	print_tree(&tree);
	free_tree(&tree);
}
