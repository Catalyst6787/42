# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 10:20:38 by lfaure            #+#    #+#              #
#    Updated: 2024/11/18 15:55:44 by lfaure           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define necessary variables
NAME = so_long # Replace with your desired executable name
CC = gcc # Compiler, you can change this to clang if desired
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address  # Compilation flags

# Check system type and adjust includes and flags accordingly
ifeq ($(shell uname), Linux)
	MLX_DIR = ./mlx-linux
	MLX_LIB = $(MLX_DIR)/libmlx_$(shell uname).a
	INCLUDES = -I/usr/include -Imlx
	MLX_FLAGS = $(MLX_LIB) -L/usr/lib/X11 -lXext -lX11
else
	MLX_DIR = ./mlx
	MLX_LIB = $(MLX_DIR)/libmlx_$(shell uname).a
	INCLUDES = -Imlx
	MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

# List of source files
SRC = $(wildcard *.c) # Include main.c and all other .c files in the directory

# Object files are the .o files corresponding to each source file
OBJS = $(SRC:.c=.o)

# The default target to build the program
all: $(NAME)

# Rule to compile .c files to .o
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# Rule to link object files and create the executable
$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

# Rule to build MLX library if it does not exist
$(MLX_LIB):
	@make -C $(MLX_DIR)

# Clean rule to remove generated files
clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean 

# Rule to remove all generated files including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all
