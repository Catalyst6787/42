#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar_c(char c);
int	ft_putstr_c(char *s);
int	ft_putnbr_c(int n);
int	ft_putunsigned_c(unsigned int n);
int	ft_puthex_c(int n, unsigned int up);

#endif
