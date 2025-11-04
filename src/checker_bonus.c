/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:10:16 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/04 15:54:49 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_all(t_list *stack_a, t_list *stack_b, char **commands)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_matrix(commands);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**commands;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (!is_input_valid(argc, argv))
			error();
		init_stack(argc, argv, &stack_a);
		commands = read_input();
		if (!commands)
		{
			free_all(stack_a, stack_b, commands);
			error();
		}
		execute_operations(commands, &stack_a, &stack_b);
		if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_all(stack_a, stack_b, commands);
	}
	return (0);
}
