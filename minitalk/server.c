#include "server.h"

void signal_handler(int signum)
{
	static char	res;
	static int	bit_pos;
	if (signum == SIGUSR1)
		res |= (1 << (7 - bit_pos));
	bit_pos++;
	if (bit_pos == 8)
	{
		ft_printf("%c", res);
		res = 0;
		bit_pos = 0;
	}
}

int main(void)
{
    struct sigaction action;
    action.sa_handler = signal_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    ft_printf("%d\n\n", getpid());
    while (1)
        usleep(1000);
    return 0;
}
