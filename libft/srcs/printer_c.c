/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:19:19 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:06:42 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_arr	*printer_c(t_arr *arr)
{
	char c;

	if (arr->what_it_is == 'c')
		c = (char)va_arg(arr->args, int);
	if (arr->tab_of_f[4] == '0' && arr->tab_of_f[1] != '-')
		print_gap(arr, '0', arr->width - 1, 1);
	else if (arr->tab_of_f[1] != '-')
		print_gap(arr, ' ', arr->width - 1, 1);
	arr->size += 1;
	if (arr->what_it_is == 'c')
		ft_putchar(c);
	else if (arr->what_it_is == '%')
		ft_putchar('%');
	if (arr->tab_of_f[1] == '-')
		print_gap(arr, ' ', arr->width - 1, 1);
	return (arr);
}
