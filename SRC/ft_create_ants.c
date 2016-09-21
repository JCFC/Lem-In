/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:46:34 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:46:35 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void			ft_create_ants(t_ants **lst, int nb_ants)
{
	t_ants		*new;
	int			i;
	int			color;

	color = 1;
	i = 0;
	if (!(new = (t_ants*)malloc(sizeof(t_ants) * nb_ants)))
		exit(0);
	while (i < nb_ants)
	{
		new[i].color = color;
		new[i].i = i + 1;
		new[i].pos = NULL;
		i++;
		color++;
		color = (color == 7) ? 1 : color;
	}
	*lst = new;
}
