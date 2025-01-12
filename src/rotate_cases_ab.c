/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cases_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:32:30 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/08 05:21:10 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb(t_list *a, t_list *b, int c)
{
	int	i;

	i = find_place_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}

int	case_rrarrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = ft_lstsize(b) - find_place_b(b, c);
	if ((i < (ft_lstsize(a) - find_index(a, c))) && find_index(a, c))
		i = ft_lstsize(a) - find_index(a, c);
	return (i);
}

int	case_rrarb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (find_index(a, c))
		i = ft_lstsize(a) - find_index(a, c);
	i = find_place_b(b, c) + i;
	return (i);
}

int	case_rarrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = ft_lstsize(b) - find_place_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}
