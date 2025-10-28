/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:10:16 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/28 15:51:21 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker_bonus.h"

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
		//GET OPERATIONS FROM THE THE PUSHSWAP AND APPLY THEM
		if (is_sorted(stack_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(stack_a);
	}
	return (0);
}