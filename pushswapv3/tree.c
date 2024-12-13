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
	
	/* NOT SURE THAT THIS IS NECESSARY, KEEPING IT AROUND FOR NOW
	(*br)->sa = NULL;
	(*br)->sb = NULL;
	(*br)->ss = NULL;
	(*br)->pa = NULL;
	(*br)->pb = NULL;
	(*br)->ra = NULL;
	(*br)->rb = NULL;
	(*br)->rr = NULL;
	(*br)->rra = NULL;
	(*br)->rrb = NULL;
	(*br)->rrr = NULL;
	*/
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
	free_branch(&(*root)->sa);
	free_branch(&(*root)->sb);
	free_branch(&(*root)->ss);
	free_branch(&(*root)->pa);
	free_branch(&(*root)->pb);
	free_branch(&(*root)->ra);
	free_branch(&(*root)->rb);
	free_branch(&(*root)->rr);
	free_branch(&(*root)->rra);
	free_branch(&(*root)->rrb);
	free_branch(&(*root)->rrr);

	free_branch(root);
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
