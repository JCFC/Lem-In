/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:47:00 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:47:01 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void				ft_print_way(t_path *lst)
{
	t_path			*path_tmp;
	t_names_coords	*rooms_tmp;
	int				i;

	i = 1;
	path_tmp = lst;
	while (path_tmp)
	{
		ft_printf("Way : %d | Number of nodes : %d\n", i, path_tmp->n_n);
		rooms_tmp = path_tmp->lst_path;
		while (rooms_tmp)
		{
			ft_printf("%s ", rooms_tmp->name);
			rooms_tmp = rooms_tmp->next;
		}
		ft_putendl("\n");
		path_tmp = path_tmp->next;
		i++;
	}
}

void				ft_print_final_way(t_path *lst)
{
	t_path			*path_tmp;
	t_names_coords	*rooms_tmp;
	int				i;

	i = 1;
	path_tmp = lst;
	ft_putendl("");
	while (path_tmp)
	{
		ft_printf("Way : %d | Number of node : %d\n", i, path_tmp->n_n);
		rooms_tmp = path_tmp->lst_path;
		while (rooms_tmp)
		{
			ft_printf("%s ", rooms_tmp->name);
			rooms_tmp = rooms_tmp->next;
		}
		ft_putendl("\n");
		path_tmp = path_tmp->f_next;
		i++;
	}
}
