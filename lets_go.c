/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:47:30 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/07 18:58:41 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_put_one_file(t_env *env)
{
	t_file		*nfile;

	nfile = (t_file*)malloc(sizeof(t_file));
	if ((nfile->dirent = readdir(env->dir)) == NULL)
		return (0);
	if (stat(env->dirent->d_name, &nfile->stat))
		ft_error(*env);
	nfile->nxt = env->file;
	nfile->pvs = NULL;
	if (env->file)
		env->file->pvs = nfile;
	env->file = nfile;
	return (1);
}

static void		ft_get_the_files(t_env *env)
{
	env->file = NULL;
	while (ft_put_one_file(env))
		if (errno)
			ft_error(*env);
	return ;
}

void			ft_lets_go(t_env *env)
{
	t_avdir		*tmp;

	if (env->lst_dir)
	{
		env->dir = opendir(env->lst_dir->name);
		*tmp = *env->lst_dir->nxt;
		free(env->lst_dir);
		env->lst_dir = tmp;
	}
	else
		env->dir = opendir(".");
	if (env->dir == NULL)
		ft_error(*env);
	else
		ft_get_the_files(env);
	return ;
}
