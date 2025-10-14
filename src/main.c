/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:04:14 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/14 15:46:51 by nde-sant         ###   ########.fr       */
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
	if (argc >= 2)
	{
		if (!is_input_valid(argc, argv))
			return (error());
		ft_printf("Input is valid\n");
	}
	return (0);
}
