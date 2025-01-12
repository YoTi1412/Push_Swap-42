/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <yrafai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 05:39:43 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/18 15:46:11 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	while ((*lst))
	{
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
}

int	ft_lstsize(t_list **lst)
{
	t_list	*tmp;
	int		size;

	if (!lst || !*lst)
		return (0);
	size = 0;
	tmp = *lst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	stack_b_checker(t_list **stack_b)
{
	if (ft_lstsize(stack_b) > 0)
		return (0);
	return (1);
}
