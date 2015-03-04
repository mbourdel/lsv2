/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 10:37:56 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/04 15:50:53 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av, char **envp)
{
	t_env	env;

	env.dir = NULL;
	env.lst_dir = NULL;
	ft_seek_option(&env, ac, av);
	if (env.option.error || !*envp)
		return (0);
	
	return (0);
}
