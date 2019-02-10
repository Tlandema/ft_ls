/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:17:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:33:27 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_swap(t_list **begin, int n)
{
	t_list		*tmp;
	t_list		*prev;

	if (begin == NULL || (*begin) == NULL)
		return (NULL);
	tmp = *begin;
	if (n <= 1)
		return (*begin);
	else
		prev = ft_lstnelem(tmp, n - 1);
	tmp = prev->next;
	if (prev)
		prev->next = tmp->next;
	else
		*begin = tmp->next;
	tmp->next = *begin;
	*begin = tmp;
	return (*begin);
}
