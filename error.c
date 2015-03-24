/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:10:46 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/24 10:46:55 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(char *str)
{
	ft_putstr("ls: ");
	if (!str)
		ft_putendl(strerror(errno));
	else
		perror(str);
	errno = 0;
	return ;
}
