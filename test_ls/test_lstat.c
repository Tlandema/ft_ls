/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:55:34 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/09 14:06:38 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>

int main(void)
{

	char* folder=".";                           
	char *time_str;

	DIR* dir_p;
	struct dirent *dir_element;
	struct stat file_info;
	struct passwd *pwd;
	struct group *grp;

	dir_p = opendir(folder);

	while((dir_element = readdir(dir_p)) != NULL)
	{
		if (dir_element->d_name[0] != '.')
		{
			lstat(dir_element->d_name, &file_info);          
			puts(dir_element->d_name);                       
			printf("file mode: %d\n", file_info.st_mode);
			pwd = getpwuid(file_info.st_uid);
			printf("username: %s\n", pwd->pw_name);		
			grp = getgrgid(file_info.st_gid);
			printf("group: %s\n", grp->gr_name);
			printf("size: %lli\n", file_info.st_size);
			time_str = ctime(&file_info.st_mtimespec.tv_sec);
			printf("time modified: %s", time_str);
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
