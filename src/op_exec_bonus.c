/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:39:14 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/30 13:49:18 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void exec_op(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "rra", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(op, "rrb", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(op, "rrr", 4))
		rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "ra", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(op, "rb", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(op, "rr", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "sa", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(op, "sb", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(op, "ss", 3))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "pa", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "pb", 3))
		pb(stack_a, stack_b, 0);
}

void	execute_operations(char **commands, t_list **stack_a, t_list **stack_b)
{
	int i;

	i = 0;
	while(commands[i])
	{
		exec_op(commands[i], stack_a, stack_b);
		i++;
	}
}
