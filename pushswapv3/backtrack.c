#include "header.h"

void	print_tree(t_tree **br)
{
	if (!br || !(*br))
		return ;
	print_branch(*br);
	print_branch((*br)->sa);
	print_branch((*br)->sb);
	print_branch((*br)->ss);
	print_branch((*br)->pa);
	print_branch((*br)->pb);
	print_branch((*br)->ra);
	print_branch((*br)->rb);
	print_branch((*br)->rr);
	print_branch((*br)->rra);
	print_branch((*br)->rrb);
	print_branch((*br)->rrr);
}

static void	call_branch_out(t_tree **br, int max)
{
	if (!br || !(*br))
		return ;
	branch_out(&(*br)->sa, max);
	branch_out(&(*br)->sb, max);
	branch_out(&(*br)->ss, max);
	branch_out(&(*br)->pa, max);
	branch_out(&(*br)->pb, max);
	branch_out(&(*br)->ra, max);
	branch_out(&(*br)->rb, max);
	branch_out(&(*br)->rr, max);
	branch_out(&(*br)->rra, max);
	branch_out(&(*br)->rrb, max);
	branch_out(&(*br)->rrr, max);
}

void	branch_out(t_tree **br, int max)
{
	if (!br || !(*br))
		return ;
	init_branch(*br, &(*br)->sa, SA);
	init_branch(*br, &(*br)->sb, SB);
	init_branch(*br, &(*br)->ss, SS);
	init_branch(*br, &(*br)->pa, PA);
	init_branch(*br, &(*br)->pb, PB);
	init_branch(*br, &(*br)->ra, RA);
	init_branch(*br, &(*br)->rb, RB);
	init_branch(*br, &(*br)->rr, RR);
	init_branch(*br, &(*br)->rra, RRA);
	init_branch(*br, &(*br)->rrb, RRB);
	init_branch(*br, &(*br)->rrr, RRR);
	if ((*br)->lvl < max - 1)
		call_branch_out(br, max);
}

