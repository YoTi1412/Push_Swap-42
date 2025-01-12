/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:11:37 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/06 23:11:38 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_ab(t_list *a, t_list *b)
{
	int		i;
	t_list	*tmp;

	tmp = a;
	i = case_rrarrb(a, b, a->number);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->number))
			i = case_rarb(a, b, tmp->number);
		if (i > case_rrarrb(a, b, tmp->number))
			i = case_rrarrb(a, b, tmp->number);
		if (i > case_rarrb(a, b, tmp->number))
			i = case_rarrb(a, b, tmp->number);
		if (i > case_rrarb(a, b, tmp->number))
			i = case_rrarb(a, b, tmp->number);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_ba(t_list *a, t_list *b)
{
	int		i;
	t_list	*tmp;

	tmp = b;
	i = case_rrarrb_a(a, b, b->number);
	while (tmp)
	{
		if (i > case_rarb_a(a, b, tmp->number))
			i = case_rarb_a(a, b, tmp->number);
		if (i > case_rrarrb_a(a, b, tmp->number))
			i = case_rrarrb_a(a, b, tmp->number);
		if (i > case_rarrb_a(a, b, tmp->number))
			i = case_rarrb_a(a, b, tmp->number);
		if (i > case_rrarb_a(a, b, tmp->number))
			i = case_rrarb_a(a, b, tmp->number);
		tmp = tmp->next;
	}
	return (i);
}
