/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:26:50 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/12 23:28:54 by tlandema         ###   ########.fr       */
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
	if (i == ac)
		ft_name_branching(&dir->bra, dir, ".");
	ft_parse_branch(i, av, dir);
	if (dir->bad_bra)
		ft_print_bad(dir, dir->bad_bra);
	//if (dir->file_bra)
	//  do something about that
	//if (dir->dir_bra)
}
