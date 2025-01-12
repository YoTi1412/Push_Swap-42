/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:17:03 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/08 03:17:15 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	validate_char(char **argv, int i, int *j)
{
	if (sign(argv[i][*j]))
	{
		(*j)++;
		if (!digit(argv[i][*j]))
			return (false);
	}
	else if (digit(argv[i][*j]))
	{
		while (digit(argv[i][*j]))
			(*j)++;
		if (argv[i][*j] != '\0' && !space(argv[i][*j]))
			return (false);
	}
	else if (!space(argv[i][*j]))
		return (false);
	else
		(*j)++;
	return (true);
}

int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!validate_char(argv, i, &j))
				return (false);
		}
		i++;
	}
	return (true);
}
