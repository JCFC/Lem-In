/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:39 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:40 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void					ft_free(char **str, t_names_coords *lst)
{
	int					i;
	t_names_coords		*tmp;
	t_link				*tmp_lst;

	i = 0;
	if (str)
		while (str[i])
			free(str[i++]);
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->name);
		while (tmp->link)
		{
			tmp_lst = tmp->link;
			tmp->link = tmp->link->next;
			free(tmp_lst->name);
			free(tmp_lst);
		}
		free(tmp);
	}
}

void					ft_free_path(t_path *path)
{
	t_path				*tmp_path;
	t_names_coords		*tmp_rooms;

	while (path)
	{
		tmp_path = path;
		while (path->lst_path)
		{
			tmp_rooms = path->lst_path;
			path->lst_path = path->lst_path->next;
			free(tmp_rooms);
		}
		path = path->next;
		free(tmp_path);
	}
}
