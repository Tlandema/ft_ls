/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:34:17 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/09 16:45:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel(int i, char ***tab)
{
	if (tab == NULL)
		return ((void)0);
	while (i >= 0)
	{
		ft_strclr((*tab)[i]);
		ft_strdel(&(*tab)[i]);
		i--;
	}
	free(*tab);
	*tab = NULL;
}
