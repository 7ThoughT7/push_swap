#include "push_swap.h"

int nearest_index(t_list **list_a, t_num *num, int index_b)
{
	t_list	*tmp;
	int		index_a;

	tmp = *list_a;
	index_a = 2147483647;
	if (index_b == 0)
	{
		index_a = num->len_list - 1;
	}
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < index_a)
			index_a = tmp->index;
		tmp = tmp->next;
	}
	return (index_a);
}

void	stack_scrolling(t_list **list, t_num *num)
{
	int	index;

	index = (*list)->index;
	if (index < num->len_list / 2)
		while ((*list)->index != 0)
			rra(list, 1);
	else
		while ((*list)->index != 0)
			ra(list, 1);
}

void	sorting_3(t_list **a)
{
	int temp;
	int temp2;
	int temp3;

	temp = (*a)->value;
	temp2 = (*a)->next->value;
	temp3 = (*a)->next->next->value;

	if ((((temp < temp2) && (temp < temp3) && (temp2 > temp3))))
	{
		sa(a);
		ra(a, 1);
	}
	else if (((temp > temp2) && (temp > temp3) && (temp2 > temp3)))
	{
		ra(a, 1);
		sa(a);
	}
	else if (((temp > temp2) && (temp > temp3) && (temp2 < temp3)))
		ra(a, 1);
	else if (((temp > temp2) && (temp2 < temp3) && (temp < temp3)))
		sa(a);
	else if ((temp3 < temp2) && (temp2 > temp))
		rra(a, 1);
}