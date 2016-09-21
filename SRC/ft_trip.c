/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:47:16 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:47:17 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int		ft_opti_route(t_content *info, int ways, int node, int i)
{
	t_path		*tmp;

	tmp = info->f_q_r;
	while (ways > 0)
	{
		if (node > tmp->n_n + (info->nb_ants - i))
		{
			info->ways--;
			return (0);
		}
		tmp = tmp->f_next;
		ways--;
	}
	return (1);
}

static void		ft_print_color(t_ants ant, t_content *info, char *str, int i)
{
	info->w ? ft_printf("[%d]", i) : 0;
	info->c ? ft_printf("\x1B[3%dmL%d-%s\x1B[0m ", ant.color, ant.i, str) :
	ft_printf("L%d-%s ", ant.i, str);
}

static void		ft_reset(int *i, int *y, t_content *info)
{
	*i = 0;
	*y = 0;
	info->reset = 0;
}

static void		ft_out(int nb_max, t_path *lst, t_content *info)
{
	static int	i;
	static int	y;
	int			count;

	if (info->reset)
		ft_reset(&i, &y, info);
	count = 0;
	while (nb_max > 0 && i < info->nb_ants)
	{
		if (count && !ft_opti_route(info, count, lst->n_n, i))
			break ;
		info->ants[i].way = count + 1;
		ft_print_color(info->ants[i], info,
		lst->lst_path->next->name, count + 1);
		info->count = (ft_strequ(lst->lst_path->next->name, info->e)) ?
		info->count + 1 : info->count;
		info->ants[i].pos = lst->lst_path->next;
		i++;
		nb_max--;
		lst = lst->f_next;
		count++;
	}
	(!y++) ? ft_putendl("") : 0;
}

void			ft_trip(t_path *lst, t_content *info)
{
	int			i;
	int			y;

	y = 0;
	while (info->count < info->nb_ants && !(i = 0))
	{
		(info->t) ? ft_printf("[\x1B[32m%d\x1B[0m] ", y + 1) : 0;
		if (y)
			while (i < info->nb_ants)
			{
				if (info->ants[i].pos &&
		(info->ants[i].pos = info->ants[i].pos->next) && info->ants[i].pos)
				{
					ft_print_color(info->ants[i], info,
					info->ants[i].pos->name, info->ants[i].way);
					info->count = (ft_strequ(info->ants[i].pos->name, info->e))
					? info->count + 1 : info->count;
				}
				i++;
			}
		ft_out(info->ways, lst, info);
		(y++) ? ft_putendl("") : 0;
	}
}
