/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:22:41 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:08:00 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static void				print_zero(long long int num, t_arr *arr)
{
	if (arr->tab_of_f[3] == '#' && num)
		ft_putchar('0');
}

static long long int	is_num(t_arr *arr)
{
	unsigned long long int	num;

	if (ft_strcmp(arr->args_flags, "hh") == 0)
		num = (unsigned char)(va_arg(arr->args, unsigned int));
	else if (ft_strcmp(arr->args_flags, "h") == 0)
		num = (unsigned short)(va_arg(arr->args, unsigned int));
	else if (ft_strcmp(arr->args_flags, "ll") == 0)
		num = (va_arg(arr->args, unsigned long long int));
	else if (ft_strcmp(arr->args_flags, "l") == 0)
		num = (va_arg(arr->args, unsigned long int));
	else
		num = (va_arg(arr->args, unsigned int));
	num = (unsigned long long int)num;
	return (num);
}

static t_arr			*print_o(t_arr *arr, unsigned long long int num,
		char *str, int r_or_l)
{
	int	unblank;
	int	len_width;

	len_width = ft_strlen(str);
	if (arr->tab_of_f[3] == '#' && num)
		len_width++;
	unblank = len_width;
	if (len_width <= arr->preci && arr->preci > 0)
		unblank = arr->preci;
	arr->size += (unblank <= arr->width) ? arr->width : unblank;
	if (!r_or_l)
		print_gap(arr, ' ', arr->width - unblank, 0);
	print_zero(num, arr);
	print_gap(arr, '0', arr->preci - len_width, 0);
	ft_putstr(str);
	free(str);
	if (r_or_l)
		print_gap(arr, ' ', arr->width - unblank, 0);
	return (arr);
}

t_arr					*printer_o(t_arr *arr)
{
	char					*str;
	unsigned long long int	num;
	int						r_or_l;

	r_or_l = 0;
	num = is_num(arr);
	if (num == 0 && arr->preci == 0 && arr->tab_of_f[3] != '#')
	{
		print_gap(arr, ' ', arr->width, 1);
		return (arr);
	}
	if (!(str = ft_itoa_ubase(num, "01234567")))
		exit(-1);
	if (arr->tab_of_f[1] == '-')
		r_or_l = 1;
	if (arr->tab_of_f[4] == '0' && arr->preci == -1 && !arr->tab_of_f[1])
		arr->preci = arr->width;
	print_o(arr, num, str, r_or_l);
	return (arr);
}
