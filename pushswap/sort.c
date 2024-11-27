#include "header.h"

int	basic_sort(t_stack **st_a)
{
	int rotate_index;

	rotate_index = 0;
	if (!(*st_a) || !((*st_a)->next))
		return(0);

	while((*st_a) && !check_sort(*st_a))
	{
		if (*st_a && (*st_a)->next && !check_sort(*st_a))
		{
			while ((*st_a)->nbr > (*st_a)->next->nbr)
			{
				swap(*st_a);
				rotate(*st_a);
				rotate_index++;
				print_list(*st_a);
			}
			while (rotate_index)
			{
				rev_rotate(*st_a);
				rotate_index--;
				print_list(*st_a);
			}
		}
	}
	return(1);
}