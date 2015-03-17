/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:38:38 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/17 18:45:36 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_destroy_file(t_env *env)
{
	while (env->file->pvs != NULL)
		env->file = env->file->pvs;
	while (env->file->nxt != NULL)
	{
		free(env->file->name);
		env->file = env->file->nxt;
		free(env->file->pvs);
	}
	free(env->file->name);
	free(env->file);
	env->file = NULL;
}

void			ft_destroy_them_all(t_env *env)
{
	t_avdir		*tmp;

	tmp = env->lst_dir->nxt;
	if (env->dir != NULL)
		closedir(env->dir);
	free(env->lst_dir->name);
	free(env->lst_dir);
	env->lst_dir = tmp;
	ft_destroy_file(env);
	return ;
}
