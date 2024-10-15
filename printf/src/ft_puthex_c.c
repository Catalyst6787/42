#include "ft_printf.h"

int	ft_puthex_c(int n, unsigned int up)
{
	char *base;
	char *baseup;

	base = "0123456789abcdef";
	baseup = "0123456789ABCDEF";
	int c;
	c = 0;
	if (n == INT_MIN)
	{
		ft_putstr_c("-80000000");
		return (9);
	}
	if (n < 0)
	{
		c += ft_putchar_c('-');
		n = -n;
	}
	if (n >= 16)
	{
		c += ft_putnbr_c(n / 16);
		n = n % 16;
	}
	if (up)
		return (c + ft_putchar_c(baseup[n]));
	return (c + ft_putchar_c(base[n]));
}
