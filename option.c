/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 11:44:18 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/04 15:38:46 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_error_option(const char str, t_option *option)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(str);
	ft_putchar('\n');
	ft_putstr("usage: ls ");
	ft_putendl("[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	option->error = 1;
	return ;
}

static void		ft_which_one(const char *str, t_option *option)
{
	if (str[1] == '-' && !str[2])
		option->no = 1;
	else if (str[1] == '-' && str[2] && !option->no)
		ft_error_option('-', option);
	else if (str[1])
		ft_attribute_option(str + 1, option);
	return ;
}

static void		ft_attribute_option(const char *str, t_option *option)
{
	if (*str)
	{
		if (*str == 'a')
			option->a = 1;
		else if (*str == 'l')
			option->l = 1;
		else if (*str == 't')
			option->t = 1;
		else if (*str == 'r')
			option->r1 = 1;
		else if (*str == 'R')
			option->r2 = 1;
		else
			ft_error_option(*str, option);
		if (str[1] && !option->error)
			ft_attribute_option(str + 1, option);
	}
	return ;
}

static void		ft_init_option(t_option *option)
{
	option->no = 0;
	option->a = 0;
	option->l = 0;
	option->t = 0;
	option->r1 = 0;
	option->r2 = 0;
	option->error = 0;
	return ;
}

void			ft_seek_option(t_env *env, int ac, char **av)
{
	int			i;

	ft_init_option(&env->option);
	if (ac == 1)
		env->option.no = 1;
	i = 1;
	ac--;
	while (av[i] && ac)
	{
		if (av[i][0] == '-' && !env->option.no)
			ft_which_one(av[i], &env->option);
		else
		{
			env->option.no = 1;
		}
		ac--;
		i++;
	}
	return ;
}
