/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:47:30 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/21 16:26:31 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_put_one_file(t_env *env)
{
	t_file		*nfile;
	t_dirent	*dirent;
	char		*tmp;
	char		*tmp2;

	if ((dirent = readdir(env->dir)) == NULL)
		return (0);
	if ((dirent->d_name[0] == '.') && !env->option.a)
		return (2);
	nfile = (t_file*)malloc(sizeof(t_file));
	nfile->name = ft_strdup(dirent->d_name);
	if (env->option.l || env->option.t)
	{
		tmp2 = ft_strjoin(env->lst_dir->name, "/");
		tmp = ft_strjoin(tmp2, nfile->name);
		((lstat(tmp, &nfile->stat)) == -1) ? ft_error(NULL) : 0;
		free(tmp);
		free(tmp2);
	}
	nfile->nxt = env->file;
	nfile->pvs = NULL;
	if (env->file != NULL)
		env->file->pvs = nfile;
	env->file = nfile;
	return (1);
}

static void		ft_get_the_files(t_env *env)
{
	int			dot;

	env->file = NULL;
	ft_reset_space(&env->option);
	while ((dot = ft_put_one_file(env)) != 0)
	{
		if ((env->file == NULL) && !dot)
			return ;
		if (dot == 1)
			ft_space(env);
	}
	return ;
}

void			ft_lets_go(t_env *env)
{
	t_avdir		*tmp;

	if (!(env->dir = opendir(env->lst_dir->name)))
	{
		ft_error(env->lst_dir->name);
		tmp = env->lst_dir->nxt;
		free(env->lst_dir->name);
		free(env->lst_dir);
		env->lst_dir = tmp;
	}
	else
	{
		ft_get_the_files(env);
		ft_sort_files(env);
		ft_print_output(env);
	}
	return ;
}
