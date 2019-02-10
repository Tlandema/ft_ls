/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:29:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:28:10 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long l)
{
	int		i;

	i = 1;
	if (l < 0)
	{
		i++;
		l = -l;
	}
	while (l > 9)
	{
		l /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long	l;
	int		i;
	int		size;
	char	*s;

	i = 0;
	l = n;
	size = get_size(l);
	if (!(s = ft_strnew(size)))
		return (NULL);
	if (l < 0)
	{
		i++;
		l = -l;
		s[0] = '-';
	}
	while (size > i)
	{
		s[size - 1] = l % 10 + '0';
		l /= 10;
		size--;
	}
	return (s);
}
