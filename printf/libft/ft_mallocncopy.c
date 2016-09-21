/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocncopy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:26:18 by jchen             #+#    #+#             */
/*   Updated: 2015/12/29 11:25:43 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_mallocncopy(const char *str, size_t size)
{
	char			*tmp;
	size_t			i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	else
		while (i < size && *str)
		{
			tmp[i] = str[i];
			i++;
		}
	tmp[i] = '\0';
	return (tmp);
}
