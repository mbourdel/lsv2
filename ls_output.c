/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:25:36 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/16 14:47:36 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_nm(t_env *env)
{
	while (env->file->nxt != NULL)
	{
		if ((!env->option.a && env->file->dirent->d_name[0] != '.')
					|| env->option.a)
			ft_putendl(env->file->dirent->d_name);
		env->file = env->file->nxt;
	}
	if ((!env->option.a && env->file->dirent->d_name[0] != '.')
				|| env->option.a)
		ft_putendl(env->file->dirent->d_name);
	return ;
}

static void	ft_print_l(t_env *env)
{
	while (env->file->nxt != NULL)
	{
		if ((!env->option.a && env->file->dirent->d_name[0] != '.')
					|| env->option.a)
			ft_putendl(env->file->dirent->d_name);
		env->file = env->file->nxt;
	}
	if ((!env->option.a && env->file->dirent->d_name[0] != '.')
				|| env->option.a)
		ft_putendl(env->file->dirent->d_name);
	return ;
}

static void ft_print_r(t_env *env)
{
	while (env->file->nxt != NULL)
	{
		if ((!env->option.a && env->file->dirent->d_name[0] != '.')
					|| env->option.a)
			ft_putendl(env->file->dirent->d_name);
		env->file = env->file->nxt;
	}
	if ((!env->option.a && env->file->dirent->d_name[0] != '.')
				|| env->option.a)
		ft_putendl(env->file->dirent->d_name);
	return ;
}

void		ft_print_output(t_env *env)
{
	if (env->option.r2)
		ft_print_r(env);
	else if (env->option.l)
		ft_print_l(env);
	else
		ft_print_nm(env);
	ft_destroy_them_all(env);
	return ;
}
