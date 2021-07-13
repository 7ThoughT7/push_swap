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

//	count = 1;
//	while (argv[count] != NULL)
//	{
//		tmp = ft_lstnew(ft_atoi(argv[count]));
//		ft_lstadd_back(&b, tmp);
//		count++;
//	}
	tmp = a;
	while (tmp)
	{
		printf("a:%d\n", tmp->value);
		tmp = tmp->next;
	}
//	tmp2 = b;
//	while (tmp2)
//	{
//		printf("b:%d\n", tmp2->num);
//		tmp2 = tmp2->next;
//	}
	indexation(&a, &num);
//	test = a;
//	while (test)
//	{
//		printf("\nЗначение листа:%d  Индекс листа:%d", test->num, test->index);
//		test = test->next;
//	}
//	tmp = NULL;
//	tmp = a;
//	tmp2 = NULL;
//	tmp2 = a;
//	while (tmp2)
//	{
//		best_index(&tmp, num);
//		printf("%d\n", tmp2->max_num_range);
//		tmp2 = tmp2->next;
//	}
	tmp2 = NULL;
	tmp2 = a;
	while (tmp2)
	{
		search_max_range(&tmp2, &num);
//		printf("\n%d", tmp2->num_range);
		tmp2 = tmp2->next;
	}
	tmp = NULL;
	tmp = a;
	push_list_b(&tmp, &b, &num);
	while (a)
	{
		printf("\n\na:%d", a->value);
		a = a->next;
	}
	while (b)
	{
		printf("\n\nb:%d", b->value);
		b = b->next;
	}

	return (0);
}