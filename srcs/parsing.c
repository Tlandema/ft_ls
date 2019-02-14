/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:26:50 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/14 16:41:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void    ft_parse_options(int ac, char **av, t_dir *dir)
{
	int i;

	i = 1;
	while (i < ac && !ft_strequ("--", av[i]) && av[i][0] == '-'
			&& !ft_strequ("-", av[i]))
	{
		ft_strchr(av[i], 'l') ? (dir->options[0] = 1) : 0;
		ft_strchr(av[i], 'R') ? (dir->options[1] = 1) : 0;
		ft_strchr(av[i], 'a') ? (dir->options[2] = 1) : 0;
		ft_strchr(av[i], 'r') ? (dir->options[3] = 1) : 0;
		ft_strchr(av[i], 't') ? (dir->options[4] = 1) : 0;
		i++;
	}
	if (ft_strequ("--", av[i]))
		i++;
	if (i == ac || i == ac - 1)
		dir->one_dir = 1;
	if (i == ac)
		ft_name_branching(&dir->dir_bra, dir, ".");
	ft_parse_branch(i, av, dir);
	if (dir->bad_bra)
		ft_print_bad(dir, dir->bad_bra);
	if (dir->file_bra)
	{
		ft_print_file(dir, dir->file_bra);
		ft_putchar('\n');
	}
	if (dir->dir_bra)
		ft_print_dir(dir, dir->dir_bra);
}
