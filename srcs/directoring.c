/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directoring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:38:42 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/01 10:45:33 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_path_forming(char *path, char *dir_name, char *file_name)
{
	ft_strcpy(path, dir_name);
	if (!(ft_strrev(path)[0] == '/'))
	{
		ft_strrev(path);
		if (!(ft_strequ(dir_name, "/")))
			ft_strcat(path, "/");
	}
	else
		ft_strrev(path);
	ft_strcat(path, file_name);
}

int			ft_open_dir(t_dir *dir, char *dir_name)
{
	struct dirent	*dp;

	if (!(dir->dirp = opendir(dir_name)))
		return (-1);
	while ((dp = readdir(dir->dirp)) != NULL)
	{
		ft_path_forming(dir->path, dir_name, dp->d_name);
		lstat(dir->path, &dir->file_info);
		if ((dp->d_name[0] != '.')
				|| (dp->d_name[0] == '.' && dir->options[2] == 1)
				|| (dp->d_name[0] == '.' && dir->options[6] == 1
					&& dp->d_name[1] && dp->d_name[1] != '.'))
		{
			ft_dir_len_filler(dir);
			dir->blocksize += dir->file_info.st_blocks;
			ft_na_or_da_or_si(dp->d_name, dir, &dir->in_dir_bra);
		}
	}
	if (closedir(dir->dirp) == -1 || !dir->in_dir_bra)
		return (-1);
	return (0);
}

int			ft_inside_dir(t_dir *dir, char *work)
{
	dir->j = 0;
	dir->in_dir_bra = NULL;
	dir->blocksize = 0;
	dir->n_max = 0;
	dir->l_max = 0;
	dir->p_max = 0;
	dir->g_max = 0;
	dir->b_max = 0;
	if (ft_open_dir(dir, work) == -1)
		return (-1);
	ft_print_spec(dir, work);
	if (dir->options[1] == 1)
	{
		if (dir->options[3] == 0)
			ft_rollback(dir->in_dir_bra, dir, work);
		else
			ft_rollfront(dir->in_dir_bra, dir, work);
	}
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
			ft_print_error(dir, in_dir_bra);
	}
	if (in_dir_bra->right)
		ft_rollback(in_dir_bra->right, dir, tmp);
	free(tmp);
	free(in_dir_bra->list);
	free(in_dir_bra->name);
	free(in_dir_bra);
}

void		ft_rollfront(t_bra *in_dir_bra, t_dir *dir, char *work)
{
	char	*tmp;

	tmp = ft_strdup(work);
	if (in_dir_bra->right)
		ft_rollfront(in_dir_bra->right, dir, tmp);
	if (in_dir_bra->isdir == 'd')
	{
		ft_path_forming(dir->dir_path, tmp, in_dir_bra->name);
		if (ft_inside_dir(dir, dir->dir_path) == -1)
			ft_print_error(dir, in_dir_bra);
	}
	if (in_dir_bra->left)
		ft_rollfront(in_dir_bra->left, dir, tmp);
	free(tmp);
	free(in_dir_bra->list);
	free(in_dir_bra->name);
	free(in_dir_bra);
}
