/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:35:29 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/20 11:22:47 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		nb_a;
	int		nb_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	nb_a = 0;
	nb_b = 0;
	ft_printf("Stack\nA |B \n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			nb_a = *(int *)tmp_a->content;
			tmp_a = tmp_a->next;
		}
		if (tmp_b)
		{
			nb_b = *(int *)tmp_b->content;
			tmp_b = tmp_b->next;
		}
		ft_printf("%d  %d\n", nb_a, nb_b);
	}
}
