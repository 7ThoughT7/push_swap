NAME	= push_swap
NAME_B	= checker
HEADER	= push_swap.h

LIST		= libft_func_0.c libft_func_1.c libft_func_2.c indexation.c best_num_value.c push_swap.c \
			secondary_functions_0.c sort_commands_0.c sort_commands_1.c sort_commands_2.c split.c search_best_option.c \
			secondary_functions_1.c read_and_sorting.c

LIST_B		= checker.c libft_func_0.c libft_func_1.c libft_func_2.c indexation.c best_num_value.c \
			secondary_functions_0.c sort_commands_0.c sort_commands_1.c sort_commands_2.c split.c search_best_option.c \
			secondary_functions_1.c read_and_sorting.c

OBJ			= $(LIST:.c=.o)
OBJ_B		= $(LIST_B:.c=.o)

FLAGS       = -Wall -Wextra -Werror

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			gcc $(OBJ) -o $(NAME)

bonus :		$(OBJ) $(OBJ_B) $(HEADER)
			gcc $(OBJ_B) -o $(NAME_B)

all :		$(NAME)

clean :
			rm -f $(OBJ) $(OBJ_B)

fclean :	clean
			rm -f $(NAME) $(NAME_B)

re :		fclean all

.PHONY :	all clean fclean re bonus
