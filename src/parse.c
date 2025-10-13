/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:46:11 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/13 15:58:23 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(int argc, char **argv, t_list *stack)
{
	int		i;
	char	**inputs;

	if (argc == 2)
		inputs = ft_split(argv[1], ' ');
	else if (argc > 2)
		inputs = ++argv;
	else
		return ;
	i = 0;
	while (inputs[i])
	{
		if (is_input_valid(inputs[i]))
		{
			if (is_number_valid(ft_atol(inputs[i])))
				;
			else
				ft_putstr_fd("Error\n", STDERR_FILENO);
		}
		else
			ft_putstr_fd("Error\n", STDERR_FILENO);
	}
}
