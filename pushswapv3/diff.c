#include "header.h"

static int	get_next_smallest(int size, int **st, int last_smallest)
{
	int	i;
	int	smallest;
	int	set;

	i = 0;
	set = 0;
	smallest = 0;
	while(i < size)
	{
		if (!set && (*st)[i] > (*st)[last_smallest])
		{
			set = 1;
			smallest = i;
		}
		else if (set && (*st)[i] < (*st)[smallest] && (*st)[i] > (*st)[last_smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

static int get_smallest(int size, int **st)
{
	int i;
	int smallest;

	i = 1;

	smallest = 0;
	while(i < size)
	{
		if ((*st)[i] < (*st)[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

void	set_optid(int size, int **st, int **st_optid)
{
	int current_optid;
	int last_smallest;
	
	current_optid = 0;

	last_smallest = get_smallest(size, st);
	while(current_optid < size)
	{
		(*st_optid)[last_smallest] = current_optid;
		current_optid++;
		last_smallest = get_next_smallest(size, st, last_smallest);
	}
}
