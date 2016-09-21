/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:22:53 by jchen             #+#    #+#             */
/*   Updated: 2015/12/02 17:01:54 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_fstrndup(char const *str, int n)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	tmp = (char*)malloc(sizeof(char) * (n + 1));
	if (tmp == NULL)
		return (NULL);
	while (i != n)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char			*ft_strtrim(char const *s)
{
	int			i;
	char		*newstr;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (*s == '\t' || *s == '\n' || *s == ' ')
		s++;
	i = ft_strlen(s) - 1;
	if (i < 0)
	{
		newstr = ft_fstrndup((char*)s, 0);
		return (newstr ? newstr : NULL);
	}
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	newstr = ft_fstrndup((char*)s, i + 1);
	return (newstr ? newstr : NULL);
}
