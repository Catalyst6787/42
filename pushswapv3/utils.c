#include "header.h"

void	print_st(int size, int **st)
{
	int i;

	i = 0;
	if (!st || !(*st))
		return(ft_printf("NULL stack\n"), (void)NULL);
	while(i < size)
	{
		ft_printf("element n: %d, value: %d\n", i, (*st)[i]);
		i++;
	}
}

void	free_st(int **st)
{
	if (!st || !(*st))
		return ;
	free(*st);
	(*st) = NULL;
	st = NULL;
}
