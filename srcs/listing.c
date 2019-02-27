/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:28:12 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/27 02:42:21 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <unistd.h>

static void	ft_loop(int check, char *perm)
{
	if (check % 10 == 7)
		ft_strcat(perm, "rwx");
	else if (check % 10 == 6)
		ft_strcat(perm, "rw-");
	else if (check % 10 == 5)
		ft_strcat(perm, "r-x");
	else if (check % 10 == 4)
		ft_strcat(perm, "r--");
	else if (check % 10 == 3)
		ft_strcat(perm, "-wx");
	else if (check % 10 == 2)
		ft_strcat(perm, "-w-");
	else if (check % 10 == 1)
		ft_strcat(perm, "--x");
	else
		ft_strcat(perm, "---");
}

static void	ft_permissions(t_dir *dir, char *perm, int i)
{
	int		check;
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_itoa_ubase(dir->file_info.st_mode, "01234567");
	check = ft_atoi(tmp1);
	free(tmp1);
	tmp2 = ft_strrev(ft_itoa(check));
	check = ft_atoi(tmp2);
	if (check >= 100000)
		check /= 1000;
	else
		check /= 100;
	free(tmp2);
	while (i < 3)
	{
		ft_loop(check, perm);
		check = check / 10;
		i++;
	}
	ft_acl(dir, perm);
}

static void	ft_fill_inform(t_dir *dir, char **fill, char *name)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*tmp;

	fill[1] = ft_itoa(dir->file_info.st_nlink);
	pwd = getpwuid(dir->file_info.st_uid);
	fill[2] = ft_strdup(pwd->pw_name);
	grp = getgrgid(dir->file_info.st_gid);
	fill[3] = ft_strdup(grp->gr_name);
	fill[4] = ft_itoa(dir->file_info.st_size);
	tmp = ft_strdup(&ctime(&dir->file_info.st_mtimespec.tv_sec)[4]);
	tmp = ft_strrev(tmp);
	fill[5] = ft_strdup(&tmp[9]);
	fill[5] = ft_strrev(fill[5]);
	free(tmp);
	fill[6] = ft_strnew(PATH_MAX);
	if (S_ISLNK(dir->file_info.st_mode))
	{
		readlink(name, fill[6], PATH_MAX);
		if (fill[6][0] == '\0')
			readlink(dir->path, fill[6], PATH_MAX);
	}
}

static char	*ft_fill_list(char **fill, int i)
{
	char	*display;
	int		j;
	int		len_max;

	len_max = 0;
	while (fill[i])
	{
		j = 0;
		while (fill[i][j])
		{
			len_max++;
			j++;
		}
		i++;
	}
	i = 0;
	display = (char *)ft_memalloc(sizeof(char) * len_max + 9);
	while (fill[i])
	{
		ft_strcat(display, fill[i]);
		ft_strcat(display, " ");
		i++;
	}
	ft_tabdel(8, &fill);
	return (display);
}

char		*ft_listing(t_dir *dir, char *name)
{
	char	**fill;

	fill = (char **)ft_memalloc(sizeof(char *) * 9);
	fill[0] = (char *)ft_memalloc(sizeof(char) * 11);
	if (S_ISDIR(dir->file_info.st_mode))
		fill[0][0] = 'd';
	else if (S_ISLNK(dir->file_info.st_mode))
		fill[0][0] = 'l';
	else if (S_ISFIFO(dir->file_info.st_mode))
		fill[0][0] = 'p';
	else if (S_ISCHR(dir->file_info.st_mode))
		fill[0][0] = 'c';
	else if (S_ISBLK(dir->file_info.st_mode))
		fill[0][0] = 'b';
	else if (S_ISSOCK(dir->file_info.st_mode))
		fill[0][0] = 's';
	else
		fill[0][0] = '-';
	ft_permissions(dir, fill[0], 0);
	ft_fill_inform(dir, fill, name);
	return (ft_fill_list(fill, 0));
}
