/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:31:25 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/17 09:39:21 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_lst_swap(t_avdir **tmp, t_avdir **nxt)
{
	char	*str;

	str = ft_strdup((*tmp)->name);
	free((*tmp)->name);
	(*tmp)->name = ft_strdup((*nxt)->name);
	free((*nxt)->name);
	(*nxt)->name = ft_strdup(str);
	free(str);
	return ;
}

static void		ft_sort_directory(t_env *env)
{
	t_avdir		*tmp;
	t_avdir		*nxt;

	tmp = env->lst_dir;
	while (tmp)
	{
		nxt = tmp->nxt;
		while (nxt)
		{
			if (ft_strcmp(tmp->name, nxt->name) > 0 && !env->option.r1)
				ft_lst_swap(&tmp, &nxt);
			if (ft_strcmp(tmp->name, nxt->name) < 0 && env->option.r1)
				ft_lst_swap(&tmp, &nxt);
			nxt = nxt->nxt;
		}
		tmp = tmp->nxt;
	}
	return ;
}

void			ft_lst_directory(const char *directory, t_env *env)
{
	t_avdir		*lst_dir;

	lst_dir = (t_avdir*)malloc(sizeof(t_avdir));
	lst_dir->nxt = env->lst_dir;
	lst_dir->name = ft_strdup(directory);
	env->lst_dir = lst_dir;
	ft_sort_directory(env);
	return ;
}
