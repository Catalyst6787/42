NAME = libftprintf.a

SRCS = src/ft_printf.c	src/ft_putchar_c.c	src/ft_puthex_c.c \
	  src/ft_putnbr_c.c	src/ft_putstr_c.c	src/ft_putunsigned_c.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./include

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft

cp libft/libft.a .:w
	mv libft.a ${NAME}
	ar rcs $(NAME) $(OBJS)

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make clean -C ./libft
	rm -rf $(NAME)

re: fclean all

.SILENT:
