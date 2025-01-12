/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 06:04:14 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/08 03:10:53 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	min_number(t_list *a)
{
	int		i;

	i = a->number;
	while (a)
	{
		if (a->number < i)
			i = a->number;
		a = a->next;
	}
	return (i);
}

int	max_number(t_list *a)
{
	int		i;

	i = a->number;
	while (a)
	{
		if (a->number > i)
			i = a->number;
		a = a->next;
	}
	return (i);
}

int	find_index(t_list *a, int number)
{
	int		i;

	i = 0;
	while (a->number != number)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int	find_place_b(t_list *stack_b, int nbr_push)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbr_push > stack_b->number && nbr_push < ft_lstlast(stack_b)->number)
		i = 0;
	else if (nbr_push > max_number(stack_b) || nbr_push < min_number(stack_b))
		i = find_index(stack_b, max_number(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->number < nbr_push || tmp->number > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_a(t_list *stack_a, int nbr_push)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (nbr_push < stack_a->number && nbr_push > ft_lstlast(stack_a)->number)
		i = 0;
	else if (nbr_push > max_number(stack_a) || nbr_push < min_number(stack_a))
		i = find_index(stack_a, min_number(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->number > nbr_push || tmp->number < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
