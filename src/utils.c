/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:01:16 by nde-sant          #+#    #+#             */
/*   Updated: 2025/10/27 15:24:22 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
