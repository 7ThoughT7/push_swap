#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*tmp;
	t_list	**a;
	t_list	**b;
	int		count;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if (!a || !b)
		return (0);
	count = 1;
	*a = NULL;
	*b = NULL;
	while (argv[count] != NULL)
	{
		tmp = ft_lstnew(ft_atoi(argv[count]));
		ft_lstadd_back(a, tmp);
		count++;
	}
	b = a;
	while (*b)
	{
		printf("%d\n", (*b)->num);
		*b = (*b)->next;
	}
	sa(a);
//	while (*a)
//	{
//		printf("%d\n", (*a)->num);
//		*a = (*a)->next;
//	}
	return (0);
}