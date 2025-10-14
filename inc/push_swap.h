/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:03:19 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/14 15:01:49 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

long	ft_atol(const char *nptr);
int		is_number_valid(long n);
int		ft_issign(int c);
int		is_string_valid(char *str);
int		is_there_a_duplicate(char **array);
int		is_input_valid(int argc, char **argv);

#endif
