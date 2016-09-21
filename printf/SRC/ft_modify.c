/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:40:04 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 13:40:06 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

long long int				ft_modify(va_list ap, t_count *va)
{
	long long int	i;

	if (va->ml_h == 1)
		i = (short)va_arg(ap, int);
	else if (va->ml_h == 2)
		i = (char)va_arg(ap, int);
	else if (va->ml_l == 1)
		i = va_arg(ap, long int);
	else if (va->ml_l == 2)
		i = va_arg(ap, long long int);
	else if (va->ml_z)
		i = va_arg(ap, size_t);
	else if (va->ml_j)
		i = va_arg(ap, uintmax_t);
	return (i);
}
