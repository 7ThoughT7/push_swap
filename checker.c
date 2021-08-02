#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(line, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(line, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(line, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
		error();
}

void	check_push_swap(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		sort(stack_a, stack_b, line);
		free(line);
	}
	free(line);
	if (!sorting_check(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_num	num;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(0);
	read_argv(argc, argv, &stack_a);
	indexation(&stack_a, &num);
	check_push_swap(&stack_a, &stack_b);
	return (0);
}
