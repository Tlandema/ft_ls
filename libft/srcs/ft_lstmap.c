/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <tlandema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:18:58 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:34:12 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*to_app;

	new = NULL;
	while (lst)
	{
		if (!(to_app = f(lst)))
		{
			ft_lstdel(&new, &ft_bzero);
			return (NULL);
		}
		ft_lstapp(&new, to_app);
		lst = lst->next;
	}
	return (new);
}
