/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:50:46 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/13 15:56:35 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

int	is_number_valid(long n)
{
	return (!(n > INT_MAX || n < INT_MIN));
}

int	is_input_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			;
		else if (ft_issign(str[i]))
		{
			if (i == 0)
				;
			else if (str[i - 1] == ' ')
				;
			else
				return (0);
		}
		else if (str[i] == ' ')
			;
		else
			return (0);
		i++;
	}
	return (1);
}
