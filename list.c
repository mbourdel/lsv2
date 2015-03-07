/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:31:25 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/07 18:49:19 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_lst_directory(const char *directory, t_env *env)
{
	t_avdir		*lst_dir;

	lst_dir = (t_avdir*)malloc(sizeof(t_avdir));	
	lst_dir->nxt = env->lst_dir;
	lst_dir->name = ft_strdup(directory);
	env->lst_dir = lst_dir;
	return ;
}