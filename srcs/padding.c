/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:24:11 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/21 11:54:21 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_padding(char *test)
{
	char **tab;

	tab = ft_strsplit(test, ' ');
	ft_printf("%-11s%3s%10s%12s", tab[0], tab[1], tab[2], tab[3]);
	ft_printf("%8s%4s%3s%6s ", tab[4], tab[5], tab[6], tab[7]);
	ft_tabdel(8, &tab);
}
