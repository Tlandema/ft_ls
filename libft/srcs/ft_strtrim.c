/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:12:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/09 16:45:28 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s) - 1;
	if (i != j + 1)
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
	if (!(s2 = ft_strnew(j - i + 1)))
		return (NULL);
	k = 0;
	while (i <= j)
		s2[k++] = s[i++];
	return (s2);
}
