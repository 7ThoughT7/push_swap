#include "push_swap.h"

void	sorting_less_then_5(t_list **a, t_list **b, t_num *num)
{
	if (num->len_list == 4)
		push_in_b_for4(a, b, num);
	else if (num->len_list == 5)
		push_in_b_for5(a, b, num);
	else
		sorting_3(a);
}

void	sorting_more_then_5(t_list **a, t_list **b, t_num *num)
{
	t_list	*tmp;

	tmp = *a;
	search_max_range(&tmp, num);
	push_list_b(a, b, num);
}

void	read_argv(int argc, char **argv, t_list **a)
{
	int		count;
	char	**str;
	char	**str_2;

	count = 1;
	while (--argc)
	{
		str = ft_split(argv[count], ' ');
		str_2 = str;
		if (*str == NULL)
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
