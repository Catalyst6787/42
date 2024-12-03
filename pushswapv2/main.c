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

// CURENTLY WHEN BACKTRACKING, 
// ONLY MODIFIED LISTS ARE COPIED BEFORE PUTTING THEM IN THE NEXT BRANCH. 
// IF ENCOUNTERING PROBLEMS TRY CHANGING THAT BEHAVIOUR
int	main(int ac, char **av)
{
	if (ac < 2)
		return(ft_printf("Not enough arguments.\n"), 0);
	t_stack *st_og;
	t_stack *st_a;
	t_stack *st_b;

	st_og = NULL;
	st_a = NULL;
	st_b = NULL;
	if (!get_list(&st_og, av))
		return(0);
	set_optid(&st_og);
	ft_printf("\nst_og:\n");
	print_lst(&st_og);

	ft_printf("\nrev_st_og:\n");
	rev_print_lst(&st_og);

	lst_copy(&st_og, &st_a);

	swap(&st_a);

	ft_printf("\nst_a:\n");
	print_lst(&st_a);
	ft_printf("\nrev_st_a:\n");
	rev_print_lst(&st_a);
	ft_printf("\ndiff: %d\n", get_diff_a(&st_a));

	push(&st_a, &st_b);
	push(&st_a, &st_b);
	push(&st_a, &st_b);
	push(&st_a, &st_b);
	push(&st_a, &st_b);

	ft_printf("\nst_b:\n");
	print_lst(&st_b);
	ft_printf("\ndiff: %d\n", get_diff_b(&st_b));

	ft_printf("\nrev_st_b:\n");
	rev_print_lst(&st_b);
	//ft_printf("\nst_a:\n");
	//print_lst(&st_a);

	//ft_printf("\nst_b:\n");
	//print_lst(&st_b);

	free_lst(&st_og);
	free_lst(&st_a);
	free_lst(&st_b);
	return (1);
}
