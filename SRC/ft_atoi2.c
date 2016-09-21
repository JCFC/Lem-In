/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:10 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:11 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void				ft_error(char *str, char *tmp, long long int i)
{
	if (*str == '\0')
		return ;
	if (*str == '-' || !ft_isdigit(*str))
	{
		ft_putendl("ERROR");
		free(tmp);
		exit(0);
	}
	else if (i > INT_MAX)
	{
		ft_putendl("ERROR");
		free(tmp);
		exit(0);
	}
}

int						ft_atoi2(char *str)
{
	long long int		i;
	char				*tmp;

	tmp = str;
	i = 0;
	while (ft_isdigit(*str))
	{
		i = (i > 0) ? i * 10 : i;
		i = i + (*str - 48);
		ft_error(str, tmp, i);
		str++;
	}
	ft_error(str, tmp, i);
	return (i);
}
