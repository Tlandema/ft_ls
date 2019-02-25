/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:44:37 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/25 03:27:30 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <unistd.h>

void	ft_padding(t_dir *dir, t_bra *bra)
{
	char	**tab;
	char	*tmp;

	tmp = ft_strnew(PATH_MAX);
	if (dir->options[0] == 1)
	{
		tab = ft_strsplit(bra->list, ' ');
		ft_printf("%s %4s%10s%12s", tab[0], tab[1], tab[2], tab[3]);
		ft_printf(" %7s %s %2s %s %s ", tab[4], tab[5], tab[6], tab[7], tab[8]);
		if (tab[0][0] == 'l')
		{
			ft_putstr("-> ");
			readlink(tab[8], tmp, PATH_MAX);
			ft_putstr(dir->dir_path);
			ft_putstr(tmp);
		}
		ft_putchar('\n');
		ft_tabdel(9, &tab);
	}
	else
	{
		ft_putstr(bra->name);
		ft_putchar(' ');
	}
	free(tmp);
}
