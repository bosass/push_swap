#include "push_swap.h"

void	rev_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	int	a_len;
	int	b_len;

	a_len = count_elems(stack_a);
	b_len = count_elems(stack_b);
	if ((a_len == 0 || a_len == 1) && b_len >= 2)
		rev_rotate_b(stack_b);
	else if ((b_len == 0 || b_len == 1) && a_len >= 2)
		rev_rotate_a(stack_a);
	else if (b_len >= 2 && a_len >= 2)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
