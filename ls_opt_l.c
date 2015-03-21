/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_opt_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 10:07:07 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/21 18:40:22 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_right(t_stat stat)
{
	char		*res;

	res = ft_memalloc(11);
	res = ft_memset(res, '-', 10);
	S_ISDIR(stat.st_mode) ? (res[0] = 'd') : 0;
	S_ISFIFO(stat.st_mode) ? (res[0] = 'p') : 0;
	S_ISCHR(stat.st_mode) ? (res[0] = 'c') : 0;
	S_ISLNK(stat.st_mode) ? (res[0] = 'l') : 0;
	S_ISSOCK(stat.st_mode) ? (res[0] = 's') : 0;
	S_ISBLK(stat.st_mode) ? (res[0] = 'b') : 0;
	(stat.st_mode & S_IRUSR) ? (res[1] = 'r') : 0;
	(stat.st_mode & S_IWUSR) ? (res[2] = 'w') : 0;
	(stat.st_mode & S_IXUSR) ? (res[3] = 'x') : 0;
	(stat.st_mode & S_IRGRP) ? (res[4] = 'r') : 0;
	(stat.st_mode & S_IWGRP) ? (res[5] = 'w') : 0;
	(stat.st_mode & S_IXGRP) ? (res[6] = 'x') : 0;
	(stat.st_mode & S_IROTH) ? (res[7] = 'r') : 0;
	(stat.st_mode & S_IWOTH) ? (res[8] = 'w') : 0;
	(stat.st_mode & S_IXOTH) ? (res[9] = 'x') : 0;
	return (res);
}

static char		*ft_date(time_t sec)
{
	char		*res;
	char		*tmp;
	int			i;

	i = (-1);
	res = ft_memalloc(14);
	tmp = ctime(&sec);
	if ((sec + 15552000) <= time(NULL) || time(NULL) < sec)
	{
		while (++i < 4)
			res[i] = tmp[i + 3];
		while (i < 8)
		{
			res[i] = tmp[i + 3];
			i++;
		}
		while (i < 12)
		{
			res[i] = tmp[i + 11];
			i++;
		}
		res[i++] = ' ';
	}
	if (!(i > 0))
		while (++i < 13)
			res[i] = tmp[i + 3];
	res[i] = ' ';
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
	size_t		nb;

	nb = (env->option.max.len_link - ft_intlen(env->file->stat.st_nlink) + 2);
	ft_putstr(lol.right);
	while (nb--)
		ft_putchar(' ');
	ft_putstr(lol.nb);
	ft_putchar(' ');
	ft_putstr(lol.uid);
	nb = (env->option.max.len_uid - ft_strlen(lol.uid) + 2);
	while (nb--)
		ft_putchar(' ');
	ft_putstr(lol.gid);
	nb = (env->option.max.len_gid - ft_strlen(lol.gid));
	while (nb--)
		ft_putchar(' ');
	nb = (env->option.max.len_size - ft_intlen(env->file->stat.st_size) + 2);
	while (nb--)
		ft_putchar(' ');
	ft_putstr(lol.size);
	ft_putstr(lol.date);
	ft_putstr(env->file->name);
	lol.right[0] == 'l' ? (ft_print_symbol(env)) : 0;
	ft_putchar('\n');
}

void			ft_option_l(t_env *env)
{
	t_long		lol;
	t_passwd	*pwuid;
	t_file		*tmp;

	tmp = env->file;
	ft_print_total(env->file);
	while (env->file != NULL)
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
		env->file = env->file->nxt;
	}
	env->file = tmp;
}
