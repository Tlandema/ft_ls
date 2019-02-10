/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:37:09 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/10 13:40:23 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/ft_printf.h"

char *parse_options(char *av, char *truc)
{
	int i;
	static int j = 0;

	i = 1;
	while (av[i])
	{
		if (ft_strchr("-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1", av[i]) != NULL)
		{
			truc[j] = av[i];
			j++;
		}
		i++;
	}
	return (truc);
}

t_yes	*parser(int ac, char **av, t_yes *yes, int i)
{
	char *truc;

	truc = NULL;
	ft_memset(truc, '\0', 40);
	if (ac == 1)
		return (yes);
	else
	{
		while (av[i])
		{
			parse_options(av[i], truc);
			i++;
		}
	}
	ft_putstr(truc);
	return (yes);
}

int		main(int ac, char **av)
{
	t_yes *yes;

	yes = NULL;
	if (!(yes = (t_yes *)malloc(sizeof(t_yes))))
		return (-1);
	if (!(yes = parser(ac, av, yes, 1)))
		return (-1);
	ft_printf("%c\n", yes->options[0]);
	free(yes);
	return (0);
}
