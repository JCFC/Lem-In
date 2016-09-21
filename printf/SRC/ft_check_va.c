/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_va.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:30:23 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 12:32:13 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

t_conv g_modify[] = {
	{'h', ft_h},
	{'l', ft_l},
	{'j', ft_j},
	{'z', ft_z},
	{-1, NULL},
};

t_conv g_flags[] = {
	{'#', ft_hash},
	{'+', ft_plus},
	{' ', ft_space},
	{'.', ft_precision},
	{'-', ft_less},
	{-1, NULL},
};

t_conv g_conv[] = {
	{'d', ft_d},
	{'i', ft_d},
	{'c', ft_c},
	{'s', ft_s},
	{'o', ft_o},
	{'p', ft_p},
	{'O', ft_om},
	{'u', ft_u},
	{'U', ft_um},
	{'x', ft_x},
	{'X', ft_xm},
	{'%', ft_percent},
	{'C', ft_cm},
	{'S', ft_sm},
	{'D', ft_dm},
	{-1, NULL},
};

static int			ft_check_flags(char *str, t_count *v, va_list ap)
{
	int				i;
	int				y;

	y = 0;
	i = 0;
	while (g_flags[i].p != NULL && y != 1)
	{
		if (g_flags[i].f == *str && (y = 1))
			g_flags[i].p(ap, v);
		else if (*str >= '0' && *str <= '9' && (y = 1))
			ft_number(ap, v, *str);
		i++;
	}
	return (y);
}

static	int			ft_check_modify(char *str, t_count *v, va_list ap)
{
	int				i;
	int				y;

	y = 0;
	i = 0;
	while (g_modify[i].p != NULL && y != 1)
	{
		if (g_modify[i].f == *str && (y = 1))
			g_modify[i].p(ap, v);
		i++;
	}
	return (y);
}

static void			ft_put_rest(t_count *va)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = NULL;
	tmp = (va->nb > 0) ? ft_strnew(va->nb) : tmp;
	tmp = (va->znb > 0) ? ft_strnew(va->znb) : tmp;
	if (tmp)
	{
		while (i < va->nb - 1)
			tmp[i++] = ' ';
		while (i < va->znb - 1)
			tmp[i++] = '0';
		ft_fill_lst(&va->lst, tmp, i, va);
		free(tmp);
	}
	ft_reset_flags(va);
}

static	int			ft_check_conv(char *str, t_count *v, va_list ap)
{
	int				i;

	i = 0;
	while (g_conv[i].p != NULL)
	{
		if (g_conv[i].f == *str)
		{
			g_conv[i].p(ap, v);
			return (1);
		}
		i++;
	}
	ft_put_rest(v);
	return (0);
}

int					ft_check_va(char *format, t_count *v, va_list ap)
{
	int				i;

	i = 0;
	while (ft_check_flags(&format[i], v, ap))
		i++;
	while (ft_check_modify(&format[i], v, ap))
		i++;
	return (i += ft_check_conv(&format[i], v, ap));
}
