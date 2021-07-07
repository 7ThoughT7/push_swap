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
			return ((*list)->num);
		else
			*list = (*list)->next;
	}
	return (0);
}

int	min_number(t_list **list, int l_size)
{
	int		min_num;
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = *list;
	min_num = check_index(&tmp);
	while (count < l_size)
	{
		if ((*tmp).index == -1 && min_num > (*tmp).num)
			min_num = (*tmp).num;
		tmp = (*tmp).next;
		count++;
	}

	return (min_num);
}

void	indexation(t_list **list)
{
	int		l_size;
	int		min_num;
	int		index;
	t_list	*tmp;
	t_list	*tmp2;

	index = 0;
	tmp = *list;
	l_size = ft_lstsize(tmp);
	ft_bzero(&tmp, l_size);
	while (index < l_size)
	{
		tmp = *list;
		min_num = min_number(&tmp, l_size);
		tmp2 = *list;
		while (tmp2)
		{
			if (tmp2->num == min_num)
			{
				tmp2->index = index;
				index++;
				break;
			}
			tmp2 = tmp2->next;
		}
	}
}