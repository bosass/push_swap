#include "push_swap.h"

int	count_elems(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack[i].index != -1)
		i++;
	return (i);
}

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack[0].value;
	stack[0].value = stack[1].value;
	stack[1].value = temp;
}

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;
	int	k;

	i = count_elems(stack);
	k = 0;
	temp = stack[0].value;
	while (k < i - 1)
	{
		stack[k].value = stack[k + 1].value;
		stack[k].index = k;
		k++;
	}
	stack[i - 1].value = temp;
}

void	rev_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = count_elems(stack) - 1;
	stack[i + 1].index = -1;
	temp = stack[i].value;
	while (i > 0)
	{
		stack[i].value = stack[i - 1].value;
		stack[i].index = i;
		i--;
	}
	stack[0].index = 0;
	stack[0].value = temp;
}

void	push(t_stack *from, t_stack *to)
{
	int	i;
	int	k;

	i = count_elems(to);
	to[i + 1].index = -1;
	k = 0;
	while (i > 0)
	{
		to[i].value = to[i - 1].value;
		to[i].index = i;
		i--;
	}
	to[0].index = 0;
	to[0].value = from[0].value;
	i = count_elems(from);
	while (k < i - 1)
	{
		from[k].value = from[k + 1].value;
		from[k].index = k;
		k++;
	}
	from[k].value = 0;
	from[k].index = -1;
}
