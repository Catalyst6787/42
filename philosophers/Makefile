.SILENT:

NAME = philosophers
NAME_BONUS = philosophers_bonus

PHILO_DIR = philo
PHILO_BONUS_DIR = philo_bonus

CC = cc -g -Wall -Wextra -Werror -pthread -I./

RM = rm -f

SRC = $(wildcard $(PHILO_DIR)/*.c)
SRC_BONUS = $(wildcard $(PHILO_BONUS_DIR)/*.c)

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

PURPLE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	@echo "$(PURPLE)Linking $(NAME)...$(RESET)"
	$(CC) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "$(PURPLE)Linking $(NAME_BONUS)...$(RESET)"
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c
	@echo "$(PURPLE)Compiling $<...$(RESET)"
	$(CC) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
