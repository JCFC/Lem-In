/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:16 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:17 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			ft_check_double(t_names_coords *new, t_names_coords *lst)
{
	while (lst)
	{
		if ((!ft_strcmp(new->name, lst->name) ||
			(new->x == lst->x && lst->y == new->y)) && ft_printf("ERROR\n"))
			exit(0);
		lst = lst->next;
	}
	return (1);
}
