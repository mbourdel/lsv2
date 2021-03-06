/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:39:54 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/21 17:18:42 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define MTIME st_mtimespec.tv_sec
# include <uuid/uuid.h>

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <errno.h>
# include <stdio.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_passwd;

typedef struct s_long	t_long;
struct					s_long
{
	char				*right;
	char				*nb;
	char				*uid;
	char				*gid;
	char				*size;
	char				*date;
};

typedef struct s_maxs	t_maxs;
struct					s_maxs
{
	size_t				len_link;
	size_t				len_size;
	size_t				len_uid;
	size_t				len_gid;
};

typedef struct s_opt	t_option;
struct					s_opt
{
	int					no;
	int					a;
	int					l;
	t_maxs				max;
	int					t;
	int					r1;
	int					r2;
	int					error;
};

typedef struct s_avdir	t_avdir;
struct					s_avdir
{
	char				*name;
	int					err;
	t_avdir				*nxt;
};

typedef struct s_file	t_file;
struct					s_file
{
	char				*name;
	t_stat				stat;
	t_file				*pvs;
	t_file				*nxt;
};

typedef struct s_env	t_env;
struct					s_env
{
	t_avdir				*lst_dir;
	DIR					*dir;
	t_file				*file;
	t_option			option;
};

void					ft_error(char *str);
void					ft_seek_option(t_env *env, int ac, char **av);
void					ft_lst_directory(const char *directory, t_env *env);
void					ft_sort_files(t_env *env);
void					ft_destroy_them_all(t_env *env);
void					ft_print_total(t_file *file);
void					ft_print_output(t_env *env);
void					ft_option_l(t_env *env);
void					ft_lets_go(t_env *env);
void					ft_reset_space(t_option *option);
void					ft_space(t_env *env);
void					ft_print_symbol(t_env *env);

#endif
