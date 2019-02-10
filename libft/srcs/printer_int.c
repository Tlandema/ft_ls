/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:42:56 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:07:50 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long long int	num_is(t_arr *arr)
{
	long long int	num;

	if (arr->tab_of_f[4] == '0' && arr->tab_of_f[1] == '-')
		arr->tab_of_f[4] = '\0';
	if (ft_strcmp(arr->args_flags, "hh") == 0)
		num = (char)(va_arg(arr->args, int));
	else if (ft_strcmp(arr->args_flags, "h") == 0)
		num = (short)(va_arg(arr->args, int));
	else if (ft_strcmp(arr->args_flags, "ll") == 0)
		num = (va_arg(arr->args, long long int));
	else if (ft_strcmp(arr->args_flags, "l") == 0)
		num = (va_arg(arr->args, long int));
	else
		num = (va_arg(arr->args, int));
	num = (long long int)num;
	return (num);
}

static int				get_tens(long long int num)
{
	int	tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char				get_neg_holder(t_arr *arr, int is_neg)
{
	if (is_neg)
		return ('-');
	if (arr->tab_of_f[0] == '+')
		return ('+');
	if (arr->tab_of_f[2] == ' ')
		return (' ');
	return ('\0');
}

static t_arr			*make_int(t_arr *arr, long long int num
		, int len_width, int r_or_l)
{
	int		unblank;
	char	neg_holder;
	int		is_neg;

	is_neg = (num < 0) ? 1 : 0;
	num *= (is_neg) && num != (-9223372036854775807 - 1) ? -1 : 1;
	neg_holder = get_neg_holder(arr, is_neg);
	unblank = len_width;
	if (len_width <= arr->preci && arr->preci >= 0)
		unblank = arr->preci;
	if (neg_holder)
		unblank++;
	arr->size += (unblank <= arr->width) ? arr->width : unblank;
	if (!r_or_l && arr->tab_of_f[0] == '\0')
		print_gap(arr, ' ', arr->width - unblank, 0);
	if (neg_holder)
		ft_putchar(neg_holder);
	if (!r_or_l && arr->tab_of_f[0] == '+' && arr->preci == -1)
		print_gap(arr, '0', arr->width - unblank, 0);
	print_gap(arr, '0', arr->preci - len_width, 0);
	if (num != (-9223372036854775807 - 1))
		ft_big_putnbr(num);
	if (r_or_l)
		print_gap(arr, ' ', arr->width - unblank, 0);
	return (arr);
}

t_arr					*printer_int(t_arr *arr)
{
	long long int	num;
	int				len_width;

	num = num_is(arr);
	if (num == 0 && arr->preci == 0)
	{
		if (arr->tab_of_f[0] == '+')
			ft_putchar('+');
		if (arr->tab_of_f[2] == ' ')
			ft_putchar(' ');
		print_gap(arr, ' ', arr->width, 1);
		return (arr);
	}
	len_width = get_tens(num);
	if (arr->tab_of_f[1] == '\0' && arr->tab_of_f[0] == '+' \
			&& arr->preci > 0)
		print_gap(arr, ' ', arr->preci - 1, 0);
	if (arr->tab_of_f[4] == '0' && arr->preci == -1 && !arr->tab_of_f[0])
	{
		arr->preci = arr->width;
		if (num < 0 || arr->tab_of_f[0] || arr->tab_of_f[1] || arr->tab_of_f[2])
			arr->preci--;
	}
	make_int(arr, num, len_width, (arr->tab_of_f[1] == '-') ? 1 : 0);
	return (arr);
}
