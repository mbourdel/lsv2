/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:39:54 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/10 16:00:50 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if ((defined __APPLE__) && (!defined MTIME))
# define MTIME st_mtimespec.tv_sec
#elif ((defined __linux) && (!defined MTIME))
# define MTIME st_mtime
#endif

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <errno.h>
# include <stdio.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_passwd;

typedef struct s_opt	t_option;
struct					s_opt
{
	int					no;
	int					a;
	int					l;
	int					t;
	int					r1;
	int					r2;
	int					error;
};

typedef struct s_avdir	t_avdir;
struct					s_avdir
{
	char				*name;
	t_avdir				*nxt;
};

typedef struct s_file	t_file;
struct					s_file
{
	t_dirent			*dirent;
	t_stat				stat;
	t_file				*pvs;
	t_file				*nxt;
};

typedef struct s_env	t_env;
struct					s_env
{
	t_avdir				*lst_dir;
	DIR					*dir;
	t_dirent			*dirent;
	t_file				*file;
	t_option			option;
};

void					ft_error(char *str);
void					ft_seek_option(t_env *env, int ac, char **av);
void					ft_lst_directory(const char *directory, t_env *env);
void					ft_sort_files(t_env *env);
void					ft_lets_go(t_env *env);
#endif
