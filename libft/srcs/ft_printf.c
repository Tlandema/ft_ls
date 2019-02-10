/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:10:26 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:09:39 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

t_arr	*clean_and_init(t_arr *arr)
{
	arr->size = 0;
	arr->i = 0;
	arr->format_cpy = (char *)arr->format;
	arr->format_mdf = (char *)arr->format;
	arr->specifier_tab = "fscdiuoxbpFDUOX%";
	arr->converter_tab = "-+ 0#";
	arr->arguments_tab = "hlLjz";
	return (arr);
}

t_arr	*re_clean(t_arr *arr)
{
	arr->preci = -1;
	arr->width = 0;
	arr->what_it_is = '\0';
	arr->args_flags[0] = '\0';
	arr->args_flags[1] = '\0';
	arr->tab_of_f[0] = '\0';
	arr->tab_of_f[1] = '\0';
	arr->tab_of_f[2] = '\0';
	arr->tab_of_f[3] = '\0';
	arr->tab_of_f[4] = '\0';
	arr->tab_of_f[5] = '\0';
	return (arr);
}

int		modify(t_arr *arr)
{
	arr->i++;
	parse_flags(arr);
	parse_width(arr);
	parse_preci(arr);
	parse_arguments(arr);
	parse_what_it_is(arr);
	choose_printer(arr);
	return (arr->size);
}

int		parse_and_print(t_arr *arr)
{
	if (ft_strcmp(arr->format_cpy, "%") == 0)
		return (0);
	while (arr->format_cpy[arr->i] != '\0')
	{
		if (arr->format_cpy[arr->i] == '%')
		{
			re_clean(arr);
			modify(arr);
		}
		else
		{
			ft_putchar(arr->format_cpy[arr->i]);
			arr->size++;
		}
		arr->i++;
	}
	return (arr->size);
}

int		ft_printf(const char *format, ...)
{
	t_arr	*arr;
	int		ret;

	if (!(arr = (t_arr *)malloc(sizeof(t_arr))))
		return (-1);
	arr->format = format;
	arr = clean_and_init(arr);
	if (format)
	{
		va_start(arr->args, format);
		arr->size = parse_and_print(arr);
		va_end(arr->args);
	}
	ret = arr->size;
	free(arr);
	return (ret);
}
