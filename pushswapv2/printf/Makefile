# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 17:56:15 by lfaure            #+#    #+#              #
#    Updated: 2024/11/22 16:08:29 by lfaure           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/ft_printf.c \
       src/ft_putchar_c.c \
       src/ft_putnbr_c.c \
       src/ft_putstr_c.c \
       src/ft_putunsigned_c.c \
       src/ft_putlonghex_c.c \
       src/ft_putunsignedhex_c.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./include

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a ./
	ar rcs $@ $(OBJS) libft.a
	rm -f libft.a

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make clean -C ./libft
	rm -rf $(NAME)

re: fclean all
