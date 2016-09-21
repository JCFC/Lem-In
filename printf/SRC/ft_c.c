/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:29:42 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 12:30:08 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void	ft_deflags(t_count *va, int u)
{
	va->h = 0;
	va->s = 0;
	va->plus = 0;
	va->nb = (va->znb > 0 && va->less) ? va->znb : va->nb;
	va->znb = (va->znb > 0 && va->less) ? 0 : va->znb;
	va->z = 0;
	va->h = 0;
	va->pcs = 0;
	va->pcsnb = (va->pcsnb && va->nb > 0 && !va->less) ? va->pcsnb - va->nb : 0;
}

void		ft_c(va_list ap, t_count *va)
{
	int		i;
	int		u;
	char	*tmp;

	if (!va->ml)
	{
		i = va_arg(ap, int);
		tmp = (char*)malloc(sizeof(char));
		if (tmp)
		{
			u = 1;
			*tmp = i;
			ft_deflags(va, u);
			ft_fill_conv(va, u, tmp);
			free(tmp);
		}
	}
	else
		ft_cm(ap, va);
}
