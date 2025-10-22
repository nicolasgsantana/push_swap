/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:35:11 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/22 17:16:52 by nde-sant         ###   ########.fr       */
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
	closest = *(int *)tmp->content;
	while(tmp)
	{
		n = *(int *)tmp->content;
		if (n < item)
			if (ft_abs_diff(n, item) < ft_abs_diff(closest, item))
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
	closest = *(int *)tmp->content;
	while (tmp)
	{
		n = *(int *)tmp->content;
		if (n > item)
			if (ft_abs_diff(n, item) < ft_abs_diff(closest, item))
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

	lowest_cost_item = INT_MAX;
	tmp_a = stack_a;
	while (tmp_a)
	{
		n = *(int *)tmp_a->content;
		cost_a = cost_to_top(n, stack_a);
		cost_b = cost_to_top(find_closest_lower(n, stack_b), stack_b);
	}
}
