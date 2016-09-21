/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_parsing_rooms.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:47:10 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:47:11 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

#define I_N_C (ft_strchr(split[0], '-')) ? ft_putendl("ERROR"), exit (0) : 0 ;

static void				ft_stock_room(char *str, t_content *lst, int i)
{
	char				**split;
	t_names_coords		*new;

	split = ft_strsplit(str, ' ');
	if (split && (new = (t_names_coords*)malloc(sizeof(t_names_coords))))
	{
		ft_bzero(new, sizeof(t_names_coords));
		I_N_C;
		lst->s = (i == 1) ? split[0] : lst->s;
		lst->start = (i == 1) ? new : lst->start;
		lst->e = (i == 2) ? split[0] : lst->e;
		lst->end = (i == 2) ? new : lst->end;
		new->name = split[0];
		new->x = ft_atoi3(split[1]);
		new->y = ft_atoi3(split[2]);
		ft_free(&split[1], NULL);
		free(split);
		ft_check_double(new, lst->rooms_names_coords);
		ft_push_list_end(&lst->rooms_names_coords, new);
	}
}

static void				ft_check_room(char *str, t_content *lst, int y)
{
	int					i;

	i = ft_nbword(str, ' ');
	if (i == 1)
		lst->parse_room = 0;
	else if (i == 3)
		ft_stock_room(str, lst, y);
	else if (ft_printf("ERROR\n"))
		exit(0);
}

static void				ft_start_end(t_content *lst, int i)
{
	char	*str;

	while (ft_gnl(&str, 1))
	{
		if ((ft_strequ(str, "##start") || ft_strequ(str, "##end")) &&
												ft_printf("ERROR\n"))
			exit(0);
		else if (str[0] != '#')
		{
			ft_check_room(str, lst, i);
			ft_strdel(&str);
			return ;
		}
		ft_strdel(&str);
	}
}

static void				ft_isnt_room(char *str, t_content *lst)
{
	(ft_strequ(str, "##start")) ? ft_start_end(lst, 1) : 0;
	(ft_strequ(str, "##end")) ? ft_start_end(lst, 2) : 0;
	lst->pw = (ft_strequ(str, "#pw")) ? 1 : lst->pw;
	lst->c = (ft_strequ(str, "#c")) ? 1 : lst->c;
	lst->w = (ft_strequ(str, "#w")) ? 1 : lst->w;
	lst->m = (ft_strequ(str, "#m")) ? 1 : lst->m;
	lst->t = (ft_strequ(str, "#t")) ? 1 : lst->t;
	lst->r = (ft_strequ(str, "#r")) ? 1 : lst->r;
}

void					ft_start_parsing_rooms(t_content *lst, char *str)
{
	while (ft_gnl(&str, 1))
	{
		if (lst->parse_room)
			(str[0] == '#' || str[0] == 'L') ?
				ft_isnt_room(str, lst) : ft_check_room(str, lst, 0);
		if (!lst->parse_room && ((ft_strequ(str, "##start")) ||
				(ft_strequ(str, "##end"))) && ft_printf("ERROR\n"))
			exit(0);
		else if (!lst->parse_room && (str[0] == '#' || str[0] == 'L'))
			;
		else if (!lst->parse_room && lst->e && lst->s && !ft_strlen(str))
			break ;
		else if (!lst->parse_room && ft_strchr(str, '-')
		&& (!lst->e || !lst->s) && ft_printf("ERROR : START || END\n"))
			exit(0);
		else if (!lst->parse_room && ft_strchr(str, '-') && lst->e && lst->s)
			ft_parsing_link(str, lst);
		else if (!lst->parse_room)
		{
			ft_strdel(&str);
			return ;
		}
		ft_strdel(&str);
	}
}
