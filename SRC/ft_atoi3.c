/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:13:09 by jchen             #+#    #+#             */
/*   Updated: 2016/04/30 15:13:24 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void				ft_error(char *str, char *tmp, long long int i)
{
	if (*str == '\0')
		return ;
	if (!ft_isdigit(*str))
	{
		ft_putendl("ERROR");
		free(tmp);
		exit(0);
	}
	else if (i > INT_MAX || i < INT_MIN)
	{
		ft_putendl("ERROR");
		free(tmp);
		exit(0);
	}
}

static void				free_exit(char *str)
{
	free(str);
	exit(0);
}

int						ft_atoi3(char *str)
{
	long long int		i;
	char				*tmp;
	int					sign;

	sign = 1;
	tmp = str;
	i = 0;
	if (ft_strlen(str) == 1 && *str == '-' && ft_printf("ERROR\n"))
		free_exit(str);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		i = (i > 0) ? i * 10 : i;
		i = i + (*str - 48);
		ft_error(str, tmp, i);
		str++;
	}
	ft_error(str, tmp, i);
	return (i * sign);
}
