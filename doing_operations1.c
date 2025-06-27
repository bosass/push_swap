#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	if (count_elems(stack) >= 2)
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack *stack)
{
	if (count_elems(stack) >= 2)
	{
		swap(stack);
		write(1, "sb\n", 3);
	}
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	int	a_len;
	int	b_len;

	a_len = count_elems(stack_a);
	b_len = count_elems(stack_b);
	if ((a_len == 0 || a_len == 1) && b_len >= 2)
		swap_b(stack_b);
	else if ((b_len == 0 || b_len == 1) && a_len >= 2)
		swap_a(stack_a);
	else if (b_len >= 2 && a_len >= 2)
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}

void	push_a(t_stack *from, t_stack *to)
{
	if (count_elems(from) >= 1)
	{
		push(from, to);
		write(1, "pa\n", 3);
	}
}

void	push_b(t_stack *from, t_stack *to)
{
	if (count_elems(from) >= 1)
	{
		push(from, to);
		write(1, "pb\n", 3);
	}
}
