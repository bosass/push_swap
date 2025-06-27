#include "push_swap.h"

int	ft_isalnum(char *c)
{
	int	i;

	i = 0;
	while (c[i] && c[i] != '\0')
	{
		if ((c[i] < '0' || c[i] > '9')
			&& c[i] != ' ' && c[i] != '+' && c[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
