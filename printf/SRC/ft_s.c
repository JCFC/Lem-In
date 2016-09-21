/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:50:07 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:50:08 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void		ft_deflags(t_count *va)
{
	va->h = 0;
	va->s = 0;
	va->plus = 0;
	va->pcsnb = 0;
	va->pcs = 0;
	va->z = 0;
	va->znb = (va->z2 && va->nb > 0) ? va->nb : va->znb;
	va->nb = (va->z2 && va->nb > 0) ? 0 : va->nb;
	va->pcsnb = 0;
}

void			ft_s(va_list ap, t_count *va)
{
	int			x;
	int			u;
	char		*tmp;

	x = 0;
	if (!va->ml)
	{
		tmp = va_arg(ap, char *);
		if (!tmp && (x = 1))
			tmp = ft_strdup("(null)");
		if (tmp)
		{
			u = ft_strlen(tmp);
			u = (u > va->pcsnb && va->pcs) ? va->pcsnb : u;
			ft_deflags(va);
			ft_fill_conv(va, u, tmp);
			(x) ? free(tmp) : tmp;
		}
	}
	else
		ft_sm(ap, va);
}
