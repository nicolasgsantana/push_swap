/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:46:11 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/15 10:33:36 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_matrix(char **matrix, int argc)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}

void	init_stack(int argc, char **argv, t_list **stack)
{
	char	**inputs;
	t_list	*node;
	int		i;
	int		*content;

	if (argc == 2)
		inputs = ft_split(argv[1], ' ');
	else if (argc > 2)
		inputs = ++argv;
	i = 0;
	while (inputs[i])
	{
		content = malloc(sizeof(int) * 1);
		*content = ft_atoi(inputs[i]);
		node = ft_lstnew((void *)content);
		ft_lstadd_back(stack, node);
		i++;
	}
	free_matrix(inputs, argc);
}
