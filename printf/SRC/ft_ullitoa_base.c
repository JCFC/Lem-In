/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:56:01 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:56:37 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static int			ft_count(unsigned long long int n, int base, int *tab)
{
	int				i;

	i = 0;
	while (n)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	return (i);
}

static void			ft_fill(char *str, int *tab, int unit, char letter)
{
	int				i;
	int				x;

	x = unit;
	i = 0;
	while (i <= x)
	{
		str[i] = (tab[unit] < 10) ? tab[unit] + '0' : tab[unit] + letter - 10;
		unit--;
		i++;
	}
}

char				*ft_ullitoa_base(unsigned long long int n, int base,\
		char l, int *u)
{
	char			*str;
	int				tab[64];
	int				tmp;

	*u = 0;
	str = NULL;
	*u = ft_count(n, base, tab);
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
		ft_fill(str, tab, tmp, l);
	return (str);
}
