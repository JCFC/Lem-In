/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 13:49:11 by jchen             #+#    #+#             */
/*   Updated: 2016/04/30 13:49:12 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_gnl2(char **str)
{
	int			i;

	i = 0;
	*str = NULL;
	ft_putstr("Choice a end : ");
	while (!*str)
	{
		i = get_next_line(1, str);
		if (!i)
			break ;
	}
	return (i);
}
