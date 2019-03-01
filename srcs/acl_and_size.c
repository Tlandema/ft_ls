/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl_and_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 01:04:16 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/01 06:15:48 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/acl.h>

void	ft_size_branching(t_bra **root, t_dir *dir, char *name)
{
	if (*root == NULL)
	{
		*root = ft_create_branch(dir, name);
		return ;
	}
	if (dir->file_info.st_size > (*root)->size)
		ft_size_branching(&(*root)->left, dir, name);
	else
		ft_size_branching(&(*root)->right, dir, name);
}

void	ft_acl(t_dir *dir, char *perm)
{
	acl_t		acl;
	ssize_t		xattr;
	char		str[2];
	acl_entry_t	dummy;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np(dir->path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(dir->path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	str[1] = '\0';
	if (xattr > 0)
		str[0] = '@';
	else if (acl != NULL)
		str[0] = '+';
	else
		str[0] = ' ';
	acl_free(acl);
	ft_strcat(perm, str);
}
