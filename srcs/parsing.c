/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:58:06 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/25 00:35:32 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_parse_helper(int i, char **av, t_dir *dir)
{
	ft_strchr(av[i], 'l') ? (dir->options[0] = 1) : 0;
	ft_strchr(av[i], 'R') ? (dir->options[1] = 1) : 0;
	ft_strchr(av[i], 'a') ? (dir->options[2] = 1) : 0;
	ft_strchr(av[i], 'r') ? (dir->options[3] = 1) : 0;
	ft_strchr(av[i], 't') ? (dir->options[4] = 1) : 0;
}

static void	ft_first_dir(t_dir *dir, t_bra *dir_bra)
{
	if (!dir->bad_bra && !dir->file_bra)
		dir->first_stuff = '1';
	if (dir_bra->left)
		ft_first_dir(dir, dir_bra->left);
	dir->first_dir = ft_strdup(dir_bra->name);
	if (dir_bra->right)
	{
		if (ft_strequ(dir->first_dir, dir_bra->right->name))
		{
			free(dir->first_dir);
			dir->first_dir = NULL;
		}
	}
}

static void	ft_parse_helper_2(t_dir *dir)
{
	ft_print_file(dir, dir->file_bra);
	ft_free(dir->file_bra);
	ft_putchar('\n');
}

void		ft_parse_options(int argc, char **argv, t_dir *dir)
{
	int i;

	i = 1;
	while (i < argc && !ft_strequ(argv[i], "--") && argv[i][0] == '-'
			&& !ft_strequ(argv[i], "-"))
		ft_parse_helper(i++, argv, dir);
	if (ft_strequ(argv[i], "--"))
		i++;
	if (i == argc || i == argc - 1)
		dir->one_dir = 1;
	if (i == argc)
		ft_name_branching(&dir->dir_bra, dir, ".");
	ft_parse_branch(i, argv, dir);
	if (dir->bad_bra)
		ft_print_bad(dir, dir->bad_bra);
	if (dir->file_bra)
		ft_parse_helper_2(dir);
	if (dir->dir_bra)
	{
		if (i == argc | i == argc - 1)
			ft_first_dir(dir, dir->dir_bra);
		ft_print_dir(dir, dir->dir_bra);
	}
}
