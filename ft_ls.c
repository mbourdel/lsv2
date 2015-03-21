/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:37:56 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/21 15:05:05 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av, char **envp)
{
	t_env	env;

	if (!*envp)
		return (0);
	env.dir = NULL;
	env.lst_dir = NULL;
	ft_seek_option(&env, ac, av);
	if (env.option.error)
		return (0);
	while (env.lst_dir != NULL)
		ft_lets_go(&env);
	return (0);
}
