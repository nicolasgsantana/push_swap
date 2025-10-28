/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:04:14 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/28 13:55:42 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
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

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (!is_input_valid(argc, argv))
			return (error());
		init_stack(argc, argv, &stack_a);
		if (!is_sorted(stack_a))
			sort(&stack_a, &stack_b);
		free_stack(stack_a);
	}
	return (0);
}
