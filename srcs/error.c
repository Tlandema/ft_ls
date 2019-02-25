/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 00:51:37 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/25 01:20:26 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <errno.h>
#include <stdio.h>

void	ft_print_error(char *name)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(name) + 5);
	ft_strcpy(tmp, "ls: ");
	ft_strcat(tmp, name);
	if (errno == 2)
		perror(tmp);
	if (errno == 13)
		perror(tmp);
	free(tmp);
}
