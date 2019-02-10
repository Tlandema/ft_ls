/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 05:09:34 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 09:09:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_arr	*parse_what_it_is(t_arr *arr)
{
	int i;

	i = 0;
	while (arr->specifier_tab[i] != '\0')
	{
		if (arr->specifier_tab[i] == arr->format_mdf[arr->i])
			arr->what_it_is = arr->specifier_tab[i];
		i++;
	}
	return (arr);
}

t_arr	*parse_arguments(t_arr *arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arr->arguments_tab[i] != '\0')
	{
		while (arr->arguments_tab[i] == arr->format_mdf[arr->i])
		{
			arr->args_flags[j] = arr->format_mdf[arr->i];
			arr->args_flags[j + 1] = '\0';
			arr->i++;
			j++;
		}
		i++;
	}
	return (arr);
}

t_arr	*parse_preci(t_arr *arr)
{
	while (arr->format_mdf[arr->i] == '.')
	{
		arr->i++;
		arr->preci = 0;
	}
	while (arr->format_mdf[arr->i] >= '0' && arr->format_mdf[arr->i] <= '9')
	{
		arr->preci = arr->preci * 10;
		arr->preci = arr->preci + (arr->format_mdf[arr->i] - 48);
		arr->i++;
	}
	return (arr);
}

t_arr	*parse_width(t_arr *arr)
{
	while (arr->format_mdf[arr->i] >= '0' && arr->format_mdf[arr->i] <= '9')
	{
		arr->width = arr->width * 10;
		arr->width = arr->width + (arr->format_mdf[arr->i] - 48);
		arr->i++;
	}
	return (arr);
}

t_arr	*parse_flags(t_arr *arr)
{
	int i;

	i = 0;
	while (arr->converter_tab[i] != '\0')
	{
		while (arr->converter_tab[i] == arr->format_mdf[arr->i])
		{
			while (arr->format_mdf[arr->i] == '+' && arr->i++)
				arr->tab_of_f[0] = '+';
			while (arr->format_mdf[arr->i] == '-' && arr->i++)
				arr->tab_of_f[1] = '-';
			while (arr->format_mdf[arr->i] == ' ' && arr->i++)
				arr->tab_of_f[2] = ' ';
			while (arr->format_mdf[arr->i] == '#' && arr->i++)
				arr->tab_of_f[3] = '#';
			while (arr->format_mdf[arr->i] == '0' && arr->i++)
				arr->tab_of_f[4] = '0';
			i = 0;
		}
		i++;
	}
	return (arr);
}
