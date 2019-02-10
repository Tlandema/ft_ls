/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:18:57 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:08:16 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

t_arr	*printer_string(t_arr *arr)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = va_arg(arr->args, char*)))
		str = "(null)";
	if (arr->preci > -1 && str)
		str = ft_strndup(str, arr->preci);
	else if (arr->preci == -1 && str)
		str = ft_strdup(str);
	arr->size = arr->size + ft_strlen(str);
	if (arr->tab_of_f[4] == '0' && arr->tab_of_f[1] != '-')
		print_gap(arr, '0', arr->width - ft_strlen(str), 1);
	else if (arr->tab_of_f[1] != '-')
		print_gap(arr, ' ', arr->width - ft_strlen(str), 1);
	ft_putstr(str);
	if (arr->tab_of_f[1] == '-')
		print_gap(arr, ' ', arr->width - ft_strlen(str), 1);
	free(str);
	return (arr);
}
