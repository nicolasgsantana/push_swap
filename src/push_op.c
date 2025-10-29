/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:08:49 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/29 11:15:11 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*next_b;

	if (!*stack_b)
		return ;
	next_b = (*stack_b)->next;
	if (!*stack_a)
	{
		ft_lstadd_front(stack_a, *stack_b);
		(*stack_a)->next = NULL;
	}
	else
		ft_lstadd_front(stack_a, *stack_b);
	*stack_b = next_b;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*next_a;

	if (!*stack_a)
		return ;
	next_a = (*stack_a)->next;
	if (!*stack_b)
	{
		ft_lstadd_front(stack_b, *stack_a);
		(*stack_b)->next = NULL;
	}
	else
		ft_lstadd_front(stack_b, *stack_a);
	*stack_a = next_a;
	if (print)
		ft_printf("pb\n");
}
