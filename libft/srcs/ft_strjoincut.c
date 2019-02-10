/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:54:16 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/07 13:04:44 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoincut(char *str1, char *str2, int c)
{
	char	*str3;
	int		i;

	i = 0;
	while (str2[i] != c && str2[i])
		i++;
	if (!(str3 = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	str3[i + 1] = '\0';
	while (i > 0)
	{
		str3[i] = str2[i];
		i--;
	}
	str1 = ft_strjoin(str1, str3);
	free(str3);
	return (str1);
}
