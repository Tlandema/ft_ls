/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:02:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/25 01:11:56 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_bad_filler(t_bra *bad)
{
	char *tmp;

	tmp = ft_memalloc(PATH_MAX);
	ft_strcpy(tmp, "ls: ");
	ft_strcat(tmp, bad->name);
	ft_strcat(tmp, ": No such file or directory\n");
	bad->display = ft_strdup(tmp);
	free(tmp);
}

void	ft_print_bad(t_dir *dir, t_bra *bad)
{
	if (bad->left)
		ft_print_bad(dir, bad->left);
	ft_putstr(bad->display);
	if (bad->right)
		ft_print_bad(dir, bad->right);
	free(bad->list);
	free(bad->name);
	free(bad->display);
	free(bad);
}

void	ft_print_file(t_dir *dir, t_bra *file)
{
	if (dir->options[3] == 0)
	{
		if (file->left)
			ft_print_file(dir, file->left);
		ft_padding(dir, file);
		if (file->right)
			ft_print_file(dir, file->right);
	}
	else
	{
		if (file->right)
			ft_print_file(dir, file->right);
		ft_padding(dir, file);
		if (file->left)
			ft_print_file(dir, file->left);
	}
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

void	ft_print_spec(t_dir *dir, char *current)
{
	static int i = 0;

	if (!dir->first_dir || (dir->options[1] == 1 && !dir->first_dir)
			|| dir->one_dir == 0)
	{
		if (i != 0)
			ft_putchar('\n');
		i = 1;
		if (dir->options[1] == 1 && dir->options[0] != 1)
			ft_putchar('\n');
		ft_putstr(current);
		ft_putstr(":\n");
	}
	if (dir->options[0] == 1)
		ft_printf("total %i\n", dir->blocksize);
	dir->first_stuff = '\0';
	free(dir->first_dir);
	dir->first_dir = NULL;
	ft_print_file(dir, dir->in_dir_bra);
}
