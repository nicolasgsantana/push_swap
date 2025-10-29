/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:39:14 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/29 16:09:32 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void exec_op(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "ra", 2))
		ra(stack_a, 0);
	else if (!ft_strncmp(op, "rb", 2))
		rb(stack_b, 0);
	else if (!ft_strncmp(op, "rr", 2))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "sa", 2))
		sa(stack_a, 0);
	else if (!ft_strncmp(op, "sb", 2))
		sb(stack_b, 0);
	else if (!ft_strncmp(op, "ss", 2))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "pa", 2))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "pb", 2))
		pb(stack_b, stack_b, 0);
	else if (!ft_strncmp(op, "rra", 3))
		rra(stack_a, 0);
	else if (!ft_strncmp(op, "rrb", 3))
		rrb(stack_b, 0);
	else if (!ft_strncmp(op, "rrr", 3))
		rrr(stack_a, stack_b, 0);
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
