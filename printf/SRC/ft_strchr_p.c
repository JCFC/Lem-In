/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:55:17 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:55:18 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

char		*ft_strchr_p(const char *s, int c, t_lst **lst, t_count *va)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ft_fill_lst(lst, s, i, va);
			return ((char*)s + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char*)s + i);
	ft_fill_lst(lst, s, i, va);
	return (NULL);
}
