/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directoring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:32:14 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/21 07:33:22 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_path_forming(char *path, char *dir_name, char *file_name)
{
	ft_strcpy(path, dir_name);
	if (!(ft_strequ(dir_name, "/")))
		ft_strcat(path, "/");
	ft_strcat(path, file_name);
}

int			ft_open_dir(t_dir *dir, char *dir_name)
{
	struct dirent *dp;

	if (!(dir->dirp = opendir(dir_name)))
		return (-1);
	while ((dp = readdir(dir->dirp)) != NULL)
	{
		ft_path_forming(dir->path, dir_name, dp->d_name);
		if (lstat(dir->path, &dir->file_info) == 0)
			stat(dir->path, &dir->file_info);
		if ( dp->d_name[0] != '.' ||
				(dp->d_name[0] == '.' && dir->options[2] == 1))
			ft_name_or_date(dp->d_name, dir, &dir->in_dir_bra);
	}
	if (closedir(dir->dirp) == -1 || !dir->in_dir_bra)
		return (-1);
	return (0);
}

int			ft_inside_dir(t_dir *dir, char *work)
{
	dir->in_dir_bra = NULL;
	if (ft_open_dir(dir, work) == -1)
		return (-1);
	ft_print_spec(dir, work);
	if (dir->options[1] == 1)
		ft_rollback(dir->in_dir_bra, dir, work);
	else
		ft_free(dir->in_dir_bra);
	return (0);
}

void		ft_rollback(t_bra *in_dir_bra, t_dir *dir, char *work)
{
	char	*tmp;

	tmp = ft_strdup(work);
	if (in_dir_bra->left)
		ft_rollback(in_dir_bra->left, dir, tmp);
	if (in_dir_bra->isdir == 'd')
	{
		ft_path_forming(dir->dir_path, tmp, in_dir_bra->name);
		if (ft_inside_dir(dir, dir->dir_path) == -1)
			ft_putstr("shit");
	}
	if (in_dir_bra->right)
		ft_rollback(in_dir_bra->right, dir, tmp);
	free(tmp);
	free(in_dir_bra->name);
	free(in_dir_bra);
}

void	ft_first_dir(t_dir *dir, t_bra *dir_bra)
{
	if (!dir->bad_bra && !dir->file_bra)
		dir->first_stuff = '1';
	if (dir_bra->left)
		ft_first_dir(dir, dir_bra->left);
	dir->first_dir = ft_strdup(dir_bra->name);
	if (dir_bra->right)
		if (ft_strequ(dir->first_dir, dir_bra->right->name))
			dir->first_dir = NULL;
}
