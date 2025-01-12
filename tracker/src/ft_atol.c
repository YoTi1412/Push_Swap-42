/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <yrafai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:01:58 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/18 15:46:14 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	int		i;
	int		sing;
	long	res;

	if (!s)
		return (0);
	(1) && (i = 0, res = 0, sing = 1);
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sing = -1;
		i++;
	}
	while (is_number(s[i]))
	{
		res = (res * 10) + (s[i] - '0');
		if ((sing == 1 && res > INT_MAX) || (sing == -1 && res > (long)INT_MAX
				+ 1))
			return ((long)INT_MAX + 2);
		i++;
	}
	return (res * sing);
}
