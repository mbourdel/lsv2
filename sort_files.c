/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:23:26 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/17 17:29:22 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_switch_file(t_env *env)
{
	char			*tmp_d;
	t_stat			tmp_s;

	tmp_d = ft_strdup(env->file->name);
	tmp_s = env->file->stat;
	free(env->file->name);
	env->file->name = ft_strdup(env->file->nxt->name);
	env->file->stat = env->file->nxt->stat;
	free(env->file->nxt->name);
	env->file->nxt->name = ft_strdup(tmp_d);
	env->file->nxt->stat = tmp_s;
	free(tmp_d);
	return ;
}

static int		ft_count_file(t_file *file)
{
	int		i;

	i = 1;
	while (file->nxt)
	{
		file = file->nxt;
		i++;
	}
	return (i);
}

static void		ft_sort_nm_ls(t_env *env)
{
	int			i;
	int			j;

	j = 0;
	i = ft_count_file(env->file);
	while (j++ <= i)
	{
		while (env->file->nxt)
		{
			if (env->option.r1)
			{
				if (ft_strcmp(env->file->name,
					env->file->nxt->name) < 0)
					ft_switch_file(env);
			}
			else if (ft_strcmp(env->file->name,
				env->file->nxt->name) > 0)
				ft_switch_file(env);
			env->file = env->file->nxt;
		}
		while (env->file->pvs)
			env->file = env->file->pvs;
	}
	return ;
}

static void		ft_sort_t_ls(t_env *env)
{
	int			i;
	int			j;

	j = 0;
	i = ft_count_file(env->file);
	while (j++ <= i)
	{
		while (env->file->nxt)
		{
			if (env->file->stat.MTIME > env->file->nxt->stat.MTIME
				&& !env->option.r1)
				ft_switch_file(env);
			else if (env->file->stat.MTIME < env->file->nxt->stat.MTIME
				&& env->option.r1)
				ft_switch_file(env);
			env->file = env->file->nxt;
		}
		while (env->file->pvs)
			env->file = env->file->pvs;
	}
	return ;
}

void			ft_sort_files(t_env *env)
{
	ft_sort_nm_ls(env);
	if (env->option.t)
		ft_sort_t_ls(env);
	return ;
}
