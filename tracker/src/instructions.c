/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <yrafai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:05:12 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/18 15:46:53 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_stack(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	if (!*stack_b)
	{
		*stack_b = ft_addnew((*stack_a)->data);
		if (!*stack_b)
			return ;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_free_node(&tmp);
	}
	else
	{
		tmp = *stack_b;
		*stack_b = ft_addnew((*stack_a)->data);
		if (!*stack_b)
			return ;
		(*stack_b)->next = tmp;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_free_node(&tmp);
	}
}

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}


void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*cur;

	if (!stack || !*stack || ft_lstsize(stack) == 1)
		return ;
	last = *stack;
	cur = NULL;
	while (last->next)
	{
		cur = last;
		last = last->next;
	}
	cur->next = NULL;
	last->next = *stack;
	*stack = last;
}
