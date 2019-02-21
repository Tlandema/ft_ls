/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:37:09 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/21 06:59:30 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_free(t_bra *to_f)
{
	if (!to_f)
		return ;
	if (to_f->left)
		ft_free(to_f->left);
	if (to_f->right)
		ft_free(to_f->right);
	free(to_f->name);
	to_f->name = NULL;
	free(to_f);
	to_f = NULL;
}

static void	init(t_dir *dir)
{
	dir->options = ft_memalloc(sizeof(int) * 5);
	dir->path = ft_strnew(PATH_MAX);
	dir->dir_path = ft_strnew(PATH_MAX);
	dir->one_dir = 0;
	dir->file_bra = NULL;
	dir->bad_bra = NULL;
	dir->dir_bra = NULL;
	dir->in_dir_bra = NULL;
}

int			main(int ac, char **av)
{
	t_dir *dir;

	dir = NULL;
	dir = ft_memalloc(sizeof(t_dir));
	init(dir);
	ft_parse_options(ac, av, dir);
	free(dir);
	return (0);
}
