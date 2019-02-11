/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:44:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/11 15:35:22 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include "../libft/includes/libft.h"

typedef struct s_fil
{
	   int mode;
	   char *name;
	   char *user;
	   char *group;
	   long long size;
	   char *time;
	   int hard;
	   struct s_fil *next;
}               t_fil;

typedef struct	s_yes
{
	t_fil *fil;
}				t_yes;



#endif
