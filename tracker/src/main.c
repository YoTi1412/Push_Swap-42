/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <yrafai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:59:04 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/18 15:47:01 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mult_check(char **v, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (!ft_check(v[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_init(int c, char **v, t_list **stack_a)
{
	int	check_err;

	check_err = 0;
	if (c == 1)
		return (1);
	else if (c == 2 && ft_check(v[1]))
		check_err += stack_init(v[1], stack_a, 0);
	else if (c >= 3 && ft_mult_check(v + 1, c - 1))
		check_err += stack_init_mult(v + 1, stack_a);
	else
		check_err++;
	if (check_err == 0)
	{
		if (ft_list_checker(stack_a) == 1)
			return (1);
	}
	return (check_err);
}

#include "stdio.h"

void ft_print_lists(t_list **stack_1, t_list **stack_2)
{
	int size = 0;
	int size1 = ft_lstsize(stack_1);
	int size2 = ft_lstsize(stack_2);
	if (size1 > size2)
		size = size1;
	else
		size = size2;
	t_list *stack_a = *stack_1;
	t_list *stack_b = *stack_2;
    printf("------Start-----\n");
    while (size)
    {
        if (stack_a)
        {
            printf("%5d|\t", stack_a->data);
            stack_a = stack_a->next;
        }
        else
        {
            printf("  |   \t");
        }
        if (stack_b)
        {
            printf("%5d|", stack_b->data);
            stack_b = stack_b->next;
        }
        size--;
        printf("\n");
    }
    printf("   -\t    -\n   a\t    b\n");
    printf("-------End-------\n");
}

int	main(int c, char **v)
{
	int		check_err;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (c == 1)
		return (0);
	check_err = ft_init(c, v, &stack_a);
	if (check_err > 0)
		return (print_err("Error\n"), ft_lstclear(&stack_a), 1);
	check_err += ft_instructions(&stack_a, &stack_b);
	if (check_err != 0)
		return (print_err("Error\n"), ft_lstclear(&stack_a),
			ft_lstclear(&stack_b), 1);
	if (ft_sort_checker(&stack_a) == 1 && stack_b_checker(&stack_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), check_err);
}
