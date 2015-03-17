/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_opt_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 10:07:07 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/17 15:21:59 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_right(t_stat stat)
{
	char		*res;

	res = ft_memalloc(11);
	S_ISDIR(stat.st_mode) ? (res[0] = 'd') : 0;
	S_ISFIFO(stat.st_mode) ? (res[0] = 'p') : 0;
	S_ISCHR(stat.st_mode) ? (res[0] = 'c') : 0;
	S_ISLNK(stat.st_mode) ? (res[0] = 'l') : 0;
	S_ISSOCK(stat.st_mode) ? (res[0] = 's') : 0;
	S_ISBLK(stat.st_mode) ? (res[0] = 'b') : 0;
	S_ISREG(stat.st_mode) ? (res[0] = '-') : 0;
	(stat.st_mode & S_IRUSR) ? (res[1] = 'r') : (res[1] = '-');
	(stat.st_mode & S_IWUSR) ? (res[2] = 'w') : (res[2] = '-');
	(stat.st_mode & S_IXUSR) ? (res[3] = 'x') : (res[3] = '-');
	(stat.st_mode & S_IRGRP) ? (res[4] = 'r') : (res[4] = '-');
	(stat.st_mode & S_IWGRP) ? (res[5] = 'w') : (res[5] = '-');
	(stat.st_mode & S_IXGRP) ? (res[6] = 'x') : (res[6] = '-');
	(stat.st_mode & S_IROTH) ? (res[7] = 'r') : (res[7] = '-');
	(stat.st_mode & S_IWOTH) ? (res[8] = 'w') : (res[8] = '-');
	(stat.st_mode & S_IXOTH) ? (res[9] = 'x') : (res[9] = '-');
	return (res);
}

static char		*ft_date(time_t sec)
{
	char		*res;
	char		*tmp;
	int			i;

	i = 0;
	res = ft_memalloc(13);
	tmp = ctime(&sec);
	while (i < 13)
	{
		res[i] = tmp[i + 3];
		i++;
	}
	return (res);
}

static char		*ft_group(gid_t gid)
{
	struct group	*grp;
	char			*res;

	grp = getgrgid(gid);
	res = ft_strdup(grp->gr_name);
	return (res);
}

static void		ft_print_ls_l(t_env *env, t_long lol)
{
	ft_putstr(lol.right);
	ft_putstr(" \t");
	ft_putstr(lol.nb);
	ft_putstr(" \t");
	ft_putstr(lol.uid);
	ft_putstr("  ");
	ft_putstr(lol.gid);
	ft_putstr(" \t");
	ft_putstr(lol.size);
	ft_putstr("\t");
	ft_putstr(lol.date);
	ft_putstr(" ");
	ft_putendl(env->file->dirent->d_name);
	return ;
}

void			ft_option_l(t_env *env)
{
	t_long		lol;
	t_passwd	*pwuid;
	t_file		*tmp;

	tmp = env->file;
	while (env->file != NULL)
	{
		if (env->file->dirent->d_name[0] != '.' || env->option.a)
		{
			pwuid = getpwuid(env->file->stat.st_uid);
			lol.uid = ft_strdup(pwuid->pw_name);
			lol.right = ft_right(env->file->stat);
			lol.date = ft_date(env->file->stat.MTIME);
			lol.gid = ft_group(env->file->stat.st_gid);
			lol.size = ft_itoa(env->file->stat.st_size);
			lol.nb = ft_itoa(env->file->stat.st_nlink);
			ft_print_ls_l(env, lol);
			free(lol.right);
			free(lol.date);
			free(lol.gid);
			free(lol.uid);
			free(lol.nb);
			free(lol.size);
		}
		env->file = env->file->nxt;
	}
	env->file = tmp;
	return ;
}
