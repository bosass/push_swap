#include "push_swap.h"

void	set_targets_ascend(t_stack *stack_a, t_stack *stack_b)
{
	int	ac;
	int	i;

	i = 0;
	ac = count_elems(stack_a);
	while (i < ac)
	{
		stack_a[i].target = find_index_of_closest_bigger(stack_a[i].value,
				stack_b);
		if (stack_a[i].target == -1)
			stack_a[i].target = find_index_of_min_value(stack_b);
		i++;
	}
}

void	sort_three(t_stack *stack)
{
	if (count_elems(stack) != 3 || is_sorted(stack))
		return ;
	if (find_index_of_max(stack) == 2)
	{
		swap_a(stack);
		return ;
	}
	else if (find_index_of_max(stack) == 1)
	{
		rev_rotate_a(stack);
		if (!is_sorted(stack))
			swap_a(stack);
		return ;
	}
	rotate_a(stack);
	if (!is_sorted(stack))
		swap_a(stack);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = find_index_of_min_value(stack_a);
	if (count_elems(stack_a) != 4 || is_sorted(stack_a))
		return ;
	if (i < 2)
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
	else
	{
		while (i < 4)
		{
			rev_rotate_a(stack_a);
			i++;
		}
	}
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_b, stack_a);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (count_elems(stack_a) == 2 && !is_sorted(stack_a))
		rotate_a(stack_a);
	else if (count_elems(stack_a) == 3 && !is_sorted(stack_a))
		sort_three(stack_a);
	else if (count_elems(stack_a) == 4 && !is_sorted(stack_a))
		sort_four(stack_a, stack_b);
	else if (count_elems(stack_a) >= 5 && !is_sorted(stack_a))
		turk_thing(stack_a, stack_b);
}

void	set_stacks(t_stack *stack_a, t_stack *stack_b, char **list, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack_a[i].value = ft_atoi(list[i]);
		stack_a[i].index = i;
		i++;
	}
	stack_a[i].value = 0;
	stack_a[i].index = -1;
	stack_b[0].value = 0;
	stack_b[0].index = -1;
}
