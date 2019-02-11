/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:37:09 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/11 13:41:28 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/ft_printf.h"

void	init(t_dir *dir)
{
	dir->options = ft_memalloc(sizeof(int) * 5);
	dir->test = ft_memalloc(sizeof(t_fil));
}

void	printy(int ac, char **av, t_dir *dir)
{
	DIR             *dirp;
   	struct dirent   *dp;
	char            *file_name;

	if (dir->i < ac)
		dirp = opendir(av[dir->i]);
	else 
		dirp = opendir(".");
	while ((dp = readdir(dirp)) != NULL)
	{
		file_name = dp->d_name;
		if (file_name[0] != '.')
			ft_printf("%s ", file_name);
	}
	ft_printf("\n");
	closedir(dirp);
	dir->i++;
}

void	parse_options(int ac, char **av, t_dir *dir)
{
	dir->i = 1;
	while (dir->i < ac && !ft_strequ("--", av[dir->i]) && av[dir->i][0] == '-' 
			&& !ft_strequ("-", av[dir->i]))
	{
		ft_strchr(av[dir->i], 'l') ? (dir->options[0] = 1) : 0;
		ft_strchr(av[dir->i], 'R') ? (dir->options[1] = 1) : 0;
		ft_strchr(av[dir->i], 'a') ? (dir->options[2] = 1) : 0;
		ft_strchr(av[dir->i], 'r') ? (dir->options[3] = 1) : 0;
		ft_strchr(av[dir->i], 't') ? (dir->options[4] = 1) : 0;
		dir->i++;
	}
	if (ft_strequ("--", av[dir->i]))
		dir->i++;
}

int		main(int ac, char **av)
{
	t_dir *dir;

	dir = NULL;
	dir = ft_memalloc(sizeof(t_dir));
	init(dir);
	parse_options(ac, av, dir);
	printy(ac, av, dir);
	free(dir);
	return (0);
}
