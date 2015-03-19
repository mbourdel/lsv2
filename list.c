/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:31:25 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/19 16:01:03 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_lst_swap(t_avdir **tmp, t_avdir **nxt)
{
	char	*str;
	int		tmp_err;

	tmp_err = (*tmp)->err;
	str = ft_strdup((*tmp)->name);
	free((*tmp)->name);
	(*tmp)->name = ft_strdup((*nxt)->name);
	(*tmp)->err = (*nxt)->err;
	free((*nxt)->name);
	(*nxt)->name = ft_strdup(str);
	(*nxt)->err = tmp_err;
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
			if (tmp->err == nxt->err)
			{
				if (ft_strcmp(tmp->name, nxt->name) > 0 && (!env->option.r1 ||
							tmp->err))
					ft_lst_swap(&tmp, &nxt);
				if (ft_strcmp(tmp->name, nxt->name) < 0 && env->option.r1 &&
							!tmp->err)
					ft_lst_swap(&tmp, &nxt);
			}
			else if (!tmp->err && nxt->err)
				ft_lst_swap(&tmp, &nxt);
			nxt = nxt->nxt;
		}
		tmp = tmp->nxt;
	}
	return ;
}

static int		ft_time(const char *s1, const char *s2)
{
	t_stat		s1_s;
	t_stat		s2_s;

	stat(s1, &s1_s);
	stat(s2, &s2_s);
	if (s1_s.MTIME >= s2_s.MTIME)
		return (0);
	return (1);
}

static void		ft_sort_t(t_env *env)
{
	t_avdir		*tmp;
	t_avdir		*nxt;

	tmp = env->lst_dir;
	while (tmp)
	{
		nxt = tmp->nxt;
		while (nxt)
		{
			if (!tmp->err && !nxt->err)
			{
				if (ft_time(tmp->name, nxt->name) > 0 && !env->option.r1)
					ft_lst_swap(&tmp, &nxt);
				if (ft_time(tmp->name, nxt->name) < 0 && env->option.r1)
					ft_lst_swap(&tmp, &nxt);
			}
			nxt = nxt->nxt;
		}
		tmp = tmp->nxt;
	}
	return ;
}

void			ft_lst_directory(const char *directory, t_env *env)
{
	t_avdir		*lst_dir;
	DIR			*lol;

	lst_dir = (t_avdir*)malloc(sizeof(t_avdir));
	lst_dir->err = 0;
	lst_dir->nxt = env->lst_dir;
	lst_dir->name = ft_strdup(directory);
	if (!(lol = opendir(directory)))
		lst_dir->err = 1;
	else
		closedir(lol);
	env->lst_dir = lst_dir;
	ft_sort_directory(env);
	if (env->option.t)
		ft_sort_t(env);
	return ;
}
