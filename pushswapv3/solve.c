#include "header.h"

void	solve(t_tree **br)
{
	if ((*br)->diff == 0)
		return(print_branch(*br), print_steps(br), (void)printf("\n\nDONE\n\n"));
	else
	{
		branch_out(br, 4);
		solve(get_best_branch(br));
	}
}

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