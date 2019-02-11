/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:44:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/11 13:41:51 by tlandema         ###   ########.fr       */
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
# include "libft/includes/libft.h"

typedef struct s_fil
{
	long long truc;
}				t_fil;

typedef struct	s_dir
{
	int		*options;
	int		i;
	t_fil	**test;
}				t_dir;



#endif
