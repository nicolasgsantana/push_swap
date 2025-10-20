/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:54:09 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/20 15:12:23 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list *stack)
{
	int		max;
	int		value;
	t_list	*tmp;

	max = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		value = *(int *)tmp->content;
		if (value > max)
			max = value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_list *stack)
{
	int		min;
	int		value;
	t_list	*tmp;

	min = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		value = *(int *)tmp->content;
		if (value < min)
			min = value;
		tmp = tmp->next;
	}
	return (min);
}

int	is_sorted(t_list *stack)
{
	t_list	*tmp;
	int		current_val;
	int		next_val;
	
	tmp = stack;
	while (tmp->next)
	{
		current_val = *(int *)tmp->content;
		next_val = *(int *)(tmp->next)->content;
		if (current_val > next_val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
int	find_index(t_list *stack, int value)
{
	t_list	*tmp;
	int	index;
	int	i;

	tmp = stack;
	index = -1;
	i = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == value)
		{
			index = i;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}

void	sort_three(t_list **stack_a)
{
	if (get_min(*stack_a) == *(int *)(*stack_a)->content)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (get_max(*stack_a) == *(int *)(*stack_a)->content)
	{
		ra(stack_a);
		if (!is_sorted(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (find_index(*stack_a, get_min(*stack_a)) == 1)
			sa(stack_a);
		else
			rra(stack_a);
	}
}
