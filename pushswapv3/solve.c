#include "header.h"

void	print_steps(t_tree **br)
{
	if ((*br)->lastop == -1)
		return ;
	else
	{
		print_steps(&(*br)->prev);
		print_op((*br)->lastop);
	}
}

t_tree **find_best_branch(t_tree **br, t_tree **current_best)
{
	if (!br || !(*br))
		return(current_best);
	if ((*br)->diff < (*current_best)->diff || ((*br)->diff == (*current_best)->diff && (*br)->lvl < (*current_best)->lvl))
		current_best = br;
	if ((*br)->sa)
		current_best = find_best_branch(&(*br)->sa, current_best);
	if ((*br)->sb)
		current_best = find_best_branch(&(*br)->sb, current_best);
	if ((*br)->ss)
		current_best = find_best_branch(&(*br)->ss, current_best);
	if ((*br)->pa)
		current_best = find_best_branch(&(*br)->pa, current_best);
	if ((*br)->pb)
		current_best = find_best_branch(&(*br)->pb, current_best);
	if ((*br)->ra)
		current_best = find_best_branch(&(*br)->ra, current_best);
	if ((*br)->rb)
		current_best = find_best_branch(&(*br)->rb, current_best);
	if ((*br)->rr)
		current_best = find_best_branch(&(*br)->rr, current_best);
	if ((*br)->rra)
		current_best = find_best_branch(&(*br)->rra, current_best);
	if ((*br)->rrb)
		current_best = find_best_branch(&(*br)->rrb, current_best);
	if ((*br)->rra)
		current_best = find_best_branch(&(*br)->rra, current_best);
	if ((*br)->rrr)
		current_best = find_best_branch(&(*br)->rrr, current_best);
	return(current_best);
}

t_tree	**get_best_branch(t_tree **tree)
{
	if (!tree || !(*tree))
		return(NULL);
	return(find_best_branch(tree, tree));
}
void	branch_out_next(t_tree **br, int max_depth)
{
	int	is_branch;

	is_branch = 0;
	if (!br || !(*br))
		return ;

	if ((*br)->sa)
	{
		branch_out_next(&(*br)->sa, max_depth);
		is_branch = 1;
	}
	if ((*br)->sb)
	{
		branch_out_next(&(*br)->sb, max_depth);
		is_branch = 1;
	}
	if ((*br)->ss)
	{
		branch_out_next(&(*br)->ss, max_depth);
		is_branch = 1;
	}
	if ((*br)->pa)
	{
		branch_out_next(&(*br)->pa, max_depth);
		is_branch = 1;
	}
	if ((*br)->pb)
	{
		branch_out_next(&(*br)->pb, max_depth);
		is_branch = 1;
	}
	if ((*br)->ra)
	{
		branch_out_next(&(*br)->ra, max_depth);
		is_branch = 1;
	}
	if ((*br)->rb)
	{
		branch_out_next(&(*br)->rb, max_depth);
		is_branch = 1;
	}
	if ((*br)->rr)
	{
		branch_out_next(&(*br)->rr, max_depth);
		is_branch = 1;
	}
	if ((*br)->rra)
	{
		branch_out_next(&(*br)->rra, max_depth);
		is_branch = 1;
	}
	if ((*br)->rrb)
	{
		branch_out_next(&(*br)->rrb, max_depth);
		is_branch = 1;
	}
	if ((*br)->rrr)
	{
		branch_out_next(&(*br)->rrr, max_depth);
		is_branch = 1;
	}
	if (!is_branch)
		branch_out(br, max_depth);
}
/*
static void remove_ref(t_tree **br)
{
	if (!br || !*br)
		return;

	if ((*br)->lastop == SA)
		(*br)->prev->sa = NULL;
	else if ((*br)->lastop == SB)
		(*br)->prev->sb = NULL;
	else if ((*br)->lastop == SS)
		(*br)->prev->ss = NULL;
	else if ((*br)->lastop == PA)
		(*br)->prev->pa = NULL;
	else if ((*br)->lastop == PB)
		(*br)->prev->pb = NULL;
	else if ((*br)->lastop == RA)
		(*br)->prev->ra = NULL;
	else if ((*br)->lastop == RB)
		(*br)->prev->rb = NULL;
	else if ((*br)->lastop == RR)
		(*br)->prev->rr = NULL;
	else if ((*br)->lastop == RRA)
		(*br)->prev->rra = NULL;
	else if ((*br)->lastop == RRB)
		(*br)->prev->rrb = NULL;
	else if ((*br)->lastop == RRR)
		(*br)->prev->rrr = NULL;
}
*/

void	solve(t_tree **br, int max_depth, t_tree **tree)
{
	print_steps(br);
	free_tree_excl(tree, br);
	(*br)->prev = NULL;
	
	if ((*br)->diff == 0)
		return (free_tree(br));
	branch_out_next(br, max_depth);
	solve(get_best_branch(br), max_depth, br);
}