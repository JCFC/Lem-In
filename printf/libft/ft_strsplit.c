/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:55:12 by jchen             #+#    #+#             */
/*   Updated: 2015/12/15 16:48:10 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(const char *str, int n)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	tmp = (char*)malloc(sizeof(char) * (n + 1));
	if (tmp)
	{
		while (i != n)
		{
			tmp[i] = str[i];
			i++;
		}
	}
	tmp[i] = '\0';
	return (tmp);
}

static int		ft_nbword(char const *s, char c)
{
	int			nbword;

	nbword = 0;
	while (*s)
	{
		while (*s != c && *s != '\0')
			s++;
		nbword++;
		while (*s == c && *s != '\0')
			s++;
	}
	return (nbword);
}

static char		**ft_malloc_cpy(char const *s, char c, int nbword)
{
	int			size;
	int			i;
	char		**array;

	if ((array = (char**)malloc(sizeof(char*) * (nbword + 1))) == NULL)
		return (NULL);
	size = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
			if (size > 0)
			{
				array[i++] = ft_strndup(s - size, size);
				size = 0;
			}
		if (*s != c)
			size++;
		s++;
	}
	if (size > 0)
		array[i++] = ft_strndup(s - size, size);
	array[i] = 0;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;

	if (s == NULL)
		return (NULL);
	array = ft_malloc_cpy(s, c, ft_nbword(s, c));
	return (array ? array : NULL);
}
