/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:16:05 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/01 06:21:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_bra	*ft_create_branch(t_dir *dir, char *name)
{
	t_bra *branch;

	branch = ft_memalloc(sizeof(t_bra));
	branch->left = NULL;
	branch->right = NULL;
	branch->name = ft_strdup(name);
	branch->color = ft_set_color(dir->file_info.st_mode);
	if (ft_strlen(name) > dir->n_max)
		dir->n_max = ft_strlen(name);
	if (S_ISDIR(dir->file_info.st_mode) && !ft_strequ(branch->name, ".")
			&& !ft_strequ(branch->name, ".."))
		branch->isdir = 'd';
	else
		branch->isdir = '0';
	if (dir->options[8] == 1)
		branch->size = (long long)dir->file_info.st_size;
	if (dir->options[4] == 1)
		branch->time = (long long)dir->file_info.st_mtime;
	if (dir->options[4] == 1)
		branch->nano_time = (long long)dir->file_info.st_mtimespec.tv_nsec;
	if (dir->options[0] == 1)
		branch->list = ft_listing(dir, branch->name);
	return (branch);
}

void	ft_name_branching(t_bra **root, t_dir *dir, char *name)
{
	if (*root == NULL)
	{
		*root = ft_create_branch(dir, name);
		return ;
	}
	if (ft_strcmp(name, (*root)->name) < 0)
		ft_name_branching(&(*root)->left, dir, name);
	else
		ft_name_branching(&(*root)->right, dir, name);
}

void	ft_date_branching(t_bra **root, t_dir *dir, char *name)
{
	if (*root == NULL)
	{
		*root = ft_create_branch(dir, name);
		return ;
	}
	if (dir->file_info.st_mtime > (*root)->time)
		ft_date_branching(&(*root)->left, dir, name);
	else if (dir->file_info.st_mtime < (*root)->time)
		ft_date_branching(&(*root)->right, dir, name);
	else
	{
		if (dir->file_info.st_mtimespec.tv_nsec > (*root)->nano_time)
			ft_date_branching(&(*root)->left, dir, name);
		else if (dir->file_info.st_mtimespec.tv_nsec < (*root)->nano_time)
			ft_date_branching(&(*root)->right, dir, name);
		else
		{
			if (ft_strcmp(name, (*root)->name) < 0)
				ft_date_branching(&(*root)->left, dir, name);
			else
				ft_date_branching(&(*root)->right, dir, name);
		}
	}
}

void	ft_na_or_da_or_si(char *n_or_d, t_dir *dir, t_bra **use)
{
	if (dir->options[4] == 1)
		ft_date_branching(use, dir, n_or_d);
	else if (dir->options[8] == 1)
		ft_size_branching(use, dir, n_or_d);
	else
		ft_name_branching(use, dir, n_or_d);
}

void	ft_parse_branch(int i, char **argv, t_dir *dir)
{
	while (argv[i])
	{
		if (!argv[i][0])
		{
			ft_putstr("ls: fts_open: No such file or directory\n");
			exit(1);
		}
		lstat(argv[i], &dir->file_info);
		if (S_ISREG(dir->file_info.st_mode) || S_ISLNK(dir->file_info.st_mode))
		{
			ft_dir_len_filler(dir);
			ft_na_or_da_or_si(argv[i], dir, &dir->file_bra);
		}
		else if (!dir->file_info.st_mode)
			ft_name_branching(&dir->bad_bra, dir, argv[i]);
		else if (S_ISDIR(dir->file_info.st_mode))
			ft_na_or_da_or_si(argv[i], dir, &dir->dir_bra);
		dir->file_info.st_mode = 0;
		i++;
	}
}
