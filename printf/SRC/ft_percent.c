/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:43:53 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:44:03 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void	ft_deflags(t_count *va, int u)
{
	va->h = 0;
	va->s = 0;
	va->plus = 0;
	va->pcs = 0;
	va->pcsnb = 0;
}

void		ft_percent(va_list ap, t_count *va)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char));
	if (tmp)
	{
		*tmp = '%';
		ft_deflags(va, 1);
		ft_fill_conv(va, 1, tmp);
		free(tmp);
	}
}
