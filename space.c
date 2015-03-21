/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:59:33 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/21 16:56:20 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_symbol(t_env *env)
{
	char		*symbo;
	char		*tmp;
	char		*tmp2;

	symbo = ft_memalloc(30);
	tmp2 = ft_strjoin(env->lst_dir->name, "/");
	tmp = ft_strjoin(tmp2, env->file->name);
	if (readlink(tmp, symbo, 30) > 0)
	{
		ft_putstr(" -> ");
		ft_putstr(symbo);
	}
	free(symbo);
	free(tmp2);
	free(tmp);
	return ;
}

void		ft_reset_space(t_option *option)
{
	option->max.len_link = 0;
	option->max.len_size = 0;
	option->max.len_uid = 0;
	option->max.len_gid = 0;
	return ;
}

void		ft_space(t_env *env)
{
	size_t		nb;

	nb = ft_intlen(env->file->stat.st_nlink);
	env->option.max.len_link < nb ? env->option.max.len_link = nb : 0;
	nb = ft_intlen(env->file->stat.st_size);
	env->option.max.len_size < nb ? env->option.max.len_size = nb : 0;
	nb = ft_strlen((getpwuid(env->file->stat.st_uid))->pw_name);
	env->option.max.len_uid < nb ? env->option.max.len_uid = nb : 0;
	nb = ft_strlen((getgrgid(env->file->stat.st_gid))->gr_name);
	env->option.max.len_gid < nb ? env->option.max.len_gid = nb : 0;
	return ;
}
