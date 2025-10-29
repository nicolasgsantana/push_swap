/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:28:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/29 11:20:44 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op_cost(t_list **stack, int *cost, void (*op)(t_list **, int))
{
	if (*cost > 0)
		*cost -= 1;
	else
		*cost += 1;
	op(stack, 1);
}

void	rot_stacks(t_list **stack_a, t_list **stack_b, int ca, int cb)
{
	while (ca != 0 || cb != 0)
	{
		if (ca > 0 && cb > 0)
		{
			rr(stack_a, stack_b, 1);
			ca--;
			cb--;
		}
		else if (ca < 0 && cb < 0)
		{
			rrr(stack_a, stack_b, 1);
			ca++;
			cb++;
		}
		else if (ca > 0)
			do_op_cost(stack_a, &ca, ra);
		else if (ca < 0)
			do_op_cost(stack_a, &ca, rra);
		else if (cb > 0)
			do_op_cost(stack_b, &cb, rb);
		else
			do_op_cost(stack_b, &cb, rrb);
	}
}

void	to_stack_b(t_list **stack_a, t_list **stack_b, int item)
{
	int	cost_a;
	int	cost_b;

	cost_a = cost_to_top(item, *stack_a);
	cost_b = cost_to_top(find_closest_lower(item, *stack_b), *stack_b);
	rot_stacks(stack_a, stack_b, cost_a, cost_b);
	pb(stack_a, stack_b, 1);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	item;

	while (ft_lstsize(*stack_a) > 3)
	{
		item = get_lowest_cost_item(*stack_a, *stack_b);
		if (ft_lstsize(*stack_b) < 2)
			pb(stack_a, stack_b, 1);
		else
			to_stack_b(stack_a, stack_b, item);
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (ft_lstsize(*stack_b))
	{
		item = find_closest_higher(*(int *)(*stack_b)->content, *stack_a);
		if (item == *(int *)(*stack_a)->content)
			pa(stack_a, stack_b, 1);
		else
			rot_stacks(stack_a, stack_b, cost_to_top(item, *stack_a), 0);
	}
	item = get_min(*stack_a);
	rot_stacks(stack_a, stack_b, cost_to_top(item, *stack_a), 0);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, 1);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b);
}
