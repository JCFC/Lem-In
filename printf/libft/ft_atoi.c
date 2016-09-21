/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 12:15:49 by jchen             #+#    #+#             */
/*   Updated: 2015/12/23 12:15:51 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		resultat;

	resultat = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\v' || str[i] == '\r' || str[i] == ' '
			|| str[i] == '\f' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = (resultat * 10) + str[i] - '0';
		i++;
	}
	return (sign * resultat);
}
