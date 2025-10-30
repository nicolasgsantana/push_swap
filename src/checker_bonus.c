/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:10:16 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/30 13:48:40 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker_bonus.h"

static void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	ft_lstiter(stack, free);
	while(stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
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
		execute_operations(commands, &stack_a, &stack_b);
		if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(stack_a);
	}
	return (0);
}
