#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*a;
	t_list	*b;
//	t_list	*test;
	int		count;
	int		asd;
	t_num	num;

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
//	tmp2 = b;
//	while (tmp2)
//	{
//		printf("b:%d\n", tmp2->num);
//		tmp2 = tmp2->next;
//	}
	indexation(&a, num);
//	test = a;
//	while (test)
//	{
//		printf("\nЗначение листа:%d  Индекс листа:%d", test->num, test->index);
//		test = test->next;
//	}
	tmp = NULL;
	tmp = a;
	best_value(&tmp, num);
	tmp2 = NULL;
	tmp2 = a;
	while (tmp2)
	{
		printf("%d\n", tmp2->max_num_range);
		tmp2 = tmp2->next;
	}

	return (0);
}