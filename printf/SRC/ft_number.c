/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:40:58 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:41:28 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

void		ft_number(va_list ap, t_count *va, int c)
{
	if ((!va->less && c == '0' && va->nb == 0 && !va->pcs) || va->z == 1)
	{
		va->znb = (va->znb == 0) ? c - 48 : va->znb * 10 + c - 48;
		va->z = 1;
	}
	else if (va->pcs)
	{
		if (va->znb && !va->z)
		{
			va->nb = va->znb;
			va->znb = 0;
		}
		va->pcsnb = (va->pcsnb == 0) ? c - 48 : va->pcsnb * 10 + c - 48;
	}
	else
		va->nb = (va->nb == 0) ? c - 48 : va->nb * 10 + c - 48;
}
