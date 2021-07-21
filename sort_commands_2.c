#include "push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4); //удалить
}

void	rrr_rr(t_list **list_a, t_list **list_b, t_num *num)
{
	int	range;

	range = min_r(num->step_a, num->step_b);
	if (num->bool_a == 1)
		while (range-- > 1)
			rr(list_a, list_b);
	else
		while (range-- > 1)
			rrr(list_a, list_b);
}

void	rab_or_rrab(t_list **list_a, t_list **list_b, t_num *num)
{
	int range;

	range = num->step_a - num->step_b;
	if (range > 0)
		if (num->bool_a == 1)
			while (range-- > 0)
				ra(list_a, 1);
		else
			while (range-- > 0)
				rra(list_a, 1);
	else if (range < 0)
	{
		range *= -1;
		if (num->bool_b == 1)
			while (range-- > 0)
				rb(list_b, 1);
		else
			while (range-- > 0)
				rrb(list_b, 1);
	}
}

void	ra_or_rra(t_list **list_a, t_num *num)
{
	int	range;

	range = num->step_a - 1;
	if (num->bool_a == 1)
		while (range-- > 0)
			ra(list_a, 1);
	else
		while (range-- > 0)
			rra(list_a, 1);
}

void	rb_or_rrb(t_list **list_b, t_num *num)
{
	int	range;

	range = num->step_b - 1;
	if (num->bool_b == 1)
		while (range-- > 0)
			rb(list_b, 1);
	else
		while (range-- > 0)
			rrb(list_b, 1);
}