#include "push_swap.h"

int	ft_repeat(char **list, int len)
{
	int	i;
	int	k;

	i = 0;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if ((ft_atoi(list[k])) == (ft_atoi(list[i])))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

void	free_list(char **list, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(list[i]);
		i++;
	}
	free(list);
	exit (0);
}

void	spell_check(char **list, int len, int ac)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!ft_isalnum(list[i]))
		{
			write(1, "Error\n", 6);
			if (ac == 2)
				free_list(list, len);
			exit (0);
		}
		else if (ft_atoi(list[i]) > INT_MAX || ft_atoi(list[i]) < INT_MIN)
		{
			write(1, "Error\n", 6);
			if (ac == 2)
				free_list(list, len);
			exit (0);
		}
		i++;
	}
}

char	**write_args_to_list(int ac, char **av, int *amount_of_elements)
{
	char	**list;

	if (ac == 2)
	{
		list = ft_split(av[1], ' ');
		*amount_of_elements = ft_count_words(av[1], ' ');
	}
	else if (ac >= 3)
	{
		list = av + 1;
		*amount_of_elements = ac - 1;
	}
	else
		exit (1);
	spell_check(list, *amount_of_elements, ac);
	if (ft_repeat(list, *amount_of_elements))
	{
		write(1, "Error\n", 6);
		if (ac == 2)
			free_list(list, *amount_of_elements);
		exit (0);
	}
	return (list);
}
