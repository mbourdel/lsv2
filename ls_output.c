/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 10:25:36 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/24 12:40:48 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_nm(t_env *env)
{
	while (env->file->nxt != NULL)
	{
		if ((!env->option.a && env->file->name[0] != '.')
					|| env->option.a)
			ft_putendl(env->file->name);
		env->file = env->file->nxt;
	}
	if ((!env->option.a && env->file->name[0] != '.')
				|| env->option.a)
		ft_putendl(env->file->name);
	return ;
}

static void	ft_print_l(t_env *env)
{
	ft_option_l(env);
	return ;
}

static void ft_print_r(t_env *env)
{
	while (env->file->nxt != NULL)
	{
		if ((!env->option.a && env->file->name[0] != '.')
					|| env->option.a)
			ft_putendl(env->file->name);
		env->file = env->file->nxt;
	}
	if ((!env->option.a && env->file->name[0] != '.')
				|| env->option.a)
		ft_putendl(env->file->name);
	return ;
}

void		ft_print_output(t_env *env)
{
	static int	save = 0;

	if (env->lst_dir->nxt != NULL || save)
	{
		ft_putstr(env->lst_dir->name);
		ft_putendl(":");
		save = 1;
	}
	if (env->file != NULL)
	{
		if (env->option.r2)
			ft_print_r(env);
		else if (env->option.l)
			ft_print_l(env);
		else
			ft_print_nm(env);
	}
	if (env->lst_dir->nxt != NULL)
		ft_putchar('\n');
	ft_destroy_them_all(env);
	return ;
}
