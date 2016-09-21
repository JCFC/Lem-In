/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:35:28 by jchen             #+#    #+#             */
/*   Updated: 2015/12/09 16:08:32 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;

	newstr = NULL;
	if (s == NULL || ft_strlen(s) < start + len)
		return (NULL);
	newstr = (char*)malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	newstr = ft_strncpy(newstr, s + start, len);
	newstr[len] = '\0';
	return (newstr);
}
