/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:59:39 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/13 15:12:27 by tlandema         ###   ########.fr       */
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
	if (file->left)
		ft_print_file(dir, file->left);
	ft_printf("%s ", file->display);
	if (file->right)
		ft_print_file(dir, file->right);
}

void	ft_print_dir(t_dir *dir, t_bra *direc)
{
	if (direc->left)
		ft_print_dir(dir, direc->left);
	ft_open_dir(dir, direc->name);
	ft_putchar('\n');
	if (direc->right)
		ft_print_dir(dir, direc->right);
}
