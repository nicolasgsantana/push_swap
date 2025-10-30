/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:50:46 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/30 14:28:42 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	is_number_valid(long n)
{
	return (n <= (long)INT_MAX && n >= (long)INT_MIN);
}

int	is_string_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			;
		else if (ft_issign(str[i]))
		{
			if (i == 0 && ft_isdigit(str[i + 1]))
				;
			else if (str[i - 1] == ' ' && ft_isdigit(str[i + 1]))
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

int	is_there_a_duplicate(char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	free_matrix_return(char **matrix, int argc, int return_value)
{
	if (argc == 2)
		free_matrix(matrix);
	return (return_value);
}

int	is_input_valid(int argc, char **argv)
{
	int		i;
	char	**inputs;

	if (argc == 2 && argv[1][0])
		inputs = ft_split(argv[1], ' ');
	else if (argc > 2)
		inputs = ++argv;
	else
		return (0);
	i = 0;
	while (inputs[i])
	{
		if (!is_string_valid(inputs[i]))
			return (free_matrix_return(inputs, argc, 0));
		else if (!is_number_valid(ft_atol(inputs[i])))
			return (free_matrix_return(inputs, argc, 0));
		i++;
	}
	if (is_there_a_duplicate(inputs))
		return (free_matrix_return(inputs, argc, 0));
	return (free_matrix_return(inputs, argc, 1));
}
