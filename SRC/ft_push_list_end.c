/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_list_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:47:04 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:47:04 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void				ft_push_list_top(t_names_coords **lst, t_names_coords *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void				ft_push_list_end(t_names_coords **lst, t_names_coords *new)
{
	t_names_coords	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void				ft_push_list_end_path(t_path **lst, t_path *new)
{
	t_path			*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void				ft_push_list_end_link(t_link **lst, t_link *new)
{
	t_link			*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void				ft_push_list_end_link2(t_link **lst, t_link *new)
{
	t_link			*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->lst_lvl)
			tmp = tmp->lst_lvl;
		tmp->lst_lvl = new;
	}
}
