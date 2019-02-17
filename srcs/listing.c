/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:52:50 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/17 18:39:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_listing(t_dir *dir, char *name)
{
	//struct passwd	*pwd;
	//struct group	*grp;
	char 			*test;

	name = NULL;
	test = ft_memalloc(sizeof(char) * 64);
	if (S_ISDIR(dir->file_info.st_mode))
		test[0] = 'd';
	else if (S_ISLNK(dir->file_info.st_mode))
		test[0] = 'l';
	else
		test[0] = '-';
	ft_putchar(test[0]);
	return (test);
}
