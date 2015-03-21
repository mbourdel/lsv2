/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 12:36:41 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/21 14:57:28 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_total(t_file *file)
{
	int		total;
	char	*tmp;

	total = 0;
	while (file != NULL)
	{
		total += (int)file->stat.st_blocks;
		file = file->nxt;
	}
	tmp = ft_itoa(total);
	ft_putstr("total ");
	ft_putendl(tmp);
	free(tmp);
	return ;
}
