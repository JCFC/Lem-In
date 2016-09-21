/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:45:00 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 12:46:28 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ft_printf.h"

static void			ft_lst_p(t_lst **lst, t_lst *new)
{
	static	t_lst	*tmp;

	if (*lst == NULL)
	{
		tmp = new;
		*lst = new;
		return ;
	}
	tmp->next = new;
	tmp = new;
}

static void			ft_fill(t_lst **lst, char *str, int size)
{
	t_lst			*tmp;

	tmp = NULL;
	tmp = (t_lst*)malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->str = str;
		tmp->ct = 0;
		tmp->s_str = size;
		tmp->next = NULL;
		ft_lst_p(lst, tmp);
	}
}

void				ft_fill_lst(t_lst **lst, const char *str, int size,\
		t_count *va)
{
	char			*tmp;
	int				i;

	i = 0;
	tmp = NULL;
	if (!size)
		return ;
	tmp = ft_strnew(size);
	if (tmp)
	{
		while (i < size)
		{
			tmp[i] = str[i];
			i++;
		}
		ft_fill(lst, tmp, size);
		va->nbstr += size;
	}
}
