/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:49:53 by lfaure            #+#    #+#             */
/*   Updated: 2024/12/21 18:55:25 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_char(char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	server_pid;

	if (ac != 3)
		return (0);
	server_pid = ft_atoi(av[1]);
	ft_printf("\nclient received pid: %d\n", server_pid);
	i = 0;
	while (av[2][i])
	{
		ft_printf("sending char> \"%c\"\n", av[2][i]);
		send_char(av[2][i], server_pid);
		i++;
	}
	ft_printf("\ndone! sent all chars.\n");
	return (0);
}
