# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 16:27:11 by lfaure            #+#    #+#              #
#    Updated: 2024/12/20 16:29:35 by lfaure           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -Wunused-function # -fsanitize=address

PRINTF_DIR = ./printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR)/include

SRC = $(wildcard *.c)

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) $(INCLUDES)

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

norme:
	@norminette $(SRC)
	@norminette header.h

re: fclean all
