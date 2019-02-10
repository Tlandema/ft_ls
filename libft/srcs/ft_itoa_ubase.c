/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:14:18 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:29:01 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long ul, int b_size)
{
	int		i;

	i = 1;
	while (ul >= (unsigned long long)b_size)
	{
		ul /= b_size;
		i++;
	}
	return (i);
}

char		*ft_itoa_ubase(unsigned long long ul, char *base)
{
	int					size;
	int					b_size;
	char				*s;

	b_size = ft_strlen(base);
	size = (get_size(ul, b_size));
	if (!(s = ft_strnew(size)))
		return (NULL);
	while (size > 0)
	{
		s[size - 1] = base[ul % b_size];
		ul /= b_size;
		size--;
	}
	return (s);
}
