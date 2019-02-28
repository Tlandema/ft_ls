/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 04:13:44 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/28 16:05:16 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_color(char **tab, int i)
{
	if (i == 1)
	{
		if (tab[0][0] == 'd')
			ft_putstr("\033[96m");
		else if (tab[0][3] == 'x' || tab[0][6] == 'x' || tab[0][9] == 'x')
			ft_putstr("\033[31m");
		if (tab[0][0] == 'c')
			ft_putstr("\033[34;43m");
		if (tab[0][0] == 'b')
			ft_putstr("\033[34;46m");
		if (tab[0][0] == 'l')
			ft_putstr("\033[35m");
	}
	else
		ft_putstr("\033[39;49m");
}

void	ft_color_file(char c, char *name, int i)
{
	if (c == 'b')
		ft_putstr("\033[96m");
	else if (c == 'y')
		ft_putstr("\033[34;43m");
	else if (c == 'u')
		ft_putstr("\033[34;46m");
	else if (c == 'r')
		ft_putstr("\033[31m");
	else if (c == 'v')
		ft_putstr("\033[35m");
	else
		ft_putstr("\033[39m");
	ft_putstr(name);
	if (i == 1)
		ft_putchar('\n');
	ft_putstr("\033[39;49m");
}

char	ft_set_color(mode_t info)
{
	if (S_ISCHR(info))
		return ('y');
	if (S_ISDIR(info))
		return ('b');
	if (S_ISBLK(info))
		return ('u');
	if (S_ISLNK(info))
		return ('v');
	else if ((info & S_IXUSR) || (info & S_IXGRP) || (info & S_IXOTH))
		return ('r');
	return (' ');
}
