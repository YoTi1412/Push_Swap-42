/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <yrafai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:02:45 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/18 15:47:18 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	int		i;
	int		index;

	i = 0;
	index = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	final = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!final)
		return (NULL);
	while (s1[i])
		final[index++] = s1[i++];
	final[index++] = ' ';
	i = 0;
	while (s2[i])
		final[index++] = s2[i++];
	final[index] = '\0';
	return (final);
}

int	stack_init_mult(char **v, t_list **stack)
{
	char	*final;
	char	*tmp;
	int		err;
	int		i;

	if (!v || !stack)
		return (1);
	err = 0;
	i = 0;
	final = NULL;
	while (v[i])
	{
		tmp = final;
		final = ft_strjoin(final, v[i]);
		if (!final)
			return (free(tmp), 1);
		free(tmp);
		i++;
	}
	err += stack_init(final, stack, 1);
	return (err);
}

int	ft_error(t_list **stack, char *str, int args, char **splite)
{
	int	n;

	if (!splite)
		return (1);
	n = ft_count(str, ' ');
	ft_free(splite, n);
	if (args == 1)
		free(str);
	ft_lstclear(stack);
	return (1);
}

int	stack_init(char *str, t_list **stack, int args)
{
	char	**numbers;
	int		i;
	int		err_check;

	i = 0;
	err_check = 0;
	numbers = ft_split(str, ' ');
	if (!numbers || !stack)
		return (ft_error(stack, str, args, numbers));
	while (numbers[i])
	{
		if (ft_overflow(numbers[i]) || err_check > 0)
			return (ft_error(stack, str, args, numbers));
		err_check += ft_addback(stack, ft_addnew(ft_atol(numbers[i])));
		i++;
	}
	ft_free(numbers, i);
	if (args == 1)
		free(str);
	return (err_check);
}
