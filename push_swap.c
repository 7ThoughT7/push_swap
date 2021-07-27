#include "push_swap.h"

static void	sorting_less_then_5(t_list **a, t_list **b, t_num *num)
{
	int	len;

	len = num->len_list;
	if (len > 3)
	{
		while (len--)
		{
			if ((*a)->index == 0 || (*a)->index == 1)
				pb(a, b);
			else
				ra(a, 1);
		}
		sorting_3(a);
		search_best_option(a, b, num);
	}
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
//	tmp = *a;
	push_list_b(a, b, num);
}

static void	read_argv(int argc, char **argv, t_list **a)
{
	int		count;
	char	**str;
	t_list	*tmp;

	count = 1;
	while (count < argc)
	{
		str = ft_split(argv[count], ' ');
		if (str == NULL)
			error();
		while (*str)
		{
			parser(a, str);
			tmp = ft_lstnew(ft_atoi(*str));
			if (tmp == NULL)
			{
				ft_lstclear(a);
				error();
			}
			ft_lstadd_back(a, tmp);
			str++;
		}
		count++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_num	num;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if (!a || !b)
		return (0);
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
