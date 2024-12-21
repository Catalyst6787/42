# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 16:27:11 by lfaure            #+#    #+#              #
#    Updated: 2024/12/21 15:14:26 by lfaure           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror # -Wunused-function # -fsanitize=address

PRINTF_DIR = ./printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR)/include

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(PRINTF_LIB) $(LIBFT_LIB) $(INCLUDES)

$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(PRINTF_LIB) $(LIBFT_LIB) $(INCLUDES)

clean:
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

norme:
	@norminette $(SRCS_SERVER) $(SRCS_CLIENT)
	@norminette header.h

re: fclean all

.PHONY: all clean fclean re