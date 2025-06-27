#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	if (count_elems(stack) >= 2)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack *stack)
{
	if (count_elems(stack) >= 2)
	{
		rotate(stack);
		write(1, "rb\n", 3);
	}
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	int	a_len;
	int	b_len;

	a_len = count_elems(stack_a);
	b_len = count_elems(stack_b);
	if ((a_len == 0 || a_len == 1) && b_len >= 2)
		rotate_b(stack_b);
	else if ((b_len == 0 || b_len == 1) && a_len >= 2)
		rotate_a(stack_a);
	else if (b_len >= 2 && a_len >= 2)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}

void	rev_rotate_a(t_stack *stack)
{
	if (count_elems(stack) >= 2)
	{
		rev_rotate(stack);
		write(1, "rra\n", 4);
	}
}

void	rev_rotate_b(t_stack *stack)
{
	if (count_elems(stack) >= 2)
	{
		rev_rotate(stack);
		write(1, "rrb\n", 4);
	}
}
