/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:49:01 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/08 05:21:10 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_till_3(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = rotate_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, tmp->number))
				i = apply_rarb(stack_a, stack_b, tmp->number, 'a');
			else if (i == case_rrarrb(*stack_a, *stack_b, tmp->number))
				i = apply_rrarrb(stack_a, stack_b, tmp->number, 'a');
			else if (i == case_rarrb(*stack_a, *stack_b, tmp->number))
				i = apply_rarrb(stack_a, stack_b, tmp->number, 'a');
			else if (i == case_rrarb(*stack_a, *stack_b, tmp->number))
				i = apply_rrarb(stack_a, stack_b, tmp->number, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_list	**sort_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_a(*stack_a, *stack_b, tmp->number))
				i = apply_rarb(stack_a, stack_b, tmp->number, 'b');
			else if (i == case_rarrb_a(*stack_a, *stack_b, tmp->number))
				i = apply_rarrb(stack_a, stack_b, tmp->number, 'b');
			else if (i == case_rrarrb_a(*stack_a, *stack_b, tmp->number))
				i = apply_rrarrb(stack_a, stack_b, tmp->number, 'b');
			else if (i == case_rrarb_a(*stack_a, *stack_b, tmp->number))
				i = apply_rrarb(stack_a, stack_b, tmp->number, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

t_list	*sort_b(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !check_sorted(*stack_a))
		sort_b_till_3(stack_a, &stack_b);
	if (!check_sorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

void	ft_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = find_index(*stack_a, min_number(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->number != min_number(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->number != min_number(*stack_a))
			{
				rra(stack_a, 0);
			}
		}
	}
}
