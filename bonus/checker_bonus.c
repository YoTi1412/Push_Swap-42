/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:42:30 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/08 08:42:32 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_sub(t_list **a, t_list **b, char *line)
{
	if (line[2] == 'a')
		rra(a, 1);
	else if (line[2] == 'b')
		rrb(b, 1);
	else if (line[2] == 'r')
		rrr(a, b, 1);
  else
    ft_error_msg();
}

char	*ft_check(t_list **a, t_list **b, char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		ft_error_msg();
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b, 1);
	else
		ft_error_msg();
	return (get_next_line(0));
}

void	ft_checker_sub(t_list **a, t_list **b, char *line)
{
	char	*tmp;

	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			ft_error_msg();
		}
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		ft_printf("KO\n");
	else if (!check_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	b = NULL;
	a = process(argc, argv);
	if (argc < 2 || !a || check_dup(a))
	{
		ft_free(&a);
		return (0);
	}
	ft_validate_args(argc, argv, &a);
	line = get_next_line(0);
	if (!line)
	{
		if (!check_sorted(a))
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
	}
	else
		ft_checker_sub(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}
