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
	int 	i;

	i = 0;
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
		sa(a, 1);
		ra(a, 1);
	}
	else if (((temp > temp2) && (temp > temp3) && (temp2 > temp3)))
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (((temp > temp2) && (temp > temp3) && (temp2 < temp3)))
		ra(a, 1);
	else if (((temp > temp2) && (temp2 < temp3) && (temp < temp3)))
		sa(a, 1);
	else if ((temp < temp2) && (temp2 > temp3))
		rra(a, 1);
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

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
