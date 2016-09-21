/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaning_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:21 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:22 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void			ft_push_list_end_path_f(t_path **lst, t_path *new)
{
	t_path			*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->f_next)
			tmp = tmp->f_next;
		tmp->f_next = new;
	}
}

static void			ft_push_list_end3(t_names_coords **lst, t_names_coords *new)
{
	t_names_coords	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->tmp)
			tmp = tmp->tmp;
		tmp->tmp = new;
	}
}

static void			ft_add_lst(t_names_coords **dst, t_names_coords *src)
{
	while (src)
	{
		ft_push_list_end3(dst, src);
		src = src->next;
	}
}

static int			ft_strcmp_lst(t_names_coords *lst, char *str)
{
	if (!lst)
		return (1);
	while (lst)
	{
		if (ft_strequ(lst->name, str))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void				ft_cleaning_way(t_path *lst, t_content *info)
{
	t_names_coords	*tmp;
	t_names_coords	*lst_name;
	int				i;

	i = 1;
	lst_name = NULL;
	while (lst)
	{
		tmp = lst->lst_path;
		while (tmp)
		{
			if (ft_strequ(info->s, tmp->name) || ft_strequ(info->e, tmp->name))
				;
			else if (!ft_strcmp_lst(lst_name, tmp->name) && !(i = 0))
				break ;
			tmp = tmp->next;
		}
		(i) ? ft_add_lst(&lst_name, lst->lst_path) : 0;
		(i) ? ft_push_list_end_path_f(&info->f_q_r, lst) : 0;
		info->ways = (i) ? info->ways + 1 : info->ways;
		lst = lst->next;
		i = 1;
	}
}
