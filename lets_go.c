/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:47:30 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/17 15:03:19 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_put_one_file(t_env *env)
{
	t_file		*nfile;
	char		*tmp;
	char		*tmp2;

	nfile = (t_file*)malloc(sizeof(t_file));
	if ((nfile->dirent = readdir(env->dir)) == NULL)
	{
		free(nfile);
		return (0);
	}
	tmp2 = ft_strjoin(env->lst_dir->name, "/");
	tmp = ft_strjoin(tmp2, nfile->dirent->d_name);
	if((stat(tmp, &nfile->stat)) == -1)
		ft_error(NULL);
	free(tmp);
	free(tmp2);
	nfile->nxt = env->file;
	nfile->pvs = NULL;
	if (env->file != NULL)
		env->file->pvs = nfile;
	env->file = nfile;
	return (1);
}

static void		ft_get_the_files(t_env *env)
{
	env->file = NULL;
	while (ft_put_one_file(env))
		if (env->file == NULL)
			return ;
	return ;
}

void			ft_lets_go(t_env *env)
{
	if (!(env->dir = opendir(env->lst_dir->name)))
	{
		ft_error(env->lst_dir->name);
		env->lst_dir = env->lst_dir->nxt;
	}
	else
	{
		ft_get_the_files(env);
		ft_sort_files(env);
		ft_print_output(env);
	}
	return ;
}
