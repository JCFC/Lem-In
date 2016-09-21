/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:43:45 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:44:12 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_gnl(char **str, int boole)
{
	int		i;

	i = 0;
	*str = NULL;
	while (!*str)
	{
		i = get_next_line(0, str);
		if (!i)
			break ;
	}
	(boole && *str) ? ft_putendl(*str) : 0;
	return (i);
}
