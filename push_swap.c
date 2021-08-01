#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_num	num;


	a = NULL;
	b = NULL;
	if (argc == 1)
		exit(0);
	read_argv(argc, argv, &a);
	indexation(&a, &num);
	if (sorting_check(&a))
	{
		if (num.len_list == 5 || num.len_list == 3)
			sorting_less_then_5(&a, &b, &num);
		else
			sorting_more_then_5(&a, &b, &num);
		stack_scrolling(&a, &num);
	}
	else
		exit(1);
	return (0);
}
