/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:37:09 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/12 23:28:43 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	init(t_dir *dir)
{
	dir->options = ft_memalloc(sizeof(int) * 5);
	dir->bra = NULL;
}

int		main(int ac, char **av)
{
	t_dir *dir;

	dir = NULL;
	dir = ft_memalloc(sizeof(t_dir));
	init(dir);
	ft_parse_options(ac, av, dir);
	free(dir);
	ft_putstr("\nbah yes, le programme a pas crash.\n");
	return (0);
}
