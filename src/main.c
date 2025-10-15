/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:04:14 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/15 10:29:08 by nde-sant         ###   ########.fr       */
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

	stack_a = NULL;
	if (argc >= 2)
	{
		if (!is_input_valid(argc, argv))
			return (error());
		init_stack(argc, argv, &stack_a);
		while (stack_a)
		{
			ft_printf("%d\n", (*(int *)stack_a -> content));
			stack_a = stack_a -> next;
		}
	}
	return (0);
}
