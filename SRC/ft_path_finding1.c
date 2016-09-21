/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finding1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:57 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:58 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

#define INIT_VARS_T_LINK t_link *tmp = NULL, *start = NULL;

static void				ft_stock_way(t_content *info,
							t_names_coords *lst)
{
	t_path				*new;
	t_names_coords		*new_rooms;
	t_names_coords		*start_rooms;
	int					i;

	i = 0;
	start_rooms = NULL;
	if (!(new = (t_path*)malloc(sizeof(t_path))))
		exit(0);
	ft_bzero(new, sizeof(t_path));
	while (lst)
	{
		if (!(new_rooms = (t_names_coords*)malloc(sizeof(t_names_coords))))
			exit(0);
		ft_bzero(new_rooms, sizeof(t_names_coords));
		new_rooms->name = lst->name;
		ft_push_list_top(&start_rooms, new_rooms);
		lst = lst->parent;
		i++;
	}
	new->n_n = i;
	new->lst_path = start_rooms;
	ft_push_list_end_path(&info->q_r, new);
}

static void				ft_build_tree(t_link *link,
								t_content *info, int lvl)
{
	INIT_VARS_T_LINK;
	while (link)
	{
		*link->ptr_lvl = lvl;
		tmp = link->origin->link;
		while (tmp)
		{
			if (ft_strequ(tmp->name, info->e))
			{
				tmp->origin->parent = link->origin;
				ft_stock_way(info, tmp->origin);
				return ;
			}
			else if (!*tmp->ptr_lvl)
			{
				ft_push_list_end_link2(&start, tmp);
				*tmp->ptr_lvl = lvl + 1;
				tmp->origin->parent = link->origin;
			}
			tmp = tmp->next;
		}
		link = link->lst_lvl;
	}
	(start != NULL) ? ft_build_tree(start, info, lvl + 1) : 0;
}

static void				ft_reset(t_names_coords *lst)
{
	t_link				*tmp;

	while (lst)
	{
		lst->lvl = 0;
		lst->parent = NULL;
		tmp = lst->link;
		while (tmp)
		{
			tmp->lst_lvl = NULL;
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void					ft_path_finding(t_content *lst)
{
	t_link				*tmp;
	t_link				*start;

	start = NULL;
	if (!lst->start || !lst->start->nb_link || !lst->end->nb_link)
	{
		ft_printf("ERROR : %s || %s has no link :|\n", lst->s, lst->e);
		exit(0);
	}
	tmp = lst->start->link;
	lst->start->lvl = -1;
	tmp->origin->parent = lst->start;
	while (tmp)
	{
		if (ft_strequ(tmp->name, lst->e))
			ft_stock_way(lst, lst->end);
		else
			ft_build_tree(tmp, lst, 1);
		ft_reset(lst->rooms_names_coords);
		tmp = tmp->next;
		lst->start->lvl = -1;
		if (tmp)
			tmp->origin->parent = lst->start;
	}
}
