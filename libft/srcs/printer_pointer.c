/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:59:05 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:08:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static unsigned long int	get_num(t_arr *arr)
{
	unsigned long int	num;

	num = va_arg(arr->args, unsigned long int);
	return (num);
}

static t_arr				*printing(t_arr *arr, char *str, int r_or_l)
{
	int	unblank;
	int	len_width;

	len_width = ft_strlen(str) + 2;
	unblank = len_width;
	arr->size += (unblank <= arr->width) ? arr->width : unblank;
	if (!r_or_l)
		print_gap(arr, ' ', arr->width - unblank, 0);
	ft_putchar('0');
	ft_putchar('x');
	ft_putstr(str);
	if (r_or_l)
		print_gap(arr, ' ', arr->width - unblank, 0);
	free(str);
	return (arr);
}

t_arr						*printer_pointer(t_arr *arr)
{
	char				*str;
	unsigned long int	num;
	int					r_or_l;

	r_or_l = 0;
	num = get_num(arr);
	if (!(str = ft_itoa_ubase(num, "0123456789abcdef")))
		exit(-1);
	if (arr->tab_of_f[1] == '-')
		r_or_l = 1;
	if (arr->preci == 0 && num == 0)
		*str = '\0';
	if (arr->tab_of_f[4] == '0' && arr->preci == -1 && !arr->tab_of_f[1])
	{
		arr->preci = arr->width - 2;
		arr->width = 0;
	}
	printing(arr, str, r_or_l);
	return (arr);
}
