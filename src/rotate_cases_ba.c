/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cases_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:34:07 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/08 05:21:10 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = find_place_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int	case_rrarrb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = ft_lstsize(a) - find_place_a(a, c);
	if ((i < (ft_lstsize(b) - find_index(b, c))) && find_index(b, c))
		i = ft_lstsize(b) - find_index(b, c);
	return (i);
}

int	case_rarrb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = ft_lstsize(b) - find_index(b, c);
	i = find_place_a(a, c) + i;
	return (i);
}

int	case_rrarb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = ft_lstsize(a) - find_place_a(a, c);
	i = find_index(b, c) + i;
	return (i);
}
