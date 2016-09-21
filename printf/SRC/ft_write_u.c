/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:59:07 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:59:09 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static int		ft_wchart_1(t_count *va, unsigned int t, unsigned int mask1,\
		char *str)
{
	unsigned char o2;
	unsigned char o1;
	unsigned char octet;

	mask1 = 49280;
	o2 = (t << 26) >> 26;
	o1 = ((t >> 6) << 27) >> 27;
	octet = (mask1 >> 8) | o1;
	str[0] = octet;
	octet = ((mask1 << 24) >> 24) | o2;
	str[1] = octet;
	return (2);
}

static int		ft_wchart_2(t_count *va, unsigned int t, unsigned int mask2,\
		char *str)
{
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;
	unsigned char octet;

	mask2 = 14712960;
	o3 = (t << 26) >> 26;
	o2 = ((t >> 6) << 26) >> 26;
	o1 = ((t >> 12) << 28) >> 28;
	octet = (mask2 >> 16) | o1;
	str[0] = octet;
	octet = ((mask2 << 16) >> 24) | o2;
	str[1] = octet;
	octet = ((mask2 << 24) >> 24) | o3;
	str[2] = octet;
	return (3);
}

static int		ft_wchart_3(t_count *va, unsigned int t, unsigned int mask3,\
		char *str)
{
	unsigned char o4;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;
	unsigned char octet;

	mask3 = 4034953344;
	o4 = (t << 26) >> 26;
	o3 = ((t >> 6) << 26) >> 26;
	o2 = ((t >> 12) << 26) >> 26;
	o1 = ((t >> 18) << 29) >> 29;
	octet = (mask3 >> 24) | o1;
	str[0] = octet;
	octet = ((mask3 << 8) >> 24) | o2;
	str[1] = octet;
	octet = ((mask3 << 16) >> 24) | o3;
	str[2] = octet;
	octet = ((mask3 << 24) >> 24) | o4;
	str[3] = octet;
	return (4);
}

int				ft_write_u(t_count *va, int unit, unsigned int wchar, char *str)
{
	if (unit <= 7)
	{
		str[0] = wchar;
		return (1);
	}
	else if (unit <= 11)
		return (ft_wchart_1(va, wchar, 0, str));
	else if (unit <= 16)
		return (ft_wchart_2(va, wchar, 0, str));
	else
		return (ft_wchart_3(va, wchar, 0, str));
	return (0);
}
