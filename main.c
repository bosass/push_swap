#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**list;
	int		amount_of_elements;

	list = write_args_to_list(ac, av, &amount_of_elements);
	stack_a = malloc(sizeof(t_stack) * (amount_of_elements + 1));
	stack_b = malloc(sizeof(t_stack) * (amount_of_elements + 1));
	if (stack_a == NULL || stack_b == NULL)
		return (0);
	set_stacks(stack_a, stack_b, list, amount_of_elements);
	sort_stack(stack_a, stack_b);
	free(stack_b);
	free(stack_a);
	if (ac == 2)
		free_list(list, amount_of_elements);
}
