#include "header.h"

get_best_branch

void	solve(t_tree **br)
{
	if ((*br)->diff == 0)
		return(print_branch(br), (void)printf("\n\nDONE\n\n"));
	else
	{
		branch_out(br, 4);
		solve(get_best_branch(br));
	}
}