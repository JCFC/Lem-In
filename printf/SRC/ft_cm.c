/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:32:16 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 12:33:32 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void			ft_deflags(t_count *va)
{
	va->h = 0;
	va->s = 0;
	va->plus = 0;
	va->pcsnb = 0;
}

void				ft_cm(va_list ap, t_count *va)
{
	int				i;
	unsigned int	wchar;
	char			*tmp;
	char			*str;

	wchar = va_arg(ap, unsigned int);
	str = ft_ullitoa_base(wchar, 2, 'a', &i);
	if (str)
		free(str);
	tmp = (i <= 7) ? ft_strnew(1) : tmp;
	tmp = (i > 7 && i <= 11) ? ft_strnew(2) : tmp;
	tmp = (i > 11 && i <= 16) ? ft_strnew(3) : tmp;
	tmp = (i > 16) ? ft_strnew(4) : tmp;
	if (tmp)
	{
		i = ft_write_u(va, i, wchar, tmp);
		ft_deflags(va);
		ft_fill_conv(va, i, tmp);
		free(tmp);
	}
}
