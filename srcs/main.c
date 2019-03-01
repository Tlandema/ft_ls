/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:44:02 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/01 05:58:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	init(t_dir *dir)
{
	dir->options = ft_strnew(8);
	dir->path = ft_strnew(PATH_MAX);
	dir->dir_path = ft_strnew(PATH_MAX);
	dir->one_dir = 0;
	dir->n_max = 0;
	dir->l_max = 0;
	dir->p_max = 0;
	dir->g_max = 0;
	dir->b_max = 0;
	dir->file_bra = NULL;
	dir->bad_bra = NULL;
	dir->dir_bra = NULL;
	dir->in_dir_bra = NULL;
}

void		ft_free(t_bra *to_f)
{
	if (!to_f)
		return ;
	if (to_f->left)
		ft_free(to_f->left);
	if (to_f->right)
		ft_free(to_f->right);
	free(to_f->list);
	to_f->list = NULL;
	free(to_f->name);
	to_f->name = NULL;
	free(to_f);
	to_f = NULL;
}

static void	ft_big_free(t_dir *dir)
{
	if (dir->first_dir)
		free(dir->first_dir);
	free(dir->options);
	free(dir->path);
	free(dir->dir_path);
	free(dir);
}

int			main(int argc, char **argv)
{
	t_dir	*dir;

	dir = NULL;
	dir = ft_memalloc(sizeof(t_dir));
	init(dir);
	ft_parse_options(argc, argv, dir);
	ft_big_free(dir);
	return (0);
}
