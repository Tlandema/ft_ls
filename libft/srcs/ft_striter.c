/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:57:35 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/09 16:43:49 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int		i;

	if (f != NULL && s != NULL)
	{
		i = 0;
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
	}
}
