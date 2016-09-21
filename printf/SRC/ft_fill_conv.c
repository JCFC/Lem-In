/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:44:21 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 15:43:48 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static int			ft_sort(t_count *va, int u, char *str)
{
	int		tab[5];
	int		i;

	i = 0;
	tab[0] = va->pcsnb;
	tab[1] = va->nb;
	tab[2] = va->znb;
	tab[3] = u + va->plus + va->s + va->xh;
	tab[4] = 0;
	while (i < 3)
	{
		if (tab[i] < tab[i + 1])
		{
			tab[4] = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tab[4];
			i = -1;
		}
		i++;
	}
	tab[0] = (va->pcsnb == tab[0]) ?\
		tab[0] + va->plus + va->neg + va->s + va->xh : tab[0];
	return (tab[0]);
}

static int			ft_sort2(t_count *va, int u, char *str, int i)
{
	int				tmp;
	int				verify;

	tmp = u + va->plus + va->xh;
	va->nb = (va->pcsnb >= u) ?\
		(va->nb - va->pcsnb - va->neg - va->plus - va->xh) : (va->nb - tmp);
	va->znb = (va->pcsnb > u) ?\
		(va->znb - va->pcsnb - va->neg - va->plus - va->xh) : (va->znb - tmp);
	va->pcsnb = va->pcsnb - (u - va->neg);
	va->nb = (va->nb < 0) ? 0 : va->nb;
	va->znb = (va->znb < 0) ? 0 : va->znb;
	va->pcs = (va->pcs < 0) ? 0 : va->pcs;
	verify = (va->xh) ? va->nb + va->znb + va->pcsnb + u + va->xh : 0;
	return (u = (va->xh && verify > i) ? verify : i);
}

static void			ft_create_l2(t_count *va, char *tmp, int *count)
{
	(va->s) ? tmp[(*count)++] = 32 : tmp[*count];
	(va->neg) ? tmp[(*count)++] = '-' : tmp[*count];
	(va->plus) ? tmp[(*count)++] = '+' : tmp[*count];
	(va->h) ? tmp[(*count)++] = '0' : tmp[*count];
	(va->h) ? tmp[(*count)++] = va->hl : tmp[*count];
}

static void			ft_create_l(t_count *va, int u, char *str, int i)
{
	char			*tmp;
	int				count;

	tmp = NULL;
	count = 0;
	tmp = ft_strnew(i);
	if (tmp)
	{
		ft_create_l2(va, tmp, &count);
		while (va->pcsnb > 0 && count < i)
		{
			tmp[count++] = '0';
			va->pcsnb--;
		}
		(va->cpynb < 0) ? ft_strncat(tmp, &str[1], u - 1) :\
			ft_strncat(tmp, str, u);
		count = (*str == '-') ? count + u - 1 : count + u;
		while (va->nb > 0 && count < i)
		{
			tmp[count++] = 32;
			va->nb--;
		}
		ft_fill_lst(&va->lst, tmp, i, va);
		free(tmp);
	}
}

void				ft_fill_conv(t_count *va, int u, char *str)
{
	int				i;

	u = (va->convz == 1) ? 0 : u;
	i = ft_sort(va, u, str);
	i = ft_sort2(va, u, str, i);
	(va->less) ? ft_create_l(va, u, str, i) : ft_create_wo_l(va, u, str, i);
	ft_reset_flags(va);
}
