/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:24:33 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:40:38 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	max;
	size_t	s_src;
	size_t	s_dst;

	s_src = ft_strlen(src);
	s_dst = ft_strlen(dst);
	max = size - s_dst - 1;
	if (size <= s_dst)
		return (s_src + size);
	else
		ft_strncat(dst, src, max);
	return (s_dst + s_src);
}
