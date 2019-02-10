/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:29:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/09 16:35:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse(char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int		int_to_str_l(long long x, char *str, long double true_n)
{
	int i;
	int d;

	d = 0;
	i = 0;
	if (x == 0)
		d = 1;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	if (true_n < 0.0)
		str[i++] = '-';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

void	ft_ftoa_helper(long double fpart, int i, int afterpoint, char *res)
{
	int count;

	count = -1;
	while (count++ < afterpoint - 1)
	{
		fpart = fpart * 10;
		res[i + count + 1] = (long long int)(fpart + 0.5) + '0';
		if ((long long int)(fpart + 0.5) != (long long int)fpart)
			res[i + count + 1] = (long long int)fpart + '0';
		fpart = fpart - (long long int)fpart;
	}
}

void	ft_ftoa(long double n, char *res, int afterpoint)
{
	long double		fpart;
	int				i;
	long long int	ipart;
	long double		true_n;
	int				count;

	i = 0;
	count = -1;
	true_n = n;
	if (n < 0.0)
		n = -n;
	ipart = (long long int)n;
	fpart = n - (long double)ipart;
	i = int_to_str_l(ipart, res, true_n);
	if (afterpoint != 0)
		res[i] = '.';
	true_n = fpart;
	while (count++ < afterpoint)
	{
		true_n = true_n * 10;
		if (count == afterpoint && true_n > 5.0)
			fpart = fpart + ft_recursive_power(0.1, afterpoint);
		true_n = true_n - (long long int)true_n;
	}
	ft_ftoa_helper(fpart, i, afterpoint, res);
}
