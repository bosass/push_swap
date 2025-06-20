#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

typedef struct	s_stack
{
	int	value;
	int	index;
	int target;
}				t_stack;

int trunc_up(int n)
{
	if (n % 2 == 0)
		return (n);
	return (n + 1);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_make_words(char *word, char const *s, int k, int word_ln)
{
	int	i;

	i = 0;
	while (word_ln > 0)
		word[i++] = s[k - word_ln--];
	word[i] = 0;
	return (word);
}

static char	**ft_split_words(char **out, char const *s, char c, int word_ct)
{
	int	i;
	int	k;
	int	word_ln;

	i = 0;
	k = 0 ;
	word_ln = 0;
	while (s[k] && i < word_ct)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_ln++;
		}
		out[i] = (char *)malloc(sizeof(char) * (word_ln + 1));
		if (!out[i])
			return (0);
		ft_make_words (out[i], s, k, word_ln);
		word_ln = 0;
		i++;
	}
	out[i] = 0;
	return (out);
}

char	**ft_split(char const *s, char c)
{
	int		word_ct;
	char	**out;
	
	if (s == 0)
	return (0);
	word_ct = ft_count_words(s, c);
	out = (char **)malloc(sizeof(char *) * (word_ct + 1));
	if (!out)
	return (0);
	ft_split_words (out, s, c, word_ct);
	return (out);
}

int count_elems(t_stack *stack)
{
	int i;

	i = 0;
	while(stack[i].index != -1)
		i++;
	return (i);
}

void swap(t_stack *stack)
{
	int temp;
	temp = stack[0].value;
	stack[0].value = stack[1].value;
	stack[1].value = temp;
}

void rotate(t_stack *stack)
{
	int temp;
	int i = count_elems(stack);
	int k = 0;
	temp = stack[0].value;
	while (k < i - 1)
	{
		stack[k].value = stack[k + 1].value;
        stack[k].index = k;
		k++;
	}
	stack[i - 1].value = temp;
}

void rev_rotate(t_stack *stack)
{
	int temp;
	int i;
	
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

void push(t_stack *from, t_stack *to)
{
	int	i;
	int k;

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
int is_sorted(t_stack *stack)
{
	int i = 0;
	int len = count_elems(stack);
	while (i < len - 1)
	{
		if (stack[i].value < stack[i + 1].value)
			i++;
		else
			return (0);
	}
	return (1);
}

int	calc_the_cost(t_stack stack, int a_len, int b_len)
{
	if ((trunc_up(a_len) / 2) > stack.index)
	{
		if ((trunc_up(b_len / 2)) > stack.target)
			if (stack.index >= stack.target)
				return (stack.index);
			else
				return (stack.target);
		else
			return (stack.index + b_len - stack.target);
	}
	else 
	{
		if (trunc_up(b_len / 2) > stack.target)
			return (a_len - stack.index + stack.target);
		else
			if (a_len - stack.index >= b_len - stack.target)
				return (a_len - stack.index);
			else 
				return (b_len - stack.target);
	}
}
void swap_a(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}
void swap_b(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
} 
void swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
} 
void push_a(t_stack *from, t_stack *to)
{
	push(from, to);
	write(1, "pa\n", 3);
}

void push_b(t_stack *from, t_stack *to)
{
	push(from, to);
	write(1, "pb\n", 3);
}
void rotate_a(t_stack *stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}
void rotate_b(t_stack *stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}
void rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
void rev_rotate_a(t_stack *stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
}
void rev_rotate_b(t_stack *stack)
{
	rev_rotate(stack);
	write(1, "rrb\n", 4);
}
void rev_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}

// void do_the_thing(t_stack *stack_a, t_stack *stack_b)
// {
//     int a_len;

//     a_len = count_elems(stack_a);
//     if(a_len == 2 && !is_sorted(stack_a))
// 		swap_a(stack_a);
//     else if(a_len == 3 && !is_sorted(stack_a))
//         sort_three(stack_a);
//     while(a_len > 0)
//     {
        
//     }
// }

int	find_index_of_min_value(t_stack *stack)
{
	int i = 1;
	int len = count_elems(stack);
	int temp = 0;
	while(i < len)
	{
		if(stack[i].value < stack[temp].value)
			temp = i;
		i++;
	}
	return (temp);
}
int	find_index_of_cheapest(t_stack *stack, int b_len)
{
	int i = 1;
	int a_len = count_elems(stack);
	int temp = 0;
	while(i < a_len)
	{
		if(calc_the_cost(stack[i], a_len, b_len) < calc_the_cost(stack[temp], a_len, b_len))
			temp = i;
		i++;
	}
	return (temp);
}

int	find_index_of_max(t_stack *stack)
{
	int i = 1;
	int len = count_elems(stack);
	int temp = 0;
	while(i < len)
	{
		if(stack[i].value > stack[temp].value)
			temp = i;
		i++;
	}
	return (temp);
}
int	find_index_of_closest_smaller(int number, t_stack *stack)
{
	int i = 0;
	int len = count_elems(stack);
	int hold = INT_MIN;
	int temp = -1;
	while(i < len)
	{
		if(stack[i].value > hold && stack[i].value < number)
		{
			hold = stack[i].value;
			temp = i;
		}
		i++;
	}
	return (temp);
}
int	find_index_of_closest_bigger(int number, t_stack *stack)
{
	int i = 0;
	int len = count_elems(stack);
	int hold = INT_MAX;
	int temp = -1;
	while(i < len)
	{
		if(stack[i].value < hold && stack[i].value > number)
		{
			hold = stack[i].value;
			temp = i;
		}
		i++;
	}
	return (temp);
}
void set_targets_ascend(t_stack *stack_b, t_stack *stack_a)	// closest bigger
{
	int b_len;
	int i;

	i = 0;
	b_len = count_elems(stack_b);
		while (i < b_len)			
		{
			stack_b[i].target = find_index_of_closest_bigger(stack_b[i].value, stack_a);
			if(stack_b[i].target == -1)
				stack_b[i].target = find_index_of_min_value(stack_a);
			i++;
		}
}

void set_targets_descend(t_stack *stack_a, t_stack *stack_b)	// closest smaller
{
	int ac;
	int i;

	i = 0;
	ac = count_elems(stack_a);
		while (i < ac)			
		{
			stack_a[i].target = find_index_of_closest_smaller(stack_a[i].value, stack_b);
			if(stack_a[i].target == -1)
				stack_a[i].target = find_index_of_max(stack_b);
			i++;
		}
}

void sort_three(t_stack *stack)
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
void sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (count_elems(stack_a) != 4 || is_sorted(stack_a))
		return ;
	int i = find_index_of_min_value(stack_a);
	if (i < 2)
	{
		while(i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
	else 
		while(i < 4)
		{
			rev_rotate_a(stack_a);
			i++;
		}
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_b, stack_a);
}

void both_down(t_stack *stack_a, t_stack *stack_b, int lowest_cost)
{
	int i;
	int store_target;
	int store_index;
	i = 0;
	store_target = stack_a[lowest_cost].target; 
	store_index = stack_a[lowest_cost].index;
	int a_len = count_elems(stack_a);
	int b_len = count_elems(stack_b);
	if (store_index >= store_target)
	{
		while(++i < a_len - store_index + 1)
		rev_rotate_both(stack_a, stack_b);
		while(++i <= b_len - store_target + 1)
		rev_rotate_b(stack_b);
	}
	else
	{
		while(++i < b_len - store_target + 1)
		rev_rotate_both(stack_a, stack_b);
		while(++i <= a_len - store_index + 1)
		rev_rotate_a(stack_a);
	}
}
void a_down_b_up(t_stack *stack_a, t_stack *stack_b, int lowest_cost)
{
	int i;
	int store_target;
	int store_index;
	i = 0;
	store_target = stack_a[lowest_cost].target; 
	store_index = stack_a[lowest_cost].index;
	int b_len = count_elems(stack_b);
	int a_len = count_elems(stack_a);
	while(++i < a_len - store_index + 1)
	rev_rotate_a(stack_a);
	i = 0;
	while(++i < store_target + 1)
	rotate_b(stack_b);
}

void a_up_b_down(t_stack *stack_a, t_stack *stack_b, int lowest_cost)
{
	int i;
	int store_target;
	int store_index;
	i = 0;
	store_target = stack_a[lowest_cost].target; 
	store_index = stack_a[lowest_cost].index;
	
	while(++i < store_index + 1)
	rotate_a(stack_a);
	i = 0;
	while(++i + store_target < count_elems(stack_b) + 1)
	rev_rotate_b(stack_b);
}

void both_up(t_stack *stack_a, t_stack *stack_b, int lowest_cost)
{
	int i;
	int store_target;
	int store_index;
	i = 0;
	store_target = stack_a[lowest_cost].target; // --3
	store_index = stack_a[lowest_cost].index;	// --5
	if (store_index >= store_target)
	{
		while(++i < store_target + 1)
		rotate_both(stack_a, stack_b);
		while(++i <= store_index)
		rotate_a(stack_a);
	}
	else
	{
		while(++i <= store_index)
		rotate_both(stack_a, stack_b);
		while(++i <= store_target + 1)
		rotate_b(stack_b);
	}
}
void check_polarity(t_stack *stack_a, t_stack *stack_b, int super_index)
{
	if (super_index < count_elems(stack_a) / 2)// if our star is above this trash 
	{
		if (stack_a[super_index].target < count_elems(stack_b) / 2)// if malibu is above this trash
			both_up(stack_a, stack_b, super_index); // move there
		else
			a_up_b_down(stack_a, stack_b, super_index);
	}
	else // life of poverty
	{
		if (stack_a[super_index].target < count_elems(stack_b) / 2) // we aiming big
			a_down_b_up(stack_a, stack_b, super_index);
		else
			both_down(stack_a, stack_b, super_index);
	}

}
void good_shi(t_stack *stack_b, t_stack *stack_a, int super_index)
{
	int i;
	int store_target;
	int store_index;
	i = 0;
	store_target = stack_b[super_index].target; // --3
	store_index = stack_b[super_index].index;	// --5
	if (store_index >= store_target)
	{
		while(++i <= store_target)
		rotate_both(stack_a, stack_b);
		while(++i <= store_index)
		rotate_b(stack_b);
	}
	else
	{
		while(++i <= store_index)
		rotate_both(stack_a, stack_b);
		while(++i <= store_target + 1)
		rotate_a(stack_a);
	}
}
void	gheto_life(t_stack *stack_b, t_stack *stack_a, int super_index)
{
	int i;
	int store_target;
	int store_index;
	i = 0;
	store_target = stack_b[super_index].target; 
	store_index = stack_b[super_index].index;
	
	while(++i <= store_index)
	rotate_a(stack_b);
	i = 0;
	while(++i + store_target <= count_elems(stack_a))
	rev_rotate_b(stack_a);
}
void get_me_out(t_stack *stack_b, t_stack *stack_a, int super_index)
{
	int i;
	int store_target;
	int store_index;
	i = 0;
	store_target = stack_b[super_index].target; 
	store_index = stack_b[super_index].index;
	
	while(++i + store_index < count_elems(stack_a) + 1)
	rev_rotate_b(stack_b);
	while(++i < store_target + 1)
	rotate_a(stack_a);
}
void final_countdown(t_stack *stack_b, t_stack *stack_a, int super_index)
{
	int i;
	int store_target;
	int store_index;
	i = 0;
	store_target = stack_b[super_index].target; 
	store_index = stack_b[super_index].index;
	if (store_index >= store_target)
	{
		while(++i < store_target + 1)
		rev_rotate_both(stack_a, stack_b);
		while(++i <= store_index + 1)
		rev_rotate_b(stack_b);
	}
	else
	{
		while(++i < store_index + 1)
		rev_rotate_both(stack_a, stack_b);
		while(++i <= store_target + 1)
		rev_rotate_a(stack_a);
	}
}
void reverse_polarity(t_stack *stack_b, t_stack *stack_a, int super_index)
{
	if (super_index < count_elems(stack_b) / 2) // boy was from white neibrhd 
	{
		if (stack_b[super_index].target < count_elems(stack_a) / 2)
			good_shi(stack_b, stack_a, super_index);
		else
			gheto_life;
	}
	else // life of poverty
	{
		if (stack_b[super_index].target < count_elems(stack_b) / 2) // we aiming big
			get_me_out(stack_a, stack_b, super_index);
		else
			final_countdown(stack_a, stack_b, super_index);
	}

}

void turk_thing(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int a_len;
	int b_len;
	
	i = 0;
	// push_b(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	a_len = count_elems(stack_a);
	b_len = count_elems(stack_b);
	set_targets_descend(stack_a, stack_b);
	while(count_elems(stack_a) > 3)
	{
		check_polarity(stack_a, stack_b, find_index_of_cheapest(stack_a, b_len));
		push_b(stack_a, stack_b);
		set_targets_descend(stack_a, stack_b);
		b_len = count_elems(stack_b);
	}
	sort_three(stack_a);
	set_targets_ascend(stack_b, stack_a);
	a_len = count_elems(stack_a);
	b_len = count_elems(stack_b);
	while(b_len >= 1)
	{
		set_targets_ascend(stack_b, stack_a);
		check_polarity(stack_b, stack_a, find_index_of_cheapest(stack_b, a_len));
		push_a(stack_b, stack_a);
		a_len = count_elems(stack_a);
		b_len = count_elems(stack_b);
	}
	set_targets_descend(stack_a, stack_b);
	
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char **list;
	int i = 0;
    
    
	if (ac == 2)
        list = ft_split(av[1], ' ');
    else 
        return 0;
	int amount_of_elements = ft_count_words(av[1], ' ');
	stack_a = malloc(sizeof(t_stack) * (amount_of_elements + 1));
	stack_b = malloc(sizeof(t_stack) * (amount_of_elements + 1));
	while(i < amount_of_elements)
	{
		stack_a[i].value = atoi(list[i]);
		stack_a[i].index = i;
		// stack_a[i].target = 0;
		i++;
	}
    stack_a[i].value = 0;
    stack_a[i].index = -1;  
	
    stack_b[0].value = 0;
    stack_b[0].index = -1; 
	
	
	// push(stack_a, stack_b);
	// push(stack_a, stack_b);
	// push(stack_a, stack_b);
	// push(stack_a, stack_b);
	// push(stack_a, stack_b);
	i = 0;
	printf("a1:\t");
	while(i < count_elems(stack_a) + 2)
	{
		printf("%d)%d>%d\t", stack_a[i].index, stack_a[i].value, stack_a[i].target);
		i++;
	}
	printf("\n");
	i = 0;
	printf("b1:\t");
	while(i < count_elems(stack_b) + 2)
	{
		printf("%d)%d>%d\t", stack_b[i].index, stack_b[i].value, stack_b[i].target);
		i++;
	}
	printf("\n_______\n\n");
	i = 0;
	
	turk_thing(stack_a, stack_b);
	
	
	
	printf("a2:\t");
	while(i < count_elems(stack_a) + 1)
	{
		printf("%d)%d>%d(%d)\t", stack_a[i].index, stack_a[i].value, stack_a[i].target, calc_the_cost(stack_a[i], count_elems(stack_a), count_elems(stack_b)));
		i++;
	}
	printf("\n");
	i = 0;
	printf("b2:\t");
	while(i < count_elems(stack_b) + 1)
	{
		printf("%d)%d>%d(%d)\t", stack_b[i].index, stack_b[i].value, stack_b[i].target, calc_the_cost(stack_b[i], count_elems(stack_b), count_elems(stack_a)));
		i++;
	}
    printf("\n");

    printf("%d", find_index_of_min_value(stack_a));

    free(stack_b);
    free(stack_a);
    i = 0;
    while(i < amount_of_elements)
    {
        free(list[i]);
        i++;
    }
	free(list);
}
