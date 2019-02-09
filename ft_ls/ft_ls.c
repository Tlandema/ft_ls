/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:37:09 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/09 15:26:40 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>

/*int		ft_ls(char *)
{

}*/

int		main(int argc, char **argv)
{
	t_yes *yes;
	int i;

	i = 1;
	if (!(yes = (t_yes *)malloc(sizeof(t_yes))))
		return (-1);
	if (argc == 1)
	{
		yes->test->file = ".";
		printf("%s", yes->test->file);
	}
	else
		while (i < argc)
		{
			yes->test->file = argv[i];
			printf("%s\n", yes->test->file);
			yes->test = yes->test->next;
			i++;
		}

	free(yes);
	return (0);
}
