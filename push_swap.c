#include "push_swap.h"

static void	sorting_less_then_5(t_list **a, t_list **b, t_num *num)
{

	if (num->len_list == 4)
		push_in_b_for4(a, b, num);
	else if (num->len_list == 5)
		push_in_b_for5(a, b, num);
	else
		sorting_3(a);
}

static void	sorting_more_then_5(t_list **a, t_list **b, t_num *num)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		search_max_range(&tmp, num);
		tmp = tmp->next;
	}
	push_list_b(a, b, num);
}

static void	read_argv(int argc, char **argv, t_list **a)
{
	int		count;
	char	**str;
	char 	**str_2;

	count = 1;
	while (--argc)
	{
		str = ft_split(argv[count], ' ');
		str_2 = str;
		if (str == NULL)
			error();
		while (*str)
		{
			filling_a(str, a);
			str++;
		}
		free(str_2);
		count++;
	}
}

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
	if (num.len_list <= 5)
		sorting_less_then_5(&a, &b, &num);
	else
		sorting_more_then_5(&a, &b, &num);
	stack_scrolling(&a, &num);
	return (0);
}
