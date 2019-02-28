/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:44:37 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/28 17:42:35 by tlandema         ###   ########.fr       */
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
	free(block_len);
}

static void	ft_padding_helper_2(t_dir *dir, char **tab, char *name, size_t i)
{
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
	ft_padding_helper_3(tab);
	if (dir->options[7])
	{
		ft_putstr(tab[8]);
		ft_putchar(' ');
	}
	ft_color(tab, 1);
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
	ft_padding_helper_2(dir, tab, name, 0);
	ft_color(tab, 0);
}

static int	ft_count_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			ft_padding(t_dir *dir, t_bra *bra, int j)
{
	char	**tab;
	char	*tmp;

	tmp = ft_strnew(PATH_MAX);
	if (dir->options[0] == 1)
	{
		tab = ft_strsplit(bra->list, ' ');
		ft_padding_helper(dir, tab, bra->name);
		if (tab[0][0] == 'l')
			dir->options[7] == 1 ? ft_print_lnk(tab[9]) : ft_print_lnk(tab[8]);
		ft_putchar('\n');
		ft_tabdel(ft_count_tab(tab), &tab);
	}
	else
	{
		if (dir->options[5] == 1)
			ft_color_file(bra->color, bra->name, 1);
		else
			j = ft_pad((int)dir->n_max, bra->color, bra->name, j);
		ft_putchar(dir->options[5]);
	}
	free(tmp);
	return (j);
}
