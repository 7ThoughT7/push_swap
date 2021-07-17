#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	zero_bool_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (*list)
	{
		(*list)->bool_v = 0;
		*list = (*list)->next;
	}
	if ((*list) == 0)
		*list = tmp;
}

void	zero_range_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (*list)
	{
		(*list)->num_range = 0;
		*list = (*list)->next;
	}
	if ((*list) == 0)
		*list = tmp;
}

void	min_steps(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp2;
	int 	count;
	int 	index_b;
	int 	index_a;

	tmp2 = *list_b;
	count = tmp2->steps;
	while (tmp2)
	{
		if (tmp2->steps < count)
			count = tmp2->steps;
		tmp2 = tmp2->next;
	}
	while ((*list_b)->steps != count)
		(*list_b) = (*list_b)->next;
	index_b = (*list_b)->index;
	index_a = nearest_index(list_a, index_b);
	while ((*list_a)->index != index_a)
		(*list_a) = (*list_a)->next;
}

int	min_r(a, b)
{
	if (a < b)
		return (a);
	return (b);
}