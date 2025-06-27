#include "push_swap.h"

int	trunc_up(int n)
{
	if (n % 2 == 0)
		return (n);
	return (n + 1);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	len;

	i = 0;
	len = count_elems(stack);
	while (i < len - 1)
	{
		if (stack[i].value < stack[i + 1].value)
			i++;
		else
			return (0);
	}
	return (1);
}

void	rotate_end(t_stack *stack)
{
	int	i;
	int	len;

	i = find_index_of_min_value(stack);
	len = count_elems(stack);
	if (i <= (len / 2))
	{
		while (i > 0)
		{
			rotate_a(stack);
			i--;
		}
	}
	else
	{
		while ((len - i) >= 1)
		{
			rev_rotate_a(stack);
			i++;
		}
	}
}

void	turk_thing(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (count_elems(stack_a) > 3)
		push_b(stack_a, stack_b);
	sort_three(stack_a);
	while (count_elems(stack_b) > 0)
	{
		set_targets_ascend(stack_b, stack_a);
		reverse_polarity(stack_b, stack_a, find_cheapest(stack_b, stack_a));
		push_a(stack_b, stack_a);
	}
	if (!is_sorted(stack_a))
		rotate_end(stack_a);
}
