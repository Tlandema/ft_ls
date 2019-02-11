/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:55:14 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/11 10:52:49 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	DIR				*dirp;
	struct dirent	*dp;
	char			*file_name;

	dirp = opendir(av[dir->i]);
	while ((dp = readdir(dirp)) != NULL)
	{
			file_name = dp->d_name;
			printf("%s ", file_name);
	}
	closedir(dirp);
	return 0;
}
