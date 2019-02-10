/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:48:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:09:20 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_arr	*choose_printer(t_arr *arr)
{
	if (arr->what_it_is == 'c' || arr->what_it_is == '%')
		printer_c(arr);
	if (arr->what_it_is == 'd' || arr->what_it_is == 'i')
		printer_int(arr);
	if (arr->what_it_is == 's' || arr->what_it_is == 'S')
		printer_string(arr);
	if (arr->what_it_is == 'p')
		printer_pointer(arr);
	if (arr->what_it_is == 'u')
		printer_u(arr);
	if (arr->what_it_is == 'o')
		printer_o(arr);
	if (arr->what_it_is == 'x' || arr->what_it_is == 'X')
		printer_x(arr);
	if (arr->what_it_is == 'f' || arr->what_it_is == 'F')
		printer_f(arr);
	return (arr);
}
