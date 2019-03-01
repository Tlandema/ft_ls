/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 00:51:37 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/01 10:57:02 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <errno.h>
#include <stdio.h>

void	ft_print_error(t_dir *dir, t_bra *direc)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(direc->name) + 5);
	ft_strcpy(tmp, "ls: ");
	ft_strcat(tmp, direc->name);
	if (errno == 2)
		perror(tmp);
	if (errno == 13)
		perror(tmp);
	if (errno == 0)
	{
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putstr(dir->dir_path);
		ft_putchar(':');
	}
	free(tmp);
}
