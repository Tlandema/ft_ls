/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:44:37 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/27 07:34:18 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <unistd.h>

void		ft_dir_len_filler(t_dir *dir)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*link_len;
	char			*block_len;

	if (ft_strlen(link_len = ft_itoa(dir->file_info.st_nlink)) > dir->l_max)
		dir->l_max = ft_strlen(link_len);
	free(link_len);
	pwd = getpwuid(dir->file_info.st_uid);
	if (ft_strlen(pwd->pw_name) > dir->p_max)
		dir->p_max = ft_strlen(pwd->pw_name);
	grp = getgrgid(dir->file_info.st_gid);
	if (ft_strlen(grp->gr_name) > dir->g_max)
		dir->g_max = ft_strlen(grp->gr_name);
	if (ft_strlen(block_len = ft_itoa(dir->file_info.st_size)) > dir->b_max)
		dir->b_max = ft_strlen(block_len);
}

static void	ft_padding_helper_2(t_dir *dir, char **tab, char *name)
{
	size_t i;

	i = dir->g_max - ft_strlen(tab[3]) + 1;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	i = dir->b_max - ft_strlen(tab[4]) + 1;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
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
	ft_putstr(name);
}

static void	ft_padding_helper(t_dir *dir, char **tab, char *name)
{
	size_t i;

	ft_putstr(tab[0]);
	if (ft_strlen(tab[0]) == 10)
		ft_putchar(' ');
	i = dir->l_max - ft_strlen(tab[1]) + 1;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putstr(tab[1]);
	ft_putchar(' ');
	ft_putstr(tab[2]);
	i = dir->p_max - ft_strlen(tab[2]) + 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putstr(tab[3]);
	ft_padding_helper_2(dir, tab, name);
}

void		ft_padding(t_dir *dir, t_bra *bra)
{
	char	**tab;
	char	*tmp;

	tmp = ft_strnew(PATH_MAX);
	if (dir->options[0] == 1)
	{
		tab = ft_strsplit(bra->list, ' ');
		ft_padding_helper(dir, tab, bra->name);
		if (tab[0][0] == 'l')
		{
			ft_putstr("-> ");
			ft_putstr(tab[8]);
		}
		ft_putchar('\n');
		ft_tabdel(8, &tab);
	}
	else
	{
		ft_putstr(bra->name);
		if (dir->options[5] == 1)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
	free(tmp);
}
