/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:24:11 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/22 01:36:21 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <unistd.h>

void	ft_padding(t_dir *dir, t_bra *bra)
{
	char	**tab;
	char	*test;

	test = ft_strnew(PATH_MAX);
	if (dir->options[0] == 1)
	{
		tab = ft_strsplit(bra->list, ' ');
		ft_printf("%s %4s%10s%12s", tab[0], tab[1], tab[2], tab[3]);
		ft_printf(" %7s %s %s %s %s ", tab[4], tab[5], tab[6], tab[7], tab[8]);
		ft_tabdel(9, &tab);
	}
	else
	{
		ft_putstr(bra->display);
		ft_putchar(' ');
	}
	if (dir->options[0] == 1 && bra->list[0] == 'l')
	{
		readlink(bra->name, test, PATH_MAX);
		ft_putstr("-> ");
		ft_putstr(test);
	}
	if (dir->options[0] == 1)
		ft_putchar('\n');
	free(test);
}
