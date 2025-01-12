/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 06:02:08 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/07 06:02:09 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_check_sign(const char **str)
{
	if (**str == '+')
	{
		(*str)++;
		return (1);
	}
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	return (1);
}

static int	ft_is_valid_digit(const char *str)
{
	if (!*str || !ft_isdigit(*str))
		return (0);
	return (1);
}

int	ft_isdigit_str(const char *str)
{
	long long	num;
	int			sign;

	sign = ft_check_sign(&str);
	if (!ft_is_valid_digit(str))
		return (0);
	num = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && (-num < INT_MIN)))
			return (0);
		str++;
	}
	return (1);
}

void	ft_validate_args(int argc, char **argv, t_list **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isdigit_str(argv[i]))
		{
			ft_free(a);
			ft_error_msg();
		}
		i++;
	}
}
