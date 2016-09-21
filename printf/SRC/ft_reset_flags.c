/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:49:23 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 15:40:36 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void		ft_reset_flags2(t_count *va)
{
	va->ml_l = 0;
	va->ml_j = 0;
	va->ml_h = 0;
	va->ml_j = 0;
	va->cpynb = 0;
}

void			ft_reset_flags(t_count *va)
{
	va->convz = 0;
	va->pcs = 0;
	va->plus = 0;
	va->z = 0;
	va->s = 0;
	va->xh = 0;
	va->less = 0;
	va->h = 0;
	va->nprintz = 0;
	va->ps = 0;
	va->flags = 0;
	va->neg = 0;
	va->al = 0;
	va->l = 0;
	va->i = 0;
	va->nb = 0;
	va->znb = 0;
	va->pcsnb = 0;
	va->pnb = 0;
	va->tmp = 0;
	va->z2 = 0;
	ft_reset_flags2(va);
}
