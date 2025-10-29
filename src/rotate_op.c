/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:23:23 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/29 11:16:57 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*first_node;

	if (ft_lstsize(*stack) < 2)
		return ;
	first_node = *stack;
	*stack = (*stack)->next;
	first_node->next = NULL;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
}

void	ra(t_list **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_list **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_printf("rr\n");
}
