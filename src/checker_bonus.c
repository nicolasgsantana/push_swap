/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:10:16 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/03 12:15:20 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		execute_operations(commands, &stack_a, &stack_b);
		if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(stack_a);
		free_stack(stack_b);
		free_matrix(commands);
	}
	return (0);
}
