/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 04:47:53 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/06 04:47:53 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*process_numbers(char **numbers, t_list *a)
{
	int	j;

	j = 0;
	while (numbers[j])
	{
		if (!*numbers[j])
		{
			clean_2(numbers);
			ft_error_msg();
		}
		ft_lstadd_back(&a, ft_stack_new(ft_atoi_2(numbers[j])));
		j++;
	}
	clean_2(numbers);
	return (a);
}

t_list	*process(int argc, char **argv)
{
	t_list	*a;
	char	**numbers;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error_msg();
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			ft_error_msg();
		a = process_numbers(numbers, a);
		i++;
	}
	return (a);
}
