/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:59:47 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 14:00:18 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void					ft_deflags(t_count *va, unsigned long long int i,\
		int *size)
{
	va->xh = (va->h && i != 0) ? 2 : va->xh;
	va->hl = 'X';
	va->h = (va->h && i == 0 && va->pcs && va->pcsnb >= 0) ? 0 : va->h;
	va->h = (va->h && i == 0 && va->less) ? 0 : va->h;
	va->plus = 0;
	va->s = 0;
	va->convz = (i == 0 && va->pcsnb == 0 && va->pcs) ? 1 : va->convz;
}

void						ft_xm(va_list ap, t_count *va)
{
	char					*tmp;
	char					*tmp3;
	unsigned int long long	i;
	int						size;

	if (!va->ml)
		i = va_arg(ap, unsigned int);
	else
		i = ft_modify_unsigned(ap, va);
	tmp = ft_ullitoa_base(i, 16, 'A', &size);
	if (tmp)
	{
		tmp3 = tmp;
		if (tmp)
		{
			ft_deflags(va, i, &size);
			ft_fill_conv(va, size, tmp);
			free(tmp);
		}
	}
}
