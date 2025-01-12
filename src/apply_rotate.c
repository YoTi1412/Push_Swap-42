/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:40:19 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/07 05:40:20 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->number != c && find_place_b(*b, c) > 0)
			rr(a, b, 0);
		while ((*a)->number != c)
			ra(a, 0);
		while (find_place_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->number != c && find_place_a(*a, c) > 0)
			rr(a, b, 0);
		while ((*b)->number != c)
			rb(b, 0);
		while (find_place_a(*a, c) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->number != c && find_place_b(*b, c) > 0)
			rrr(a, b, 0);
		while ((*a)->number != c)
			rra(a, 0);
		while (find_place_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->number != c && find_place_a(*a, c) > 0)
			rrr(a, b, 0);
		while ((*b)->number != c)
			rrb(b, 0);
		while (find_place_a(*a, c) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->number != c)
			rra(a, 0);
		while (find_place_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			rra(a, 0);
		while ((*b)->number != c)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->number != c)
			ra(a, 0);
		while (find_place_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ra(a, 0);
		while ((*b)->number != c)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
