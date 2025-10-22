/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:01:16 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/22 16:24:38 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_abs_diff(int n1, int n2)
{
	int	abs_n1;
	int	abs_n2;

	abs_n1 = ft_abs(n1);
	abs_n2 = ft_abs(n2);
	return (ft_abs(abs_n1 - abs_n2));
}
