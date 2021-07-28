NAME	= push_swap
HEADER	= push_swap.h

LIST		= libft_func_0.c libft_func_1.c indexation.c best_num_value.c push_swap.c \
			secondary_functions.c sort_commands_0.c sort_commands_1.c sort_commands_2.c split.c search_best_option.c

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			gcc $(OBJ) -o $(NAME)

all :		$(NAME)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
