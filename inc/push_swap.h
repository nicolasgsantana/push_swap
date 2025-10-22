/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:03:19 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/22 16:15:55 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

int		is_input_valid(int argc, char **argv);
void	init_stack(int argc, char **argv, t_list **stack);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack);
int		find_index(t_list *stack, int value);
void	sort_three(t_list **stack_a);
void	sort(t_list **stack_a, t_list **stack_b);
int		get_max(t_list *stack);
int		get_min(t_list *stack);
int		ft_abs(int n);
int		ft_abs_diff(int n1, int n2);

// FOR DEBUGGING ONLY
// TO BE REMOVED BEFORE EVALUATIONS
// REMEMBER TO REMOVE FROM MAKEFILE TOO
void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif
