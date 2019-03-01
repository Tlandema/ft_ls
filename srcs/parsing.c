/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:58:06 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/01 06:23:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_parse_helper_helper(char *opt, t_dir *dir, int i)
{
	opt[i] == 'l' ? (dir->options[0] = 1) : 0;
	opt[i] == 'R' ? (dir->options[1] = 1) : 0;
	opt[i] == 'a' ? (dir->options[2] = 1) : 0;
	opt[i] == 'r' ? (dir->options[3] = 1) : 0;
	if (opt[i] == 't' && dir->options[8] != 1)
		dir->options[4] = 1;
	opt[i] == '1' ? (dir->options[5] = 1) : 0;
	opt[i] == 'A' ? (dir->options[6] = 1) : 0;
	opt[i] == 'T' ? (dir->options[7] = 1) : 0;
	opt[i] == 'S' ? (dir->options[8] = 1) : 0;
	opt[i] == 'S' ? (dir->options[4] = 0) : 0;
	opt[i] == 'l' ? (dir->options[5] = 0) : 0;
	opt[i] == '1' ? (dir->options[0] = 0) : 0;
}

static void	ft_parse_helper(char *opt, t_dir *dir, int i)
{
	while (opt[i])
	{
		ft_parse_helper_helper(opt, dir, i);
		i++;
	}
	i = 1;
	while (opt[i])
	{
		if (opt[i] != 'l' && opt[i] != 'R' && opt[i] != 'a'
				&& opt[i] != 'r' && opt[i] != 't' && opt[i] != '1'
				&& opt[i] != 'A' && opt[i] != 'T' && opt[i] != 'S')
		{
			ft_putstr("ls: illeagl option -- ");
			ft_putchar(opt[i]);
			ft_putstr("\nusage: ls [-lRAart1TS] [file ...]\n");
			exit(1);
		}
		i++;
	}
}

static void	ft_first_dir(t_dir *dir, t_bra *dir_bra)
{
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
	ft_print_file(dir, dir->file_bra, 0);
	ft_free(dir->file_bra);
	if (dir->options[0] == 0 && dir->options[5] == 0)
		ft_putchar('\n');
}

void		ft_parse_options(int argc, char **argv, t_dir *dir)
{
	int i;

	i = 1;
	while (i < argc && !ft_strequ(argv[i], "--") && argv[i][0] == '-'
			&& !ft_strequ(argv[i], "-"))
		ft_parse_helper(argv[i++], dir, 0);
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
		if (dir->options[0] == 0 && dir->options[5] == 0)
			ft_putchar('\n');
	}
}
