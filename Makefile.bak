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

HEADER = ./
PATH_SRCS = ./

FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)

SRCS = \
    $(PATH_SRCS)ft_printf.c $(PATH_SRCS)ft_putchar_c.c \
    $(PATH_SRCS)ft_putstr_c.c $(PATH_SRCS)ft_putnbr_c.c \
    $(PATH_SRCS)ft_puthex_c.c $(PATH_SRCS)ft_putunsigned_c.c

OBJS = $(SRCS:.c=.o)

CC = gcc
AR = ar

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAG) $(OPTION) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

