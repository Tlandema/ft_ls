/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:46:11 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/08 17:17:45 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

typedef struct	s_arr
{
	const char	*format;
	char		*format_cpy;
	char		*format_mdf;
	va_list		args;
	int			size;
	size_t		i;
	int			preci;
	int			width;
	char		what_it_is;
	char		tab_of_f[6];
	char		args_flags[2];
	char		*specifier_tab;
	char		*converter_tab;
	char		*arguments_tab;
}				t_arr;

t_arr			*parse_what_it_is(t_arr *arr);
t_arr			*parse_width(t_arr *arr);
t_arr			*parse_flags(t_arr *arr);
t_arr			*parse_preci(t_arr *arr);
t_arr			*parse_arguments(t_arr *arr);

t_arr			*choose_printer(t_arr *arr);
t_arr			*printer_u(t_arr *arr);
t_arr			*printer_c(t_arr *arr);
t_arr			*printer_f(t_arr *arr);
t_arr			*printer_o(t_arr *arr);
t_arr			*printer_x(t_arr *arr);
t_arr			*printer_int(t_arr *arr);
t_arr			*printer_string(t_arr	*arr);
t_arr			*printer_pointer(t_arr *arr);

int				ft_printf(const char *format, ...);
void			print_gap(t_arr *arr, char c, int len, int update_len);

#endif
