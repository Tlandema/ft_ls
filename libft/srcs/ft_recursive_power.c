/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 11:58:31 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/08 12:56:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_recursive_power(long double nb, int power)
{
	if (power < 0.0)
		return (0.0);
	if (power == 0.0)
		return (1.0);
	if (nb == 0.0)
		return (0.0);
	return (nb * ft_recursive_power(nb, power - 1));
}
