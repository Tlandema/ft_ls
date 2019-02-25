/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:44:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/25 01:09:37 by tlandema         ###   ########.fr       */
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
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct		s_bra
{
	struct s_bra	*right;
	struct s_bra	*left;
	char			*name;
	char			*display;
	long long		time;
	long long		nano_time;
	char			*list;
	char			isdir;
}					t_bra;

typedef struct		s_dir
{
	int				*options;
	int				one_dir;
	t_bra			*in_dir_bra;
	t_bra			*file_bra;
	t_bra			*bad_bra;
	t_bra			*dir_bra;
	struct stat		file_info;
	DIR				*dirp;
	char			*path;
	char			*dir_path;
	char			*first_dir;
	char			first_stuff;
	int				blocksize;
}					t_dir;

void				ft_path_forming(char *path, char *dir_name,
		char *file_name);
void				ft_print_error(char *name);
void				ft_free_list(t_bra *to_f);
void				ft_padding(t_dir *dir, t_bra *bra);
void				ft_print_bad_filler(t_bra *bad);
void				ft_free(t_bra *to_f);
void				ft_rollback(t_bra *in_dir_bra, t_dir *dir, char *work);
void				ft_rollfront(t_bra *in_dir_bra, t_dir *dir, char *work);
void				ft_print_spec(t_dir *dir, char *current);
int					ft_inside_dir(t_dir *dir, char *work);
void				ft_name_or_date(char *n_or_d, t_dir *dir, t_bra **use);
char				*ft_listing(t_dir *dir, char *name);
t_bra				*ft_create_branch(t_dir *dir, char *name);
void				ft_name_branching(t_bra **root, t_dir *dir, char *name);
void				ft_date_branching(t_bra **root, t_dir *dir, char *name);
void				ft_parse_branch(int i, char **av, t_dir *dir);
void				ft_print_dir(t_dir *dir, t_bra *bad);
int					ft_open_dir(t_dir *dir, char *dir_name);
void				ft_print_bad(t_dir *dir, t_bra *bad);
void				ft_print_file(t_dir *dir, t_bra *bad);
void				ft_parse_options(int ac, char **av, t_dir *dir);

#endif
