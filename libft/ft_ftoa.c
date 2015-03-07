/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:03:16 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/20 15:01:12 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ftoa(float nbr)
{
	int			entire;
	float		floating;
	char		*res;

	entire = (int)nbr;
	floating = nbr - (float)entire;
	while (floating != (int)floating)
		floating *= 10;
	res = ft_strjoin(ft_strjoin(ft_itoa(entire), "."), ft_itoa((int)floating));
	return (res);
}
