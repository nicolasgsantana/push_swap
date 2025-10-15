/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:06:03 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/15 13:20:59 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack) -> next)
		return ;
	tmp = (*stack) -> next;
	(*stack) -> next = tmp -> next;
	tmp -> next = *stack;
	*stack = tmp;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
