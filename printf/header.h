#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

int	ft_printf(char *s, ...);
char	*ft_itoa_c(int nbr);
int	ft_putchar_c(char c);
int	ft_putstr_c(char *s);
int	ft_putnbr_c(int n);

#endif
