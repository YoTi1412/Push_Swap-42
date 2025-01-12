/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 04:37:52 by yrafai            #+#    #+#             */
/*   Updated: 2025/01/06 04:37:54 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"

int		apply_rarb(t_list **a, t_list **b, int c, char s);
int		apply_rrarrb(t_list **a, t_list **b, int c, char s);
int		apply_rrarb(t_list **a, t_list **b, int c, char s);
int		apply_rarrb(t_list **a, t_list **b, int c, char s);

int		min_number(t_list *a);
int		max_number(t_list *a);
int		find_index(t_list *a, int number);
int		find_place_a(t_list *stack_a, int nbr_push);
int		find_place_b(t_list *stack_b, int nbr_push);

int		check_args(char **argv);
int		check_dup(t_list *a);
int		check_sorted(t_list *stack_a);
int		check_error(char **argv, int i, int j);
int		validate_char(char **argv, int i, int *j);
int		ft_isdigit_str(const char *str);
void	ft_validate_args(int argc, char **argv, t_list **a);

void	sa(t_list **a, int j);
void	ra(t_list **a, int j);
void	rra(t_list **a, int j);
void	pa(t_list **a, t_list **b, int j);
void	ss(t_list **a, t_list **b, int j);
void	rr(t_list **a, t_list **b, int j);
void	rrr(t_list **a, t_list **b, int j);
void	rrr_helper(t_list **b, int j);
void	pb(t_list **stack_a, t_list **stack_b, int j);
void	rrb(t_list **b, int j);
void	rb(t_list **b, int j);
void	sb(t_list **b, int j);

t_list	*process(int argc, char **argv);
t_list	*process_numbers(char **numbers, t_list *a);

int		case_rarb(t_list *a, t_list *b, int c);
int		case_rrarrb(t_list *a, t_list *b, int c);
int		case_rrarb(t_list *a, t_list *b, int c);
int		case_rarrb(t_list *a, t_list *b, int c);

int		case_rarb_a(t_list *a, t_list *b, int c);
int		case_rrarrb_a(t_list *a, t_list *b, int c);
int		case_rarrb_a(t_list *a, t_list *b, int c);
int		case_rrarb_a(t_list *a, t_list *b, int c);

void	ft_sort(t_list **stack_a);
t_list	*sort_b(t_list **stack_a);
t_list	**sort_a(t_list **stack_a, t_list **stack_b);
void	sort_b_till_3(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);

int		rotate_ab(t_list *a, t_list *b);
int		rotate_ba(t_list *a, t_list *b);

void	check_sub(t_list **a, t_list **b, char *line);
char	*ft_check(t_list **a, t_list **b, char *line);
void	ft_checker_sub(t_list **a, t_list **b, char *line);

#endif
