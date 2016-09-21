/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:34:21 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 12:34:40 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void			ft_deflags(t_count *va, unsigned long long int i)
{
	va->h = 0;
	va->s = (va->plus) ? 0 : va->s;
	va->nb = (va->pcs && va->znb > 0) ? va->znb : va->nb;
	va->znb = (va->pcs) ? 0 : va->znb;
	va->convz = (i == 0 && va->pcsnb == 0 && va->pcs) ? 1 : va->convz;
}

void				ft_dm(va_list ap, t_count *va)
{
	long int		i;
	int				u;
	char			*tmp;

	if (!va->ml)
		i = va_arg(ap, long int);
	else
		i = ft_modify_unsigned_dm(ap, va);
	tmp = ft_llitoa_base(i, 10, &u);
	if (tmp)
	{
		ft_deflags(va, i);
		ft_fill_conv(va, u, tmp);
		free(tmp);
	}
}
