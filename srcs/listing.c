/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:52:50 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/18 16:13:13 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_listing(t_dir *dir, char *name, int i)
{
	struct passwd	*pwd;
	struct group	*grp;
	char 			*test;
	int 			check;
	char			*time;

	name = NULL;
	i = 0;
	test = ft_memalloc(sizeof(char) * 64);
	if (S_ISDIR(dir->file_info.st_mode))
		test[0] = 'd';
	else if (S_ISLNK(dir->file_info.st_mode))
		test[0] = 'l';
	else
		test[0] = '-';
	check = ft_atoi(ft_itoa_ubase(dir->file_info.st_mode, "01234567")) % 1000; 
	check = ft_atoi(ft_strrev(ft_itoa_ubase(check, "0123456789")));
	while (i < 3)
	{
		if (check % 10 == 7)
			ft_strcat(test, "rwx");
		else if (check % 10 == 6)
			ft_strcat(test, "rw-");
		else if (check % 10 == 5)
			ft_strcat(test, "r-x");
		else if (check % 10 == 4)
			ft_strcat(test, "r--");
		else if (check % 10 == 3)
			ft_strcat(test, "-wx");
		else if (check % 10 == 2)
			ft_strcat(test, "-w-");
		else if (check % 10 == 1)
			ft_strcat(test, "--x");
		else 
			ft_strcat(test, "---");
		check = check / 10;
		i++;
	}
	ft_strcat(test, " ");
	ft_strcat(test, ft_itoa_ubase(dir->file_info.st_nlink, "0123456789"));
	ft_strcat(test, " ");
	pwd = getpwuid(dir->file_info.st_uid);
	ft_strcat(test, pwd->pw_name);
	ft_strcat(test, " ");
	grp = getgrgid(dir->file_info.st_gid);
	ft_strcat(test, grp->gr_name);
	ft_strcat(test, " ");
	ft_strcat(test, ft_itoa(dir->file_info.st_size));
	ft_strcat(test, " ");
	time = ft_strdup(ctime(&dir->file_info.st_mtimespec.tv_sec));
	time = &time[4];
	time = ft_strrev(time);
	time = &time[6];
	time = ft_strrev(time);
	ft_strcat(test, time);
	return (test);
}
