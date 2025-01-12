SRC = ./src/additional_func.c \
			./src/ft_atol.c \
			./src/instructions_utiles.c \
			./src/checker.c \
			./src/ft_splite.c \
			./src/get_next_line_utils.c \
			./src/main.c \
			./src/stack_a.c \
			./src/clear_list.c \
			./src/get_next_line.c \
			./src/instructions.c \
			./src/main_utiles.c \
			./src/stack_a_utiles.c

INCLUD = ./src/push_swap.h ./src/get_next_line.h
NAME = Moves_Tracker
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

bonus : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c $(INCLUD)
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
