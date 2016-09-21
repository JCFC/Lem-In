/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:00:04 by jchen             #+#    #+#             */
/*   Updated: 2016/02/06 17:37:13 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*tmp10;

	tmp10 = NULL;
	tmp10 = (char*)malloc(sizeof(char) * (size + 1));
	if (tmp10 == NULL)
		return (NULL);
	tmp10 = ft_memset(tmp10, '\0', (size + 1));
	return (tmp10);
}
