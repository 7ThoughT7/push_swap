#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*a;
	t_list	*b;
	int		count;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if (!a || !b)
		return (0);
	count = 1;
	a = NULL;
	b = NULL;
	while (argv[count] != NULL)
	{
		tmp = ft_lstnew(ft_atoi(argv[count]));
		ft_lstadd_back(&a, tmp);
		count++;
	}

	count = 1;
	while (argv[count] != NULL)
	{
		tmp = ft_lstnew(ft_atoi(argv[count]));
		ft_lstadd_back(&b, tmp);
		count++;
	}
	tmp = a;
	while (tmp)
	{
		printf("a:%d\n", tmp->num);
		tmp = tmp->next;
	}
	tmp2 = b;
	while (tmp2)
	{
		printf("b:%d\n", tmp2->num);
		tmp2 = tmp2->next;
	}
	indexation(&a);

	t_list	*test;
	test = a;
	while (test)
	{
		printf("\nЗначение листа:%d", test->num);
		printf("    Индекс листа:%d", test->index);
		test = test->next;
	}

	return (0);
}