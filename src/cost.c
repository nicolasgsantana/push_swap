/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:35:11 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/27 15:31:14 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_lower(int item, t_list *stack)
{
	t_list	*tmp;
	int		closest;
	int		n;

	if (item < get_min(stack))
		return (get_max(stack));
	tmp = stack;
	closest = INT_MIN;
	while(tmp)
	{
		n = *(int *)tmp->content;
		if (n < item && n > closest)
				closest = n;
		tmp = tmp->next;
	}
	return (closest);
}

int	find_closest_higher(int item, t_list *stack)
{
	t_list	*tmp;
	int		closest;
	int		n;

	if (item > get_max(stack))
		return (get_min(stack));
	tmp = stack;
	closest = INT_MAX;
	while (tmp)
	{
		n = *(int *)tmp->content;
		if (n > item && n < closest)
				closest = n;
		tmp = tmp->next;
	}
	return (closest);
}

int	cost_to_top(int item, t_list *stack)
{
	int	index;
	int	stack_size;

	index = find_index(stack, item);
	if (index == -1)
		return (INT_MAX);
	stack_size = ft_lstsize(stack);
	if (index > (stack_size / 2))
		return (index - stack_size);
	else
		return (index);
}

int	get_lowest_cost_item(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	int		lowest_cost_item;
	int		n;
	int		cost_a;
	int		cost_b;
	int		total_cost;
	int		current_lowest;

	current_lowest = INT_MAX;
	tmp_a = stack_a;
	while (tmp_a)
	{
		n = *(int *)tmp_a->content;
		cost_a = cost_to_top(n, stack_a);
		cost_b = cost_to_top(find_closest_lower(n, stack_b), stack_b);
		if (cost_a > 0 && cost_b > 0)
			total_cost = ft_max(cost_a, cost_b);
		else if (cost_a < 0 && cost_b < 0)
			total_cost = ft_abs(ft_min(cost_a, cost_b));
		else
			total_cost = ft_abs(cost_a) + ft_abs(cost_b) + 1;
		if (total_cost < current_lowest)
		{
			current_lowest = total_cost;
			lowest_cost_item = n;
		}
		tmp_a = tmp_a->next;
	}
	return (lowest_cost_item);
}
