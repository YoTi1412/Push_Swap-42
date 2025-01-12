/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <yrafai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/18 15:46:04 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	instruction_valid(char *buffer, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(buffer, "sa\n") == 0)
		ft_swap_stack(stack_a);
	else if (ft_strcmp(buffer, "sb\n") == 0)
		ft_swap_stack(stack_b);
	else if (ft_strcmp(buffer, "ss\n") == 0)
		ft_swap_all(stack_a, stack_b);
	else if (ft_strcmp(buffer, "pa\n") == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(buffer, "pb\n") == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(buffer, "ra\n") == 0)
		ft_rotate(stack_a);
	else if (ft_strcmp(buffer, "rb\n") == 0)
		ft_rotate(stack_b);
	else if (ft_strcmp(buffer, "rr\n") == 0)
		ft_rotate_all(stack_a, stack_b);
	else if (ft_strcmp(buffer, "rra\n") == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strcmp(buffer, "rrb\n") == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strcmp(buffer, "rrr\n") == 0)
		ft_reverse_all(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	ft_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*buffer;
	int		err;

	err = 0;
	ft_print_lists(stack_a, stack_b);
	buffer = get_next_line(0);
	while (buffer)
	{
		if (buffer[0] == '\n')
			return (free(buffer), 1);
		err = instruction_valid(buffer, stack_a, stack_b);
		if (err == 1)
			return (free(buffer), 1);
		free(buffer);
		ft_print_lists(stack_a, stack_b);
		buffer = get_next_line(0);
	}
	return (0);
}
