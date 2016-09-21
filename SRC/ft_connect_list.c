/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:27 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:28 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void				ft_search(char *name_rooms, t_names_coords *lst,
							t_link *dst)
{
	while (lst)
	{
		if (ft_strequ(lst->name, name_rooms))
		{
			dst->origin = lst;
			return ;
		}
		lst = lst->next;
	}
}

void					ft_connect_list(t_names_coords *lst)
{
	t_names_coords		*tmp;
	t_link				*tmp2;

	tmp = lst;
	while (lst)
	{
		tmp2 = lst->link;
		while (tmp2)
		{
			ft_search(tmp2->name, tmp, tmp2);
			tmp2 = tmp2->next;
		}
		lst = lst->next;
	}
}
