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
