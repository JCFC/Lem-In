/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:50 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:51 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int		ft_nbword2(char const *s, char c)
{
	int			nbword;
	int			tmp;

	tmp = 0;
	nbword = 0;
	while (*s)
	{
		while (*s != c && *s != '\0')
		{
			(!tmp) ? nbword++ : 0;
			tmp++;
			s++;
		}
		while (*s == c && *s != '\0')
			s++;
		tmp = 0;
	}
	return (nbword);
}

int				ft_nbword(char *s, char c)
{
	int			y;

	if (*s == c && ft_printf("ERROR\n"))
		exit(0);
	if (!(y = ft_count_char(s, c)))
		return (1);
	else if (y == 2)
		return (ft_nbword2(s, c));
	return (0);
}
