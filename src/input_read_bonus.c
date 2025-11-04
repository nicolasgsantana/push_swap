/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:55:40 by nde-sant          #+#    #+#             */
/*   Updated: 2025/11/04 15:52:13 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	*free_and_return_null(char *input)
{
	free(input);
	return (NULL);
}

int	is_op_valid(char *input)
{
	if (ft_strlen(input) == 4)
	{
		if (!ft_strncmp(input, "rra\n", 4) || !ft_strncmp(input, "rrb\n", 4))
			return (1);
		else if (ft_strncmp(input, "rrr\n", 4) == 0)
			return (1);
		else
			return (0);
	}
	else if (ft_strlen(input) == 3)
	{
		if (!ft_strncmp(input, "pa\n", 3) || !ft_strncmp(input, "pb\n", 3))
			return (1);
		if (!ft_strncmp(input, "sa\n", 3) || !ft_strncmp(input, "sb\n", 3))
			return (1);
		if (!ft_strncmp(input, "ra\n", 3) || !ft_strncmp(input, "rb\n", 3))
			return (1);
		if (!ft_strncmp(input, "rr\n", 3) || !ft_strncmp(input, "ss\n", 3))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	is_command_valid(char *input)
{
	int	len;

	len = 0;
	while (*input)
	{
		len++;
		if (*input == '\n' && *(input + 1))
			len = 0;
		input++;
	}
	return (is_op_valid(input - len));
}

char	**read_input(void)
{
	char	c;
	char	buf[2];
	char	*input;
	char	*tmp;
	char	**commands;

	input = ft_calloc(sizeof(char), 1);
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		buf[0] = c;
		buf[1] = '\0';
		tmp = input;
		input = ft_strjoin(tmp, buf);
		free(tmp);
		if (c == '\n')
			if (!is_command_valid(input))
				return (free_and_return_null(input));
	}
	commands = ft_split(input, '\n');
	free(input);
	return (commands);
}
