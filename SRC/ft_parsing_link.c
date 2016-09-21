/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:54 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:55 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void				ft_search(t_names_coords *lst, char *str, int **ptr_lvl)
{
	while (lst)
	{
		if (ft_strequ(str, lst->name))
		{
			*ptr_lvl = &lst->lvl;
			return ;
		}
		lst = lst->next;
	}
}

static void				ft_stock_link(char *str, t_link **link,
							t_names_coords *connect, int *error)
{
	t_link				*tmp;

	tmp = *link;
	while (tmp)
	{
		if (ft_strequ(str, tmp->name) && ++(*error))
			return ;
		tmp = tmp->next;
	}
	if ((tmp = (t_link*)malloc(sizeof(t_link))))
	{
		ft_bzero(tmp, sizeof(t_link));
		tmp->name = str;
		ft_search(connect, str, &tmp->ptr_lvl);
		ft_push_list_end_link(link, tmp);
	}
}

static int				ft_check_if_room_exist(char **split,
								t_names_coords *lst)
{
	t_names_coords		*tmp;
	int					i;
	int					error;

	error = 0;
	i = 0;
	tmp = lst;
	while (lst && i < 2)
	{
		if (ft_strequ(split[i], lst->name))
		{
			lst->nb_link++;
			(!i) ? ft_stock_link(split[1], &lst->link, tmp, &error) :
				ft_stock_link(split[0], &lst->link, tmp, &error);
			lst = tmp;
			i++;
		}
		else
			lst = lst->next;
	}
	(error) ? ft_free(split, NULL) : 0;
	return (i);
}

void					ft_parsing_link(char *str, t_content *lst)
{
	char				**split;

	if (ft_count_char(str, '-') != 1 && ft_printf("ERROR\n"))
		exit(0);
	split = ft_strsplit(str, '-');
	if (!split || (ft_strequ(split[0], split[1]) && ft_printf("ERROR\n")))
		exit(0);
	if (ft_check_if_room_exist(split, lst->rooms_names_coords) != 2
		&& ft_printf("ERROR\n"))
		exit(0);
	free(split);
}
