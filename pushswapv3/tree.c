#include "header.h"

int	init_tree(t_tree *branch, int ac, char **av)
{
	if (!branch)
		return((void)ft_printf("tried to init tree on NULL branch\n"), 0);
	branch->lvl = 0;
	branch->st_a = NULL;
	branch->size_a = get_stack(ac, av, &branch->st_a);
	if (!check_st_double(branch->size_a, &branch->st_a))
		return(ft_putstr_fd("Error, double in stack\n", 2), -1);
	branch->st_a_optid = NULL;
	set_optid(branch->size_a, &branch->st_a, &branch->st_a_optid);
	branch->st_b = NULL;
	branch->st_b_optid = NULL;
	branch->size_b = 0;
	branch->diff = get_tot_diff(branch->size_a, branch->size_b, &branch->st_a_optid, &branch->st_b_optid);
	branch->prev = NULL;
	set_subbranches_to_NULL(&branch);
	return(1);
}

void	init_branch(t_tree *prev, t_tree **br, int op)
{
	(void)op;
	if (!prev)
		return((void)ft_printf("tried to init branch with NULL prev\n"));
	if (!op_possible(prev, op))
		return(*br = NULL, (void)ft_printf("tried init branch on impossible op\n"));
	*br =  (t_tree *)malloc(sizeof(t_tree));
	(*br)->lvl = prev->lvl + 1;
	(*br)->prev = prev;
	(*br)->st_a = NULL;
	(*br)->st_a_optid = NULL;
	(*br)->size_a = 0;
	(*br)->st_b = NULL;
	(*br)->st_b_optid = NULL;
	(*br)->size_b = 0;
	do_op(prev, br, op);
	(*br)->diff = get_tot_diff((*br)->size_a, (*br)->size_b, &(*br)->st_a_optid, &(*br)->st_b_optid);
	set_subbranches_to_NULL(br);
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

void	free_tree(t_tree **root)
{
	if (!root || !(*root))
		return ((void)ft_printf("tried to free NULL tree\n"));
	free_tree(&(*root)->sa);
	free_tree(&(*root)->sb);
	free_tree(&(*root)->ss);
	free_tree(&(*root)->pa);
	free_tree(&(*root)->pb);
	free_tree(&(*root)->ra);
	free_tree(&(*root)->rb);
	free_tree(&(*root)->rr);
	free_tree(&(*root)->rra);
	free_tree(&(*root)->rrb);
	free_tree(&(*root)->rrr);

	free_branch(root);
}

void	print_branch(t_tree *branch)
{
	if (!branch)
		return (ft_printf("\nNULL branch!\n"), (void)NULL);
	ft_printf("\nBranch level: %d\n", branch->lvl);

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

	ft_printf("diff of stacks: %d\n\n", branch->diff);
}
