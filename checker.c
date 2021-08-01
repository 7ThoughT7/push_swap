#include "push_swap.h"

int sort(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(line, "sb", 2) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pa", 2) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pb", 2) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rra", 3) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0)
		rr(stack_a, stack_b, 0);
	else
		return (1);
	return (0);
}

void check_push_swap(t_list **stack_a, t_list **stack_b)
{
	char *line;

	line = NULL;
	while (get_next_line(&line))
	{
		if (sort(stack_a, stack_b, line))
			error();
		free(line);
	}
	free(line);
	if (!sorting_check(stack_a))
		write(1,"OK\n", 3);
	else
		write(1,"KO\n", 3);
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(0);
	read_argv(argc, argv, &stack_a);
	indexation(&stack_a, num);
	check_push_swap(&stack_a, &stack_b);
	return (0);
}