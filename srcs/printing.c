/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:02:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/28 11:36:29 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <unistd.h>

void	ft_print_bad_filler(t_bra *bad)
{
	char *tmp;

	tmp = ft_strnew(PATH_MAX);
	ft_strcpy(tmp, "ls: ");
	ft_strcat(tmp, bad->name);
	free(bad->name);
	ft_strcat(tmp, ": No such file or directory\n");
	bad->name = ft_strdup(tmp);
	free(tmp);
}

void	ft_print_bad(t_dir *dir, t_bra *bad)
{
	if (bad->left)
		ft_print_bad(dir, bad->left);
	ft_print_bad_filler(bad);
	ft_putstr(bad->name);
	if (bad->right)
		ft_print_bad(dir, bad->right);
	free(bad->list);
	free(bad->name);
	free(bad);
}

int		ft_print_file(t_dir *dir, t_bra *file, int j)
{
	if (dir->options[3] == 0)
	{
		if (file->left)
			ft_print_file(dir, file->left, j);
		j = ft_padding(dir, file, j);
		if (file->right)
			ft_print_file(dir, file->right, j);
	}
	else
	{
		if (file->right)
			ft_print_file(dir, file->right, j);
		j = ft_padding(dir, file, j);
		if (file->left)
			ft_print_file(dir, file->left, j);
	}
	return (j);
}

void	ft_print_dir(t_dir *dir, t_bra *direc)
{
	if (dir->options[3] == 0)
	{
		if (direc->left)
			ft_print_dir(dir, direc->left);
		if (ft_inside_dir(dir, direc->name) == -1)
			ft_print_error(direc->name);
		if (direc->right)
			ft_print_dir(dir, direc->right);
	}
	else
	{
		if (direc->right)
			ft_print_dir(dir, direc->right);
		if (ft_inside_dir(dir, direc->name) == -1)
			ft_print_error(direc->name);
		if (direc->left)
			ft_print_dir(dir, direc->left);
	}
	free(direc->list);
	free(direc->name);
	free(direc);
}

void	ft_print_spec(t_dir *dir, char *current, int j)
{
	static int i = 0;

	if (i == 1 && dir->options[5] == 0)
		write(1, "\n", 2);
	i = 1;
	if (!dir->first_dir || (dir->options[1] == 1 && !dir->first_dir)
			|| dir->one_dir == 0)
	{
		if (dir->options[1] == 1 && dir->options[0] != 1)
			ft_putchar('\n');
		ft_putstr(current);
		ft_putstr(":\n");
	}
	if (dir->options[0] == 1)
		ft_printf("total %i\n", dir->blocksize);
	free(dir->first_dir);
	dir->first_dir = NULL;
	ft_print_file(dir, dir->in_dir_bra, j);
}
