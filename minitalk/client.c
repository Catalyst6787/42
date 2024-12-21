#include "client.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return(0);
	ft_printf("pid of server: %d", ft_atoi(av[1]));
}