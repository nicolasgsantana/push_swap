/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:06:03 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/29 11:17:35 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	sa(t_list **stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_list **stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}
