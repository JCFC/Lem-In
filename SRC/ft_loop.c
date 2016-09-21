/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 13:47:47 by jchen             #+#    #+#             */
/*   Updated: 2016/04/30 13:48:18 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void			ft_reset_param(t_content *lst)
{
	lst->ants = NULL;
	lst->q_r = NULL;
	lst->f_q_r = NULL;
	lst->s = lst->e;
	lst->start = lst->end;
	lst->e = NULL;
	lst->end = NULL;
	lst->start->parent = NULL;
	lst->start->tmp = NULL;
	lst->rooms_names_coords->parent = NULL;
	lst->rooms_names_coords->tmp = NULL;
	lst->count = 0;
	lst->ways = 0;
}

static int			ft_lstcmp(char *str, t_names_coords *lst, t_content *info)
{
	t_names_coords	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (ft_strequ(str, tmp->name) && !ft_strequ(str, info->s))
		{
			info->end = tmp;
			info->e = tmp->name;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void				ft_loop(t_content *lst)
{
	char			*str;

	str = NULL;
	ft_reset_param(lst);
	ft_putendl("");
	while (ft_gnl2(&str))
	{
		if (str && ft_lstcmp(str, lst->rooms_names_coords, lst))
		{
			lst->reset = 1;
			ft_after_parsing(lst);
			ft_strdel(&str);
			return ;
		}
		else if (str && ft_strequ(str, "exit"))
		{
			ft_strdel(&str);
			return ;
		}
		ft_strdel(&str);
	}
}
