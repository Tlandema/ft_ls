/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directoring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:32:14 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/13 17:26:26 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_open_dir(t_dir *dir, char *dir_name)
{
	struct dirent   *dp;
	char            *file_name;
	//t_bra			*test;

	if (dir->one_dir != 1)
		ft_printf("%s:\n", dir_name);
	dir->dirp = opendir(dir_name);
	while ((dp = readdir(dir->dirp)) != NULL)
	{
		file_name = dp->d_name;
		if (file_name[0] != '.')
		ft_printf("%s ", file_name);
	}
	ft_putchar('\n');
	closedir(dir->dirp);
}
