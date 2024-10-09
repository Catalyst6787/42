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

NAME = libft.a

PATH_SRCS = ./
HEADER = ./

FLAG = -Wall -Wextra -Werror

OPTION = -c -I $(HEADER)

SRCS = \
	   $(PATH_SRCS)ft_isalpha.c $(PATH_SRCS)ft_isdigit.c $(PATH_SRCS)ft_isalnum.c $(PATH_SRCS)ft_isascii.c \
	   $(PATH_SRCS)ft_isprint.c $(PATH_SRCS)ft_strlen.c $(PATH_SRCS)ft_memset.c $(PATH_SRCS)ft_bzero.c \
	   $(PATH_SRCS)ft_memcpy.c $(PATH_SRCS)ft_strlcpy.c $(PATH_SRCS)ft_memmove.c $(PATH_SRCS)ft_strlcat.c \
	   $(PATH_SRCS)ft_toupper.c $(PATH_SRCS)ft_tolower.c $(PATH_SRCS)ft_strchr.c $(PATH_SRCS)ft_strrchr.c \
	   $(PATH_SRCS)ft_strncmp.c $(PATH_SRCS)ft_memchr.c $(PATH_SRCS)ft_memcmp.c $(PATH_SRCS)ft_strnstr.c \
	   $(PATH_SRCS)ft_atoi.c $(PATH_SRCS)ft_calloc.c $(PATH_SRCS)ft_strdup.c $(PATH_SRCS)ft_substr.c  \
	   $(PATH_SRCS)ft_strjoin.c $(PATH_SRCS)ft_strtrim.c $(PATH_SRCS)ft_split.c $(PATH_SRCS)ft_itoa.c \
	   $(PATH_SRCS)ft_strmapi.c $(PATH_SRCS)ft_striteri.c $(PATH_SRCS)ft_putchar_fd.c \
       $(PATH_SRCS)ft_putstr_fd.c $(PATH_SRCS)ft_putendl_fd.c $(PATH_SRCS)ft_putnbr_fd.c

SRCSB = \
	   $(PATH_SRCS)ft_lstnew_bonus.c $(PATH_SRCS)ft_lstadd_front_bonus.c $(PATH_SRCS)ft_lstsize_bonus.c \
	   $(PATH_SRCS)ft_lstlast_bonus.c




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
