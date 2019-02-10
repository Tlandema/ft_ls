/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:38:43 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:42:14 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_tab_size(char const *s, char c)
{
	int		tab_size;
	int		i;
	int		bol;

	i = 0;
	bol = 1;
	tab_size = 0;
	while (s[i])
	{
		if (s[i] == c)
			bol = 1;
		else if (bol == 1)
		{
			bol = 0;
			tab_size++;
		}
		i++;
	}
	return (tab_size);
}

static int	*ft_letters(char const *s, char c)
{
	int		*tab_i;
	int		i;
	int		j;
	int		l;

	if (!(tab_i = (int*)ft_memalloc(sizeof(int) * ft_tab_size(s, c))))
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < ft_tab_size(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		l = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			l++;
		}
		tab_i[j] = l;
		j++;
	}
	return (tab_i);
}

static char	**ft_fill_tab(char const *s, char c, char **tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i] && j < ft_tab_size(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		k = 0;
		while (s[i] && s[i] != c)
		{
			tab[j][k] = s[i];
			i++;
			k++;
		}
		tab[j][k] = '\0';
		j++;
	}
	return (tab);
}

static void	let_it_go(int i, char ***tab)
{
	while (i >= 0)
	{
		ft_strclr(*tab[i]);
		ft_strdel(tab[i]);
		i--;
	}
	free(*tab);
	*tab = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		tab_size;
	int		i;
	int		*tab_i;

	if (s == NULL || !(tab_i = ft_letters(s, c)))
		return (NULL);
	tab_size = ft_tab_size(s, c);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (tab_size + 1))))
		return (NULL);
	tab[tab_size] = 0;
	i = 0;
	while (i < tab_size)
	{
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char) * (tab_i[i] + 1))))
		{
			let_it_go(i - 1, &tab);
			ft_memdel((void**)&tab_i);
			return (NULL);
		}
		i++;
	}
	ft_memdel((void**)&tab_i);
	return (ft_fill_tab(s, c, tab));
}
