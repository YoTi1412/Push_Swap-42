/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <yrafai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:57:28 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/18 15:46:57 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ');
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	valid_sing(char *s, int index)
{
	if (s[index] != '+' && s[index] != '-')
		return (0);
	else if ((s[index] == '+' && !is_number(s[index + 1])) || (s[index] == '-'
			&& !is_number(s[index + 1])) || (is_number(s[index - 1])))
		return (0);
	return (1);
}

int	ft_check(char *s)
{
	int	i;
	int	numbers;

	numbers = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!is_number(s[i]) && !is_space(s[i]) && !valid_sing(s, i))
			return (0);
		if (is_number(s[i]))
			numbers++;
		i++;
	}
	if (numbers == 0)
		return (0);
	return (1);
}
