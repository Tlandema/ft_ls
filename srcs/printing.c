/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:59:39 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/12 23:29:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void        ft_print_bad(t_dir *dir, t_bra *bad)
{
	if (bad->left)
		ft_print_bad(dir, bad->left);
	ft_printf("%s", bad->display);
	if (bad->right)
		ft_print_bad(dir, bad->right);
}
