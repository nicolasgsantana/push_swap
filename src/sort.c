/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:28:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/24 17:28:08 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_a > 0 && cost_b > 0)
			rr(stack_a, stack_b);
		else if (cost_a < 0 && cost_b < 0)
			rrr(stack_a, stack_b);
		if (cost_a > 0)
			ra(stack_a);
		else if (cost_a < 0)
			rra(stack_a);
		if (cost_b > 0)
			rb(stack_b);
		else if (cost_b < 0)
			rrb(stack_b);
		if (cost_a > 0)
			cost_a--;
		else if (cost_a < 0)
			cost_a++;
		if (cost_b > 0)
			cost_b--;
		else if (cost_b < 0)
			cost_b++;
	}
	pb(stack_a, stack_b);
}

void	to_stack_b(t_list **stack_a, t_list **stack_b, int item)
{
	int	cost_a;
	int	cost_b;

	cost_a = cost_to_top(item, *stack_a);
	cost_b = cost_to_top(find_closest_lower(item, *stack_b), *stack_b);
	move_to_b(stack_a, stack_b, cost_a, cost_b);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if (ft_lstsize(*stack_b) < 2)
			pb(stack_a, stack_b);
		else
			to_stack_b(stack_a, stack_b, get_lowest_cost_item(*stack_a, *stack_b));
	}
	sort_three(stack_a);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b);
}
