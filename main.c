#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct	s_stack
{
	int	value;
	int	index;
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

	i = 1;
	while(stack[i].index != 0)
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
		stack[k] = stack[k + 1];
		k++;
	}
	stack[i - 1].value = temp;
}

void rev_rotate(t_stack *stack)
{
	int temp;
	int i = count_elems(stack);
	int k = 0;
	temp = stack[i - 1].value;
	while (i > 0)
	{
		stack[i].value = stack[i - 1].value;
		stack[i].index = i;
		i--;
	}
	stack[0].value = temp;
}

void push(t_stack *from, t_stack *to)
{
	int	i;
	int k;
	// int temp;

	i = count_elems(to) + 1;
	k = 0;
	// temp = stack
	while (i > 0)
	{
		to[i].value = to[i - 1].value;
		to[i].index = i;
		i--;
	}
	to[0].value = from[0].value;
	i = count_elems(from);
	while (k < i - 1)
	{
		from[k] = from[k + 1];
		k++;
	}
	from[k].value = 0;
	from[k].index = 0;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char **list;
	int i = 0;
	int amount_of_elements = ft_count_words(av[1], ' ');

	if (ac == 2)
		list = ft_split(av[1], ' ');
	stack_a = malloc(sizeof(t_stack) * (amount_of_elements + 1));
	stack_b = malloc(sizeof(t_stack) * (amount_of_elements + 1));
	while(i < amount_of_elements)
	{
		stack_a[i].value = atoi(list[i]);
		stack_a[i].index = i;
		i++;
	}
	stack_b[0].value = 1;
	stack_b[1].value = 5;
	stack_b[2].value = 7;

	stack_b[0].index = 0;
	stack_b[1].index = 1;
	stack_b[2].index = 2;

	printf("stack_a = %d-%d, %d-%d, %d-%d, %d-%d\n", stack_a[0].index, stack_a[0].value, stack_a[1].index, stack_a[1].value, stack_a[2].index, stack_a[2].value, stack_a[3].index, stack_a[3].value);
	// printf("stack_b = %d, %d, %d, %d\n\n", stack_b[0].value, stack_b[1].value, stack_b[2].value, stack_b[3].value);
	rotate(stack_a);
	printf("stack_a = %d-%d, %d-%d, %d-%d, %d-%d\n", stack_a[0].index, stack_a[0].value, stack_a[1].index, stack_a[1].value, stack_a[2].index, stack_a[2].value, stack_a[3].index, stack_a[3].value);
	// printf("stack_b = %d, %d, %d, %d\n", stack_b[0].value, stack_b[1].value, stack_b[2].value, stack_b[3].value);
	free(stack_a);
	free(stack_b);
	free(list);
}