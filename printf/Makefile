# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/29 16:03:02 by lfaure            #+#    #+#              #
#    Updated: 2024/10/07 18:28:39 by lfaure           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

LIBFT = ./libft/libft.a
LIBFTH = ./libft/includes


PATH_SRCS = ./
HEADER = ./

FLAG = -Wall -Wextra -Werror

OPTION = -c -I $(HEADER) -I $(LIBFTH)

SRCS = \
       $(PATH_SRCS)ft_printf.c $(PATH_SRCS)ft_putchar_c.c \
       $(PATH_SRCS)ft_putstr_c.c $(PATH_SRCS)ft_putnbr_c.c \
       $(PATH_SRCS)ft_puthex_c.c $(PATH_SRCS)ft_putunsigned_c.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
