/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:09:54 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/30 14:21:26 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"

void	error(void);
int		is_input_valid(int argc, char **argv);
void	free_stack(t_list *stack);
void	free_matrix(char **matrix);
void	init_stack(int argc, char **argv, t_list **stack);
void	pa(t_list **stack_a, t_list **stack_b, int print);
void	pb(t_list **stack_a, t_list **stack_b, int print);
void	sa(t_list **stack_a, int print);
void	sb(t_list **stack_b, int print);
void	ss(t_list **stack_a, t_list **stack_b, int print);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b, int print);
void	rra(t_list **stack_a, int print);
void	rrb(t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b, int print);
int		is_sorted(t_list *stack);
char	**read_input(void);
void	execute_operations(char **commands, t_list **stack_a, t_list **stack_b);

#endif
