#include "header.h"

void	print_tree(t_tree **br)
{
	if (!br || !(*br))
		return ;
	print_branch(*br);
	print_tree(&(*br)->sa);
	print_tree(&(*br)->sb);
	print_tree(&(*br)->ss);
	print_tree(&(*br)->pa);
	print_tree(&(*br)->pb);
	print_tree(&(*br)->ra);
	print_tree(&(*br)->rb);
	print_tree(&(*br)->rr);
	print_tree(&(*br)->rra);
	print_tree(&(*br)->rrb);
	print_tree(&(*br)->rrr);
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
	if (max)
	{
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
	}
	if (max - 1)
		call_branch_out(br, max--);
}
