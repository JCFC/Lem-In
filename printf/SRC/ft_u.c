/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:55:33 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:55:56 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void					ft_deflags(t_count *va, int i)
{
	va->plus = 0;
	va->s = 0;
	va->h = 0;
	va->nb = (va->pcs && va->znb > 0) ? va->znb : va->nb;
	va->znb = (va->pcs) ? 0 : va->znb;
	va->convz = (i == 0 && va->pcsnb == 0 && va->pcs) ? 1 : va->convz;
}

void						ft_u(va_list ap, t_count *va)
{
	unsigned long long int	i;
	char					*tmp;
	int						u;

	if (!va->ml)
		i = va_arg(ap, unsigned int);
	else
		i = ft_modify_unsigned(ap, va);
	tmp = ft_ullitoa_base(i, 10, 'a', &u);
	if (tmp)
	{
		ft_deflags(va, i);
		ft_fill_conv(va, u, tmp);
		free(tmp);
	}
}
