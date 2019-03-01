/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:44:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/01 07:04:43 by tlandema         ###   ########.fr       */
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
	long long		time;
	long long		nano_time;
	long long		size;
	char			*list;
	char			color;
	char			isdir;
}					t_bra;

typedef struct		s_dir
{
	char			*options;
	int				one_dir;
	t_bra			*in_dir_bra;
	t_bra			*file_bra;
	t_bra			*bad_bra;
	t_bra			*dir_bra;
	struct stat		file_info;
	DIR				*dirp;
	char			*path;
	size_t			n_max;
	size_t			l_max;
	size_t			p_max;
	size_t			g_max;
	size_t			b_max;
	char			*dir_path;
	char			*first_dir;
	int				blocksize;
}					t_dir;

void				ft_path_forming(char *path, char *dir_name,
					char *file_name);
void				ft_acl(t_dir *dir, char *perm);
void				ft_free_list(t_bra *to_f);
void				ft_free(t_bra *to_f);
char				*ft_listing(t_dir *dir, char *name);

t_bra				*ft_create_branch(t_dir *dir, char *name);
void				ft_na_or_da_or_si(char *n_or_d, t_dir *dir, t_bra **use);
void				ft_size_branching(t_bra **root, t_dir *dir, char *name);
void				ft_name_branching(t_bra **root, t_dir *dir, char *name);
void				ft_date_branching(t_bra **root, t_dir *dir, char *name);

void				ft_dir_len_filler(t_dir *dir);
void				ft_rollback(t_bra *in_dir_bra, t_dir *dir, char *work);
void				ft_rollfront(t_bra *in_dir_bra, t_dir *dir, char *work);
int					ft_inside_dir(t_dir *dir, char *work);
int					ft_open_dir(t_dir *dir, char *dir_name);

void				ft_color_file(char c, char *name, int i);
char				ft_set_color(mode_t info);
void				ft_color(char **tab, int i);

int					ft_pad(int size_max, char color, char *name, int j);
void				ft_padding_helper_3(char **tab);
int					ft_padding(t_dir *dir, t_bra *bra, int j);
void				ft_print_lnk(char *link);
void				ft_print_error(char *name);
void				ft_print_bad_filler(t_bra *bad);
void				ft_print_spec(t_dir *dir, char *current, int j);
void				ft_print_dir(t_dir *dir, t_bra *bad);
void				ft_print_bad(t_dir *dir, t_bra *bad);
int					ft_print_file(t_dir *dir, t_bra *bad, int j);

void				ft_parse_branch(int i, char **av, t_dir *dir);
void				ft_parse_options(int ac, char **av, t_dir *dir);

#endif
