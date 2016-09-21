/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:43:20 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:43:46 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void			ft_deflags(t_count *va, long long int y, int *size)
{
	va->plus = 0;
	va->s = 0;
	va->h = 1;
	va->xh = 2;
}

void				ft_p(va_list ap, t_count *va)
{
	char			*tmp;
	long long int	i;
	int				size;

	i = va_arg(ap, long long int);
	tmp = ft_llitoa_base(i, 16, &size);
	if (tmp)
	{
		ft_deflags(va, i, &size);
		size = (i == 0 && va->pcsnb == 0 && va->pcs) ? size - 1 : size;
		ft_fill_conv(va, size, tmp);
		free(tmp);
	}
}
