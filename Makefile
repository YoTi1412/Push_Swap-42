NAME = push_swap
CHECKER = checker
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
INCLUDE = -L $(LIBFTDIR) -lft

SRC_DIR = src/
CHECKER_DIR = bonus/

SRC = $(SRC_DIR)push_swap.c \
      $(SRC_DIR)apply_rotate.c \
      $(SRC_DIR)helpers.c \
      $(SRC_DIR)helpers_2.c \
      $(SRC_DIR)helpers_3.c \
      $(SRC_DIR)helpers_4.c \
      $(SRC_DIR)instructions.c \
      $(SRC_DIR)instructions_2.c \
      $(SRC_DIR)instructions_3.c \
      $(SRC_DIR)process.c \
      $(SRC_DIR)rotate_cases_ab.c \
      $(SRC_DIR)rotate_cases_ba.c \
      $(SRC_DIR)rotate_types.c \
      $(SRC_DIR)sort.c \
      $(SRC_DIR)sort_three.c

BONUS_SRC = $(CHECKER_DIR)checker_bonus.c \
            $(CHECKER_DIR)instructions_bonus.c \
            $(CHECKER_DIR)instructions_2_bonus.c \
            $(CHECKER_DIR)instructions_3_bonus.c \
            $(CHECKER_DIR)helpers_bonus.c \
            $(CHECKER_DIR)helpers_2_bonus.c \
            $(CHECKER_DIR)helpers_3_bonus.c \
            $(CHECKER_DIR)helpers_4_bonus.c \
            $(CHECKER_DIR)process_bonus.c \

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

$(CHECKER): $(BONUS_OBJ)
	@make -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(BONUS_OBJ) -o $(CHECKER) $(INCLUDE)

bonus: $(CHECKER)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	@make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: clean
