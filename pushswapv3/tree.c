#include "header.h"

void	init_tree(t_tree *branch, int ac, char **av)
{
	branch->lvl = 0;
	branch->st_a = NULL;
	branch->size_a = get_stack(ac, av, &branch->st_a);
	branch->st_a_optid = NULL;
	set_optid(branch->size_a, &branch->st_a, &branch->st_a_optid);
	branch->st_b = NULL;
	branch->st_b_optid = NULL;
	branch->size_b = 0;
	branch->diff = get_tot_diff(branch->size_a, branch->size_b, &branch->st_a_optid, &branch->st_b_optid);
	branch->prev = NULL;
	branch->sa = NULL;
	branch->sb = NULL;
	branch->ss = NULL;
	branch->pa = NULL;
	branch->pb = NULL;
	branch->ra = NULL;
	branch->rb = NULL;
	branch->rr = NULL;
	branch->rra = NULL;
	branch->rrb = NULL;
	branch->rrr = NULL;
}

void free_branch(t_tree **branch)
{
    if (branch && *branch)
	{
        free_st(&(*branch)->st_a);
        (*branch)->st_a = NULL;
        free_st(&(*branch)->st_a_optid);
        (*branch)->st_a_optid = NULL;
        free_st(&(*branch)->st_b);
        (*branch)->st_b = NULL;
        free_st(&(*branch)->st_b_optid);
        (*branch)->st_b_optid = NULL;
        free(*branch);
        *branch = NULL;
    }
}

void	print_branch(t_tree *branch)
{
	if (!branch)
		return (ft_printf("NULL branch!\n"), (void)NULL);
	ft_printf("Branch level: %d\n", branch->lvl);

	ft_printf("st_a of size: %d\n", branch->size_a);
	ft_printf("st_a (value): \n");
	print_st(branch->size_a, &branch->st_a);
	ft_printf("st_a (optid): \n");
	print_st(branch->size_a, &branch->st_a_optid);

	ft_printf("st_b of size: %d\n", branch->size_b);
	ft_printf("st_b (value): \n");
	print_st(branch->size_b, &branch->st_b);
	ft_printf("st_b (optid): \n");
	print_st(branch->size_b, &branch->st_b_optid);

	ft_printf("diff of stacks: %d\n", branch->diff);
}
