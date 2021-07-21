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
	t_list	*tmp;
	t_list	*tmp2;
	int 	min_step;

	tmp = *list_a;
	tmp2 = *list_b;
	min_step = tmp2->steps;
	while (tmp2)
	{
		if (tmp2->steps < min_step)
			min_step = tmp2->steps;
		tmp2 = tmp2->next;
	}
	tmp2 = *list_b;
	while (tmp2->steps != min_step)
		tmp2 = tmp2->next;
	num->step_b = tmp2->num_range;
	num->bool_b = tmp2->bool_v;
	num->index_b = tmp2->index;
	num->index_a = nearest_index(list_a, num, num->index_b);
	while (tmp->index != num->index_a)
		tmp = tmp->next;
	num->step_a = tmp->num_range;
	num->bool_a = tmp->bool_v;
}

int	min_r(a, b)
{
	if (a < b)
		return (a);
	return (b);
}