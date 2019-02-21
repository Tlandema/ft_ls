/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 23:04:40 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/21 02:35:29 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_bra		*ft_create_branch(t_dir *dir, char *name)
{
	t_bra	*branch;
	char	*bad;

	branch = ft_memalloc(sizeof(t_bra));
	branch->left = NULL;
	branch->right = NULL;
	branch->name = ft_strdup(name);
	if (S_ISDIR(dir->file_info.st_mode) &&
			!ft_strequ(branch->name, ".") && !ft_strequ(branch->name, ".."))
		branch->isdir = 'd';
	else
		branch->isdir = '0';
	if (dir->options[4] == 1)
		branch->time = dir->file_info.st_mtime;
	if (dir->options[4] == 1)
		branch->nano_time = dir->file_info.st_mtimespec.tv_nsec;
	if (dir->options[0] == 1)
		branch->list = ft_listing(dir, branch->name);
	if (!dir->file_info.st_mode && ft_strcmp(branch->name, ".") != 0)
	{
		bad = ft_strdup("ls: ");
		bad = ft_strjoin(bad, branch->name);
		bad = ft_strjoin(bad, ": No such file or directory\n");
		branch->display = bad;
	}
	if (S_ISREG(dir->file_info.st_mode) || S_ISLNK(dir->file_info.st_mode)
		|| S_ISDIR(dir->file_info.st_mode))
		branch->display = branch->name;
	return (branch);
}

void		ft_name_branching(t_bra **root, t_dir *dir, char *name)
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

void		ft_date_branching(t_bra **root, t_dir *dir, char *name)
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

void	ft_name_or_date(char *n_or_d, t_dir *dir, t_bra **use)
{
	if (dir->options[4] == 0)
		ft_name_branching(use, dir, n_or_d);
	else
		ft_date_branching(use, dir, n_or_d);
}

void		ft_parse_branch(int i, char **av, t_dir *dir)
{
	while (av[i])
	{
		if (!av[i][0])
		{
			ft_printf("ls: fts_open: No such file or directory\n");
			exit(1);
		}
		lstat(av[i], &dir->file_info);
		if (S_ISREG(dir->file_info.st_mode) || S_ISLNK(dir->file_info.st_mode))
			ft_name_or_date(av[i], dir, &dir->file_bra);
		else if (!dir->file_info.st_mode)
			ft_name_branching(&dir->bad_bra, dir, av[i]);
		else if (S_ISDIR(dir->file_info.st_mode))
			ft_name_or_date(av[i], dir, &dir->dir_bra);
		dir->file_info.st_mode = 0;
		i++;
	}
}
