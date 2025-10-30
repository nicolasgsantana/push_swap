/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:20:26 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/30 14:27:46 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "libft.h"
# include <limits.h>

long	ft_atol(const char *nptr);
int		is_number_valid(long n);
int		ft_issign(int c);
int		is_string_valid(char *str);
int		is_there_a_duplicate(char **array);
void	free_matrix(char **matrix);

#endif
