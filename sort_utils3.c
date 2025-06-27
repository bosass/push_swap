#include "push_swap.h"

void	reverse_polarity(t_stack *stack_a, t_stack *stack_b, int super_index)
{
	if (super_index < count_elems(stack_a) / 2)
	{
		if (stack_a[super_index].target < count_elems(stack_b) / 2)
			rev_both_up(stack_a, stack_b, super_index);
		else
			rev_a_up_b_down(stack_a, stack_b, super_index);
	}
	else
	{
		if (stack_a[super_index].target < count_elems(stack_b) / 2)
			rev_a_down_b_up(stack_a, stack_b, super_index);
		else
			rev_both_down(stack_a, stack_b, super_index);
	}
}

void	rev_both_down(t_stack *base, t_stack *compare, int base_index)
{
	int	comp_val;
	int	base_val;

	comp_val = compare[base[base_index].target].value;
	base_val = base[base_index].value;
	if (count_elems(base) - base[base_index].index
		<= count_elems(compare) - base[base_index].target)
	{
		while (base[0].value != base_val)
			rev_rotate_both(base, compare);
		while (compare[0].value != comp_val)
			rev_rotate_a(compare);
	}
	else
	{
		while (compare[0].value != comp_val)
			rev_rotate_both(base, compare);
		while (base[0].value != base_val)
			rev_rotate_b(base);
	}
}

void	rev_a_down_b_up(t_stack *stack_a, t_stack *stack_b, int lowest_cost)
{
	int	b_val;
	int	a_val;

	b_val = stack_b[stack_a[lowest_cost].target].value;
	a_val = stack_a[lowest_cost].value;
	while (stack_a[0].value != a_val)
		rev_rotate_b(stack_a);
	while (stack_b[0].value != b_val)
		rotate_a(stack_b);
}

void	rev_a_up_b_down(t_stack *stack_a, t_stack *stack_b, int lowest_cost)
{
	int	b_val;
	int	a_val;

	b_val = stack_b[stack_a[lowest_cost].target].value;
	a_val = stack_a[lowest_cost].value;
	while (stack_a[0].value != a_val)
		rotate_b(stack_a);
	while (stack_b[0].value != b_val)
		rev_rotate_a(stack_b);
}

void	rev_both_up(t_stack *base, t_stack *compare, int base_index)
{
	int	comp_val;
	int	base_val;

	comp_val = compare[base[base_index].target].value;
	base_val = base[base_index].value;
	if (base_index <= base[base_index].target)
	{
		while (base[0].value != base_val)
			rotate_both(base, compare);
		while (compare[0].value != comp_val)
			rotate_a(compare);
	}
	else
	{
		while (compare[0].value != comp_val)
			rotate_both(base, compare);
		while (base[0].value != base_val)
			rotate_b(base);
	}
}
