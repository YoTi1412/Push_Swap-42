/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 04:40:50 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/06 04:40:51 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;

	if (argc < 2)
		return (0);
	a = process(argc, argv);
	if (!a || check_dup(a))
	{
		ft_free(&a);
		ft_error_msg();
		return (0);
	}
	if (!check_sorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
