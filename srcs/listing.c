/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:52:50 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/21 11:00:39 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_permissions(t_dir *dir, char *inform, int i)
{
	int	check;

	check = ft_atoi(ft_itoa_ubase(dir->file_info.st_mode, "01234567")) % 1000;
	check = ft_atoi(ft_strrev(ft_itoa_ubase(check, "0123456789")));
	while (i < 3)
	{
		if (check % 10 == 7)
			ft_strcat(inform, "rwx");
		else if (check % 10 == 6)
			ft_strcat(inform, "rw-");
		else if (check % 10 == 5)
			ft_strcat(inform, "r-x");
		else if (check % 10 == 4)
			ft_strcat(inform, "r--");
		else if (check % 10 == 3)
			ft_strcat(inform, "-wx");
		else if (check % 10 == 2)
			ft_strcat(inform, "-w-");
		else if (check % 10 == 1)
			ft_strcat(inform, "--x");
		else
			ft_strcat(inform, "---");
		check = check / 10;
		i++;
	}
}

void		ft_fill_inform(t_dir *dir, char *inform)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*time;

	ft_strcat(inform, " ");
	ft_strcat(inform, ft_itoa_ubase(dir->file_info.st_nlink, "0123456789"));
	ft_strcat(inform, " ");
	pwd = getpwuid(dir->file_info.st_uid);
	ft_strcat(inform, pwd->pw_name);
	ft_strcat(inform, " ");
	grp = getgrgid(dir->file_info.st_gid);
	ft_strcat(inform, grp->gr_name);
	ft_strcat(inform, " ");
	ft_strcat(inform, ft_itoa(dir->file_info.st_size));
	ft_strcat(inform, " ");
	time = ft_strdup(ctime(&dir->file_info.st_mtimespec.tv_sec));
	time = &time[4];
	time = ft_strrev(time);
	time = &time[9];
	time = ft_strrev(time);
	ft_strcat(inform, time);
}

char		*ft_listing(t_dir *dir, char *name)
{
	char			*inform;

	name = NULL;
	inform = ft_memalloc(sizeof(char) * 64);
	if (S_ISDIR(dir->file_info.st_mode))
		inform[0] = 'd';
	else if (S_ISLNK(dir->file_info.st_mode))
		inform[0] = 'l';
	else
		inform[0] = '-';
	ft_permissions(dir, inform, 0);
	ft_fill_inform(dir, inform);
	return (inform);
}
