/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_wo_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:42:21 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 15:44:25 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void			ft_create_wo_l2(t_count *va, char *tmp, int *count)
{
	(va->s) ? tmp[(*count)++] = 32 : tmp[*count];
	while (va->nb > 0)
	{
		tmp[(*count)++] = 32;
		va->nb--;
	}
	(va->plus && va->znb > 0) ? tmp[(*count)++] = '+' : tmp[*count];
	va->plus = (va->plus && va->znb > 0) ? 0 : va->plus;
	(va->neg) ? tmp[(*count)++] = '-' : tmp[*count];
	va->neg = (va->neg) ? 0 : va->neg;
	(va->h) ? tmp[(*count)++] = '0' : tmp[*count];
	(va->h) ? tmp[(*count)++] = va->hl : tmp[*count];
	while (va->znb > 0)
	{
		tmp[(*count)++] = '0';
		va->znb--;
	}
}

void				ft_create_wo_l(t_count *va, int u, char *str, int i)
{
	char			*tmp;
	int				count;

	va->znb = (va->s) ? va->znb - 1 : va->znb;
	va->s = (va->nb > 0) ? 0 : va->s;
	count = 0;
	tmp = ft_strnew(i);
	if (tmp)
	{
		ft_create_wo_l2(va, tmp, &count);
		(va->neg) ? tmp[count++] = '-' : tmp[count];
		(va->plus) ? tmp[count++] = '+' : tmp[count];
		while (va->pcsnb > 0)
		{
			tmp[count++] = '0';
			va->pcsnb--;
		}
		(va->cpynb < 0) ? ft_strncat(tmp, &str[1], u - 1) : \
			ft_strncat(tmp, str, u);
		ft_fill_lst(&va->lst, tmp, i, va);
		free(tmp);
	}
}
