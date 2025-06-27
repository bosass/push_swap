#include "push_swap.h"

int	find_index_of_closest_bigger(int number, t_stack *stack)
{
	int	i;
	int	len;
	int	hold;
	int	temp;

	i = 0;
	len = count_elems(stack);
	hold = INT_MAX;
	temp = -1;
	while (i < len)
	{
		if (stack[i].value < hold && stack[i].value > number)
		{
			hold = stack[i].value;
			temp = i;
		}
		i++;
	}
	return (temp);
}

int	find_index_of_max(t_stack *stack)
{
	int	i;
	int	len;
	int	temp;

	i = 1;
	len = count_elems(stack);
	temp = 0;
	while (i < len)
	{
		if (stack[i].value > stack[temp].value)
			temp = i;
		i++;
	}
	return (temp);
}

int	find_index_of_min_value(t_stack *stack)
{
	int	i;
	int	len;
	int	temp;

	i = 1;
	len = count_elems(stack);
	temp = 0;
	while (i < len)
	{
		if (stack[i].value < stack[temp].value)
			temp = i;
		i++;
	}
	return (temp);
}

int	calc_the_cost(t_stack node, int base_len, int comp_len)
{
	if ((trunc_up(base_len) / 2) > node.index)
	{
		if ((trunc_up(comp_len / 2)) > node.target)
		{
			if (node.index >= node.target)
				return (node.index);
			else
				return (node.target);
		}
		else
			return (node.index + comp_len - node.target);
	}
	else
	{
		if (trunc_up(comp_len / 2) > node.target)
			return (base_len - node.index + node.target);
		else
		{
			if (base_len - node.index >= comp_len - node.target)
				return (base_len - node.index);
			else
				return (comp_len - node.target);
		}
	}
}

int	find_cheapest(t_stack *base, t_stack *compare)
{
	int	i;
	int	base_len;
	int	comp_len;
	int	temp;

	i = 1;
	base_len = count_elems(base);
	comp_len = count_elems(compare);
	temp = 0;
	while (i < base_len)
	{
		if (calc_the_cost(base[i], base_len, comp_len)
			< calc_the_cost(base[temp], base_len, comp_len))
			temp = i;
		i++;
	}
	return (temp);
}
