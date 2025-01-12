/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:43:56 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/12 19:43:58 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	alpha_check(argv);
	if (!check_error(argv, 1, 0))
		return (false);
	return (true);
}

int	check_dup(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->number == tmp->number)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_sorted(t_list *stack_a)
{
	int	i;

	i = stack_a->number;
	while (stack_a)
	{
		if (i > stack_a->number)
			return (0);
		i = stack_a->number;
		stack_a = stack_a->next;
	}
	return (1);
}
