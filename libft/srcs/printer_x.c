/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:55:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:08:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "stdlib.h"

static void					print_zero_x(unsigned long long num, t_arr *arr)
{
	if (num)
	{
		if (arr->tab_of_f[3] == '#' && arr->what_it_is == 'x')
			ft_putstr("0x");
		if (arr->tab_of_f[3] == '#' && arr->what_it_is == 'X')
			ft_putstr("0X");
	}
}

static unsigned long long	is_num(t_arr *arr)
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

static t_arr				*make_x(t_arr *arr, unsigned long long int num,
		char *str, int r_or_l)
{
	int n_b;
	int n_w;

	if ((n_w = ft_strlen(str)) && arr->tab_of_f[3] == '#' && num
			&& arr->tab_of_f[4] == '0' && arr->width)
		n_w = n_w + 2;
	else if ((n_w = ft_strlen(str)) && arr->tab_of_f[3] == '#' && num)
	{
		arr->width -= 2;
		arr->size += 2;
	}
	n_b = (n_w <= arr->preci && arr->preci > 0) ? arr->preci : n_w;
	arr->size += (n_b <= arr->width) ? arr->width : n_b;
	if (!r_or_l)
		print_gap(arr, ' ', arr->width - n_b, 0);
	print_zero_x(num, arr);
	print_gap(arr, '0', arr->preci - n_w, 0);
	ft_putstr(str);
	if (r_or_l)
		print_gap(arr, ' ', arr->width - n_b, 0);
	return (arr);
}

t_arr						*printer_x(t_arr *arr)
{
	char					*str;
	unsigned long long int	num;

	num = is_num(arr);
	if (arr->tab_of_f[1] == '-' && arr->tab_of_f[4] == '0')
		arr->tab_of_f[4] = '\0';
	if (num == 0 && arr->preci == 0)
	{
		print_gap(arr, ' ', arr->width, 1);
		return (arr);
	}
	if (arr->what_it_is == 'X')
	{
		if (!(str = ft_itoa_ubase(num, "0123456789ABCDEF")))
			exit(-1);
	}
	else if (!(str = ft_itoa_ubase(num, "0123456789abcdef")))
		exit(-1);
	if (arr->tab_of_f[4] == '0' && arr->preci == -1 && !arr->tab_of_f[1])
		arr->preci = arr->width;
	make_x(arr, num, str, (arr->tab_of_f[1] == '-') ? 1 : 0);
	free(str);
	return (arr);
}
