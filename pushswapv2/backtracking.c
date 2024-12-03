#include "header.h"

static int	get_abs(int nbr)
{
	if (nbr < 0)
		return(-nbr);
	else
		return(nbr);
}

int	get_diff(t_stack **st)
{
	int totdiff;
	t_stack	*tail;
	
	tail = *st;
	totdiff = 0;
	while(tail)
	{
		totdiff += get_abs(tail->id - tail->optid);
		tail = tail->next;
	}
	return(totdiff);
}