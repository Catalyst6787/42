#include "header.h"

int	main(int ac, char **av)
{
	int *st;
	int size;

	st = NULL;
	size = 0;

	if (ac < 2)
		return (0);
	size = get_stack(ac, av, &st);
	print_st(size, &st);
	free_st(&st);
}
