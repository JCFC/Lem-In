/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 12:17:49 by jchen             #+#    #+#             */
/*   Updated: 2015/12/23 13:15:01 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[y] != '\0')
	{
		s1[i] = s2[y];
		i++;
		y++;
	}
	s1[i] = '\0';
	return (s1);
}
