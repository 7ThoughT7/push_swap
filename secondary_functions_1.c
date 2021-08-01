#include "push_swap.h"

void	parser(t_list **a, t_list *list)
{
	t_list	*tmp;
	int 	value;

	tmp = *a;
	value = list->value;
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			error();
		tmp = tmp->next;
	}
}

void	filling_a(char **str, t_list **a)
{
	t_list	*tmp;

	tmp = ft_lstnew(ft_atoi(*str));
	free(*str);
	if (tmp == NULL)
	{
		ft_lstclear(a);
		error();
	}
	parser(a, tmp);
	ft_lstadd_back(a, tmp);
}

void	push_in_b_for4(t_list **a, t_list **b, t_num *num)
{
	int	len;

	len = num->len_list;
	while (len--)
	{
		if ((*a)->index == 0)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	sorting_3(a);
	search_best_option(a, b, num);
}

void	push_in_b_for5(t_list **a, t_list **b, t_num *num)
{
	int	len;

	len = num->len_list;
	while (len--)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	sorting_3(a);
	search_best_option(a, b, num);
}

int	sorting_check(t_list **list)
{
	t_list	*tmp;
	int 	count;

	tmp = *list;
	count = 0;
	if (tmp->index == count)
	{
		while (tmp)
		{
			if (tmp->index == count)
			{
				tmp = tmp->next;
				count++;
			}
			else
				break;
		}
		if (tmp == NULL)
			return (0);
	}
	return (1);
}