/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:47:03 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 15:38:57 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void			init_struct2(t_count *v)
{
	v->nprintz = 0;
	v->ps = 0;
	v->lst = NULL;
	v->nbstr = 0;
}

static void			init_struct(t_count *v)
{
	v->pcs = 0;
	v->plus = 0;
	v->z = 0;
	v->z2 = 0;
	v->s = 0;
	v->less = 0;
	v->h = 0;
	v->hl = 'x';
	v->neg = 0;
	v->convz = 0;
	v->cpynb = 0;
	v->xh = 0;
	v->ml = 0;
	v->ml_j = 0;
	v->ml_h = 0;
	v->ml_l = 0;
	v->ml_z = 0;
	v->al = 0;
	v->i = 0;
	v->nb = 0;
	v->znb = 0;
	v->pcsnb = 0;
	v->pnb = 0;
	init_struct2(v);
}

static void			ft_print(t_lst *lst)
{
	while (lst)
	{
		write(1, lst->str, lst->s_str);
		lst = lst->next;
	}
}

static void			ft_parsing(t_count *va, va_list ap)
{
	int				y;

	y = 0;
	va->tmpfmt = NULL;
	while ((va->tmpfmt = ft_strchr_p(va->format, '%', &va->lst, va)) != NULL)
	{
		va->tmpfmt++;
		y = ft_check_va(va->tmpfmt, va, ap);
		va->format = &va->tmpfmt[y];
	}
	ft_print(va->lst);
	ft_free_lst(&va->lst);
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_count			v;

	v.format = (char*)format;
	va_start(ap, format);
	init_struct(&v);
	ft_parsing(&v, ap);
	va_end(ap);
	return (v.nbstr);
}
