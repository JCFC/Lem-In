/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:50:14 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 15:40:51 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static int		ft_count(wchar_t *str, t_count *va)
{
	int			count;
	int			y;
	char		*str2;

	y = 0;
	count = 0;
	while (*str)
	{
		str2 = ft_ullitoa_base((unsigned int)*str, 2, 'a', &count);
		if (str2)
			free(str2);
		if (count <= 7)
			y = (y + 1 > va->pcsnb && va->pcsnb > 0) ? y : y + 1;
		else if (count <= 11)
			y = (y + 2 > va->pcsnb && va->pcsnb > 0) ? y : y + 2;
		else if (count <= 16)
			y = (y + 3 > va->pcsnb && va->pcsnb > 0) ? y : y + 3;
		else
			y = (y + 4 > va->pcsnb && va->pcsnb > 0) ? y : y + 4;
		str++;
	}
	return (y);
}

static void		ft_deflags(t_count *va)
{
	va->h = 0;
	va->plus = 0;
	va->s = 0;
}

static int		ft_fill_str(t_count *va, char *str, wchar_t *wchars, int x)
{
	int			count;
	int			t;
	int			tmp;
	int			rtn;
	char		*str2;

	t = 0;
	rtn = 0;
	tmp = 0;
	while (*wchars && x > 0)
	{
		str2 = ft_ullitoa_base((unsigned int)*wchars, 2, 'a', &count);
		if (str2)
			free(str2);
		t = ft_write_u(va, count, (unsigned int)*wchars, &str[tmp]);
		tmp += t;
		x--;
		wchars++;
	}
	return (tmp);
}

static void		ft_sm2(va_list ap, t_count *va, char **str)
{
	*str = ft_strdup("(null)");
	if (*str)
	{
		ft_fill_conv(va, 6, *str);
		free(*str);
	}
}

void			ft_sm(va_list ap, t_count *va)
{
	wchar_t		*wchars;
	int			count;
	int			t;
	char		*str;

	wchars = va_arg(ap, wchar_t *);
	ft_deflags(va);
	if (wchars == NULL)
		ft_sm2(ap, va, &str);
	else
	{
		t = (va->pcs && va->pcsnb == 0) ? 0 : ft_count(wchars, va);
		str = ft_strnew(t);
		if (str)
		{
			ft_fill_str(va, str, wchars, t);
			va->pcsnb = 0;
			ft_fill_conv(va, t, str);
			free(str);
		}
	}
}
