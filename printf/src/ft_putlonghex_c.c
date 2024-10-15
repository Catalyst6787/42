#include "ft_printf.h"

int	ft_putlonghex_c(unsigned long n, unsigned int up)
{
	char *base;
	char *baseup;
	int c;

	base = "0123456789abcdef";
	baseup = "0123456789ABCDEF";

	c = 0;
	if (n >= 16)
	{
		c += ft_putlonghex_c(n / 16, up);
		n = n % 16;
	}
	if (up)
		return (c + ft_putchar_c(baseup[n]));
	return (c + ft_putchar_c(base[n]));
}
