/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:45 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:45 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

#define IF_NO_ANTS_EXIT (!lst.nb_ants) ? ft_putendl("ERROR"), exit (0) : 0;

void				ft_after_parsing(t_content *lst)
{
	ft_path_finding(lst);
	lst->q_r = ft_sort(lst->q_r, lst->ways);
	ft_cleaning_way(lst->q_r, lst);
	(lst->pw) ? ft_print_final_way(lst->q_r) : 0;
	(!lst->ways && ft_printf("ERROR : Can't reach room : %s :|\n", lst->e)) ?
	exit(0) : 0;
	lst->ways = (lst->m) ? lst->ways : 1;
	ft_create_ants(&lst->ants, lst->nb_ants);
	ft_trip(lst->f_q_r, lst);
	ft_free_path(lst->q_r);
	(lst->ants) ? free(lst->ants) : 0;
	(lst->r) ? ft_loop(lst) : 0;
}

int					main(void)
{
	t_content	lst;
	char		*str;

	ft_bzero(&lst, sizeof(t_content));
	lst.parse_room = 1;
	ft_gnl(&str, 1);
	(!str && ft_printf("ERROR\n")) ? exit(0) : 0;
	lst.nb_ants = ft_atoi2(str);
	IF_NO_ANTS_EXIT;
	ft_strdel(&str);
	ft_start_parsing_rooms(&lst, NULL);
	if ((!lst.e || !lst.s) && ft_printf("ERROR\n"))
		exit(0);
	ft_connect_list(lst.rooms_names_coords);
	ft_putendl("\n");
	ft_after_parsing(&lst);
	ft_free(NULL, lst.rooms_names_coords);
	return (0);
}
