#include "header.h"
#include <time.h>

int	main(int ac, char **av)
{
	time_t start,end; // TESTING
	double dif; // TESTING
	time (&start); // TESTING

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


	solve(&tree, 1);
	//branch_out(&tree, 4);
	//print_branch(*get_best_branch(&tree));
	
	//print_tree(&tree);

	free_tree(&tree);

	time (&end); // TESTING
	dif = difftime (end,start); // TESTING
	printf ("\n\nYour calculations took %.2lf seconds to run.\n", dif ); // TESTING
	
	return (0);
}
/*
time per lvl:

<= 4 : 0s
5 : 1s
6 : 3s
7 : 31s
*/