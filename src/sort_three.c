/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:44:30 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/07 05:44:31 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	if (min_number(*stack_a) == (*stack_a)->number)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (max_number(*stack_a) == (*stack_a)->number)
	{
		ra(stack_a, 0);
		if (!check_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (find_index(*stack_a, max_number(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
