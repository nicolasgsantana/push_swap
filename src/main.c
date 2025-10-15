/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:04:14 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/15 15:46:48 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (!is_input_valid(argc, argv))
			return (error());
		init_stack(argc, argv, &stack_a);
		rra(&stack_a);
		rra(&stack_a);
		rra(&stack_a);
		tmp = stack_a;
		ft_printf("Stack A\n");
		while (tmp)
		{
			ft_printf("%d\n", (*(int *)tmp -> content));
			tmp = tmp -> next;
		}
		tmp = stack_b;
		ft_printf("Stack B\n");
		while (tmp)
		{
			ft_printf("%d\n", (*(int *)tmp -> content));
			tmp = tmp -> next;
		}
	}
	return (0);
}
