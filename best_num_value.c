#include "push_swap.h"

void	best_value(t_list **list, t_num num)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		count;
	int 	len;

	tmp = *list;
	num.value = tmp->num;
	while (tmp)
	{
		tmp2 = tmp;
		count = 1;
		len = num.len_list;
		num.value = tmp->num;
		while (len > 0)
		{
			if (num.value < tmp2->num)
			{
				num.value = tmp2->num;
				count++;
			}
			tmp2 = tmp2->next;
			if (tmp2 == 0)
				tmp2 = *list;
			len--;
		}
		tmp->max_num_range = count;
		tmp = tmp->next;
	}
}