/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:55:34 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/11 15:24:46 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include "ft_ls.h"

int main(void)
{

	char* folder=".";                           
	char *time_str;

	DIR* dir_p;
	struct dirent *dir_element;
	struct stat file_info;
	struct passwd *pwd;
	struct group *grp;
	char *opt_tab;
	t_yes *test;

	test = ft_memalloc(sizeof(t_yes));
	test->fil = ft_memalloc(sizeof(t_fil));

	dir_p = opendir(folder);
	while((dir_element = readdir(dir_p)) != NULL)
	{
		if (dir_element->d_name[0] != '.')
		{
			lstat(dir_element->d_name, &file_info);          
			test->fil->mode = ft_atoi(ft_itoa_ubase(file_info.st_mode, "01234567"));
			test->fil->name = dir_element->d_name;
			printf("Name of file: %s\n", test->fil->name);
			test->fil->hard = file_info.st_nlink;
			printf("hardlink: %d\n", test->fil->hard);
			printf("file mode: %d\n", test->fil->mode);
			pwd = getpwuid(file_info.st_uid);
			test->fil->user = pwd->pw_name;
			printf("username: %s\n", test->fil->user);		
			grp = getgrgid(file_info.st_gid);
			test->fil->group = grp->gr_name;
			printf("group: %s\n", test->fil->group);
			test->fil->size = file_info.st_size;
			printf("size: %lli\n", test->fil->size);
			test->fil->time = ctime(&file_info.st_mtimespec.tv_sec);
			printf("time modified: %.12s\n", &test->fil->time[4]);
			if (S_ISDIR(file_info.st_mode)) 
				puts("|| directory");
			if (S_ISREG(file_info.st_mode)) 
				puts("|| regular file");
			if (S_ISLNK(file_info.st_mode))
				puts("|| symbolic link");
			printf("\n");
		}
	}
	return (0);
}
