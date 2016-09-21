/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:33:43 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 14:48:48 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void			ft_deflags(t_count *va, long long int i)
{
	va->h = 0;
	va->s = (va->plus) ? 0 : va->s;
	va->s = (i < 0) ? 0 : va->s;
	va->nb = (va->pcs && va->znb > 0) ? va->znb : va->nb;
	va->znb = (va->pcs) ? 0 : va->znb;
	va->plus = (i < 0) ? 0 : va->plus;
	va->neg = (i < 0) ? 1 : va->neg;
	va->convz = (i == 0 && va->pcsnb == 0 && va->pcs) ? 1 : va->convz;
}

void				ft_d(va_list ap, t_count *va)
{
	long long int	i;
	int				u;
	char			*tmp;

	if (!va->ml)
		i = va_arg(ap, int);
	else
		i = ft_modify(ap, va);
	va->cpynb = i;
	tmp = ft_llitoa_base(i, 10, &u);
	if (tmp)
	{
		ft_deflags(va, i);
		ft_fill_conv(va, u, tmp);
		free(tmp);
	}
}
