/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:08:40 by jchen             #+#    #+#             */
/*   Updated: 2016/02/01 12:22:53 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int				ft_lgstr(int n, int base)
{
	int					size;

	size = 0;
	while (n)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static	char			*ft_fillstr(char *str, int n, int size, int base)
{
	if (n < 0)
	{
		*str = '-';
		n = n * -1;
		size--;
	}
	else
		size = size - 2;
	while (n >= base)
	{
		if (n % base > 9)
			str[size--] = n % base + 'A' - 10;
		else
			str[size--] = n % base + '0';
		n = n / base;
	}
	str[size] = n + '0';
	return (str);
}

char					*ft_itoa_base(int n, int base)
{
	char				*str;
	int					size;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		if (str == NULL)
			return (NULL);
	}
	else if (n != 0)
	{
		size = ft_lgstr(n, base);
		str = ft_strnew(size + 1);
		if (str == NULL)
			return (NULL);
		ft_fillstr(str, n, size + 1, base);
	}
	else
	{
		str = ft_strnew(1);
		*str = '0';
	}
	return (str);
}
