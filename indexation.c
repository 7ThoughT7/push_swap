#include "push_swap.h"

void	ft_bzero(t_list **list, int number)
{
	t_list	*tmp;

	tmp = *list;
	while (number-- > 0)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

int	check_index(t_list **list)
{
	while (list)
	{
		if ((*list)->index == -1)
			return ((*list)->value);
		else
			*list = (*list)->next;
	}
	return (0);
}

int	min_number(t_list **list, t_num *num)
{
	int		min_num;
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = *list;
	min_num = check_index(&tmp);
	while (count < num->len_list && tmp != NULL)
	{
		if ((*tmp).index == -1 && min_num > (*tmp).value)
			min_num = (*tmp).value;
		tmp = (*tmp).next;
		count++;
	}

	return (min_num);
}

void	indexation(t_list **list, t_num *num)
{
	int		min_num;
	int		index;
	t_list	*tmp;
	t_list	*tmp2;

	index = 0;
	tmp = *list;
	num->len_list = ft_lstsize(tmp);
	ft_bzero(&tmp, num->len_list);
	while (index < num->len_list)
	{
		min_num = min_number(&tmp, num);
		tmp2 = *list;
		while (tmp2)
		{
			if (tmp2->value == min_num)
			{
				tmp2->index = index++;
				break;
			}
			tmp2 = tmp2->next;
		}
	}
}