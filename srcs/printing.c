/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:59:39 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/21 02:20:17 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_bad(t_dir *dir, t_bra *bad)
{
	if (bad->left)
		ft_print_bad(dir, bad->left);
	ft_printf("%s", bad->display);
	if (bad->right)
		ft_print_bad(dir, bad->right);
}

void	ft_print_file(t_dir *dir, t_bra *file)
{
	if (dir->options[3] == 0)
	{
		if (file->left)
			ft_print_file(dir, file->left);
		if (dir->options[0] == 1)
			ft_printf("%s ", file->list);
		ft_printf("%s ", file->display);
		if (dir->options[0] == 1)
			ft_putchar('\n');
		if (file->right)
			ft_print_file(dir, file->right);
	}
	else
	{
		if (file->right)
			ft_print_file(dir, file->right);
		if (dir->options[0] == 1)
			ft_printf("%s ", file->list);
		ft_printf("%s ", file->display);
		if (dir->options[0] == 1)
			ft_putchar('\n');
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
			ft_putstr("shit");
		//ft_open_dir(dir, direc->name);
		ft_putchar('\n');
		if (direc->right)
			ft_print_dir(dir, direc->right);
	}
	else
	{
		if (direc->right)
			ft_print_dir(dir, direc->right);
		if (ft_inside_dir(dir, direc->name) == -1)
			ft_putstr("shit");
		//ft_open_dir(dir, direc->name);
		ft_putchar('\n');
		if (direc->left)
			ft_print_dir(dir, direc->left);
	}
}

void	ft_print_spec(t_dir *dir, char *current)
{
	ft_putstr("\n");
	ft_putstr(current);
	ft_putstr(":\n");
	ft_print_file(dir, dir->in_dir_bra);
}
