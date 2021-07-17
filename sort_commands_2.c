#include "push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4); //удалить
}

void	rrr_rr(t_list **list_a, t_list **list_b)
{
	int	range;

	range = min_r((*list_a)->num_range, (*list_b)->num_range);
	if ((*list_a)->bool_v == 1)
		while (range-- > 1)
			rr(list_a, list_b);
	else
		while (range-- > 1)
			rrr(list_a, list_b);
}

void	rab_or_rrab(t_list **list_a, t_list **list_b)
{
	int range;

	range = (*list_a)->num_range - (*list_b)->num_range;
	if (range > 0)
		if ((*list_a)->bool_v == 1)
			while (range-- > 0)
				ra(list_a);
		else
			while (range-- > 0)
				rra(list_a);
	else if (range < 0)
	{
		range *= -1;
		if ((*list_a)->bool_v == 1)
			while (range-- > 0)
				rb(list_b);
		else
			while (range-- > 0)
				rrb(list_b);
	}
}

void	ra_or_rra(t_list **list_a)
{
	int	range;

	range = (*list_a)->num_range;
	if ((*list_a)->bool_v == 1)
		while (range-- > 0)
			ra(list_a);
	else
		while (range-- > 0)
			rra(list_a);
}

void	rb_or_rrb(t_list **list_b)
{
	int	range;

	range = (*list_b)->num_range;
	if ((*list_b)->bool_v == 1)
		while (range-- > 0)
			rb(list_b);
	else
		while (range-- > 0)
			rrb(list_b);
}