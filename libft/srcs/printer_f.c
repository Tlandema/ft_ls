/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:52:25 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:07:43 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static long double	num_is(t_arr *arr)
{
	long double	num;

	if (ft_strcmp(arr->args_flags, "L") == 0)
		num = va_arg(arr->args, long double);
	else
		num = va_arg(arr->args, double);
	return (num);
}

static char			get_neg_holder(t_arr *arr, int is_neg)
{
	if (is_neg)
		return ('-');
	if (arr->tab_of_f[0] == '+')
		return ('+');
	return ('\0');
}

static t_arr		*make_f(t_arr *arr, char *str, int len_width, int r_or_l)
{
	int		unblank;
	char	neg_holder;
	int		is_neg;

	is_neg = (str[0] == '-') ? 1 : 0;
	neg_holder = get_neg_holder(arr, is_neg);
	unblank = len_width;
	if (len_width <= arr->preci && arr->preci >= 0)
		unblank = arr->preci;
	if (neg_holder == '+')
		unblank++;
	arr->size += (unblank <= arr->width) ? arr->width : unblank;
	if (!r_or_l && arr->tab_of_f[0] == '\0' && arr->tab_of_f[4] == '\0')
		print_gap(arr, ' ', arr->width - unblank, 0);
	if (neg_holder)
		ft_putchar(neg_holder);
	if (!r_or_l && arr->tab_of_f[4] == '0' && arr->preci == 6)
		print_gap(arr, '0', arr->width - unblank, 0);
	print_gap(arr, '0', arr->preci - len_width, 0);
	ft_putstr((str[0] == '-') ? &str[1] : str);
	if (r_or_l)
		print_gap(arr, ' ', arr->width - unblank, 0);
	return (arr);
}

t_arr				*printer_f(t_arr *arr)
{
	long double num;
	char		str[400];
	int			len_width;

	num = num_is(arr);
	if (arr->preci == -1)
		arr->preci = 6;
	ft_ftoa(num, str, arr->preci);
	len_width = ft_strlen(str);
	if (arr->tab_of_f[4] == '0' && arr->preci == -1 && !arr->tab_of_f[0])
	{
		arr->preci = arr->width;
		if (num < 0 || arr->tab_of_f[0] || arr->tab_of_f[1] || arr->tab_of_f[2])
			arr->preci--;
	}
	make_f(arr, str, len_width, (arr->tab_of_f[1] == '-') ? 1 : 0);
	return (arr);
}
