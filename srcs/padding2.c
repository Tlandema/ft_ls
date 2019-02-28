/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 06:54:44 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/28 17:32:35 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include "../includes/ft_ls.h"

void		ft_padding_helper_3(char **tab)
{
	ft_putstr(tab[4]);
	ft_putchar(' ');
	ft_putstr(tab[5]);
	ft_putchar(' ');
	if (ft_strlen(tab[6]) == 1)
		ft_putchar(' ');
	ft_putstr(tab[6]);
	ft_putchar(' ');
	ft_putstr(tab[7]);
	ft_putchar(' ');
}

static int	size_tab(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

void		ft_print_lnk(char *link)
{
	ft_putstr(" -> ");
	ft_putstr(link);
}

int			ft_pad(int size_max, char color, char *name, int j)
{
	int			i;
	int			k;

	k = 0;
	ft_color_file(color, name, 0);
	i = (size_tab() / size_max) - 2;
	while (j < i)
	{
		while (k + (int)ft_strlen(name) < size_max + 1)
		{
			if (k != size_max - 1)
				ft_putchar(' ');
			k++;
		}
		ft_putchar(' ');
		j++;
		return (j);
	}
	ft_putchar('\n');
	j = 0;
	return (j);
}
