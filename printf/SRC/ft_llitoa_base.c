/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:39:42 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:39:48 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static int		ft_count(long long int n, int base, int *tab)
{
	int			i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	return (i);
}

static void		ft_fill(char *str, int *tab, int unit, long long int n)
{
	int			i;
	int			x;

	x = unit;
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	while (i <= x)
	{
		str[i] = (tab[unit] < 10) ? tab[unit] + '0' : tab[unit] + 'a' - 10;
		unit--;
		i++;
	}
}

char			*ft_llitoa_base(long long int n, int base, int *u)
{
	char		*str;
	int			tab[64];
	int			tmp;

	*u = 0;
	str = NULL;
	*u = ft_count(n, base, tab);
	if (n == L_M - 1)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	str = (*u) ? ft_strnew(*u) : ft_strnew(1);
	if (!*u && str)
	{
		*u = 1;
		*str = '0';
		return (str);
	}
	tmp = *u;
	tmp--;
	if (str)
		ft_fill(str, tab, tmp, n);
	return (str);
}
