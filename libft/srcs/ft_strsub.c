/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:57:44 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:42:27 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(s2 = ft_strnew(len)))
		return (NULL);
	while (i < len)
		s2[i++] = s[start++];
	return (s2);
}
