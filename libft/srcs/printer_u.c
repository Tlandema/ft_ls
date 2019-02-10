/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:59:37 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:08:23 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned long long	num_is(t_arr *arr)
{
	unsigned long long int	num;

	if (ft_strcmp(arr->args_flags, "hh") == 0)
		num = (va_arg(arr->args, unsigned int));
	else if (ft_strcmp(arr->args_flags, "h") == 0)
		num = (va_arg(arr->args, unsigned int));
	else if (ft_strcmp(arr->args_flags, "ll") == 0)
		num = (va_arg(arr->args, unsigned long long int));
	else if (ft_strcmp(arr->args_flags, "l") == 0)
		num = (va_arg(arr->args, unsigned long int));
	else
		num = (va_arg(arr->args, unsigned int));
	num = (unsigned long long int)num;
	return (num);
}

static int					get_tens(unsigned long long int num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_arr				*make_u(t_arr *arr, unsigned long long int num,
		int len_width, int r_or_l)
{
	int		unblank;

	unblank = len_width;
	if (len_width <= arr->preci)
		unblank = arr->preci;
	arr->size += (unblank <= arr->width) ? arr->width : unblank;
	if (!r_or_l)
		print_gap(arr, ' ', arr->width - unblank, 0);
	print_gap(arr, '0', arr->preci - len_width, 0);
	ft_big_putnbr(num);
	if (r_or_l)
		print_gap(arr, ' ', arr->width - unblank, 0);
	return (arr);
}

t_arr						*printer_u(t_arr *arr)
{
	unsigned long long int	num;
	int						len_width;
	int						r_or_l;

	r_or_l = 0;
	num = num_is(arr);
	if (num == 0 && arr->preci == 0)
	{
		print_gap(arr, ' ', arr->width, 1);
		return (arr);
	}
	len_width = get_tens(num);
	if (arr->tab_of_f[1] == '-')
		r_or_l = 1;
	if (arr->tab_of_f[4] == '0' && arr->preci == -1 && !arr->tab_of_f[1])
		arr->preci = arr->width;
	make_u(arr, num, len_width, r_or_l);
	return (arr);
}
