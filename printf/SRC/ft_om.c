/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_om.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:42:39 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:43:16 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void					ft_deflags(t_count *va, unsigned long long int i,\
		int *size)
{
	*size = (i == 0 && va->pcsnb == 0
			&& va->pcs && !va->h) ? *size - 1 : *size;
	va->h = 0;
	va->plus = 0;
	va->s = 0;
}

void						ft_om(va_list ap, t_count *va)
{
	char					*tmp;
	char					*tmp3;
	unsigned long long int	i;
	int						size;

	i = va_arg(ap, unsigned long int);
	tmp = ft_ullitoa_base(i, 8, 'a', &size);
	if (tmp)
	{
		tmp3 = tmp;
		tmp = (va->h && i != 0) ? ft_strjoin("0", tmp) : tmp;
		(va->h && i != 0) ? free(tmp3) : tmp;
		(va->h && i != 0) ? size++ : size;
		if (tmp)
		{
			ft_deflags(va, i, &size);
			ft_fill_conv(va, size, tmp);
			free(tmp);
		}
	}
}
