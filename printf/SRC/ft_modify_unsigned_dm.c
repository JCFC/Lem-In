/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_unsigned_dm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:40:42 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 14:00:45 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

unsigned long long int				ft_modify_unsigned_dm(va_list ap,\
		t_count *va)
{
	unsigned long long int			i;

	if (va->ml_h == 1)
		i = va_arg(ap, unsigned long int);
	else if (va->ml_h == 2)
		i = va_arg(ap, long int);
	else if (va->ml_l == 1)
		i = va_arg(ap, unsigned long int);
	else if (va->ml_l == 2)
		i = va_arg(ap, unsigned long long int);
	else if (va->ml_z)
		i = va_arg(ap, size_t);
	else if (va->ml_j)
		i = va_arg(ap, uintmax_t);
	return (i);
}
