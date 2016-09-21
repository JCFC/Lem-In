/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:33:16 by jchen             #+#    #+#             */
/*   Updated: 2015/12/02 16:54:01 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	newstr = NULL;
	newstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s[i])
	{
		newstr[i] = (*f)(s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
