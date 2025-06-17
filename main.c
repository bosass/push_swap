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

// void do_the_thing(t_stack *stack_a, t_stack *stack_b)
// {
//     int amount;

//     amount = count_elems(stack_a);
//     if(amount == 2 && !sorted(stack_a))
//     {
//         swap(stack_a);
//         write(1, "sa\n", 3);
//     }
//     else if(amount == 3 && !sorted(stack_a))
//         sort_three(stack_a);
//     while(amount > 0)
//     {
//         sort();
//     }
// }

int	find_index_of_min(t_stack *stack)
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


void set_targets_descend(t_stack *stack_a, t_stack *stack_b)	
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
	
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	set_targets_descend(stack_a, stack_b);
	printf("a2:\t");
	while(i < count_elems(stack_a) + 2)
	{
		printf("%d)%d>%d\t", stack_a[i].index, stack_a[i].value, stack_a[i].target);
		i++;
	}
	printf("\n");
	i = 0;
	printf("b2:\t");
	while(i < count_elems(stack_b) + 2)
	{
		printf("%d)%d>%d\t", stack_b[i].index, stack_b[i].value, stack_b[i].target);
		i++;
	}
    printf("\n");

    
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
