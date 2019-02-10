/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:06:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:10:11 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	print_gap(t_arr *arr, char c, int len, int update_len)
{
	char *str;

	if (len > 0)
	{
		if (update_len)
			arr->size = arr->size + len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		ft_putstr(str);
		free(str);
	}
}
