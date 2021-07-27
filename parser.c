#include "push_swap.h"

void	parser(t_list **a, char **str)
{
	t_list	*tmp;
	char	*value;
	int		val;

	tmp = *a;
	value = *str;
	val = (int)*value;
	if (tmp == NULL)
		return ;
	if (ft_isdigit(*value) == 0)
		error();
	while (tmp != NULL)
	{
		if (tmp->value == val)
			error();
		tmp = tmp->next;
	}
}