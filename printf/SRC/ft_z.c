/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:00:22 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 15:41:09 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

void		ft_z(va_list ap, t_count *va)
{
	if (va->ml_z < 1)
		va->ml_z++;
	va->ml = 1;
}