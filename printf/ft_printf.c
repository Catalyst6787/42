#include "header.h"

int	ft_choose_format(char f, va_list ptr)
{
	if (!f)
		return (0);
	if (f == 's')
		return (ft_putstr_c(va_arg(ptr, char *)));
	else if (f == 'c')
		return (ft_putchar_c(va_arg(ptr, int)));
	return (0);
}

int	ft_printf(char *s, ...)
{
	va_list	ptr;
	int c = 0;
	int i = 0;
	
	va_start(ptr, s);
	while(s[i])
	{
		if (s[i] == '%')
		{
			c += ft_choose_format(s[i + 1], ptr);
			i++;
		}
		else
			c += ft_putchar_c(s[i]);
		i++;
	}
	va_end(ptr);
	return (c);
}

int	main(void)
{
	ft_printf("print a string: %s", "'a string'");
	return(0);
}

// gc ft_printf.c  -I./ -I./libft/includes -L./libft -lft && ./a.out
