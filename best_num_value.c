#include "push_swap.h"

void	search_max_range(t_list **list, t_num *num)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		count;
	int		len;

	tmp = *list;
	while (tmp)
	{
		tmp2 = tmp;
		count = 1;
		len = num->len_list;
		num->value = tmp->value;
		while (len-- > 0)
		{
			if (num->value < tmp2->value && count++)
				num->value = tmp2->value;
			tmp2 = tmp2->next;
			if (tmp2 == 0)
				tmp2 = *list;
		}
		tmp->num_range = count;
		tmp = tmp->next;
	}
}

void	max_range(t_list **list, t_num *num)
{
	t_list *tmp;

	tmp = *list;
	num->max_range = tmp->num_range;
	num->val_ran = tmp->value;
	while (tmp)
	{
		if (num->max_range < tmp->num_range)
		{
			num->max_range = tmp->num_range;
			num->val_ran = tmp->value;
		}
		if (num->max_range == tmp->num_range)
		{
			if (num->val_ran > tmp->value)
				num->val_ran = tmp->value;
		}
		tmp = tmp->next;
	}
}

void	search_start(t_list **a, t_num *num)
{
	int	len;
	t_list *tmp;

	tmp = *a;
	len = num->len_list;
	while (*a)
	{
		if ((*a)->value == num->val_ran && (*a)->num_range == num->max_range)
			break;
		*a = (*a)->next;
	}
	num->count = (*a)->value;
	(*a)->bool_v = 1;
	while (len--)
	{
		if (num->count < (*a)->value)
		{
			(*a)->bool_v = 1;
			num->count = (*a)->value;
		}
		*a = (*a)->next;
		if ((*a) == 0)
			(*a) = tmp;
	}
}

void	push_b(t_list **list_a, t_list **list_b, t_num *num)
{
	int	len;
	len = num->len_list;
	while (len--)
	{
		if ((*list_a)->bool_v == 1)
			ra(list_a, 1);
		else
			pb(list_a, list_b);
	}
}

void	push_list_b(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp;

	tmp = *list_a;
	max_range(&tmp, num);
	tmp = *list_a;
	zero_bool_list(&tmp);
	search_start(&tmp, num);
	push_b (list_a,list_b, num);
	search_best_option(list_a, list_b, num);
	tmp = *list_a;
}