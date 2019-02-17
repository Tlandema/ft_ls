/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directoring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:32:14 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/17 17:34:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_path_forming(char *path, char *dir_name, char *file_name)
{
	ft_strcpy(path, dir_name);
	if (!(ft_strequ(dir_name, "/")))
		ft_strcat(path, "/");
	ft_strcat(path, file_name);
}
void		ft_open_dir(t_dir *dir, char *dir_name)
{
	struct dirent   *dp;
	char            *file_name;
	t_bra			*test;

	test = NULL;
	if (dir->one_dir != 1)
		ft_printf("%s:\n", dir_name);
	dir->dirp = opendir(dir_name);
	while ((dp = readdir(dir->dirp)) != NULL)
	{
		file_name = dp->d_name;
		ft_path_forming(dir->path, dir_name, dp->d_name); 
		lstat(dir->path, &dir->file_info);
		if (dp->d_name[0] != '.' ||
			   	(dp->d_name[0] == '.' && dir->options[2] == 1))
		{
			if (dir->options[4] == 0)
				ft_name_branching(&test, dir, dp->d_name);
			else
				ft_date_branching(&test, dir, dp->d_name);
		}
	}
	ft_print_file(dir, test);
	ft_putchar('\n');
	closedir(dir->dirp);
}
