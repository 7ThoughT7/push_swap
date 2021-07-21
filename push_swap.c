#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*a;
	t_list	*b;
	int		count;
	t_num	num;
	char	**str;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if (!a || !b)
		return (0);
	count = 1;
	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		while (*str != NULL)
		{
			tmp = ft_lstnew(ft_atoi(*str));
			ft_lstadd_back(&a, tmp);
			count++;
		}
	}
	if (argc > 2)
	{
		while (*str != NULL)
		{
			tmp = ft_lstnew(ft_atoi(*str));
			ft_lstadd_back(&a, tmp);
			count++;
		}
	}
	indexation(&a, &num);
	tmp2 = a;
	while (tmp2)
	{
		search_max_range(&tmp2, &num);
		tmp2 = tmp2->next;
	}
	tmp = NULL;
	tmp = a;
	push_list_b(&tmp, &b, &num);
	stack_scrolling(&tmp, &num);
//	while (tmp)
//	{
//		printf("%d\n", tmp->value);
//		tmp = tmp->next;
//	}
	return (0);
}