/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:58:34 by jchen             #+#    #+#             */
/*   Updated: 2016/03/07 15:28:40 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void			ft_splitlst(t_path *lst, t_path **a, t_path **b, int i)
{
	*a = lst;
	while (i-- > 1)
		lst = lst->next;
	*b = lst->next;
	lst->next = NULL;
}

static t_path		*ft_merge(t_path *a, t_path *b)
{
	t_path			*tmp;
	int				i;

	i = 0;
	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	i = (a->n_n < b->n_n) ? 1 : 0;
	tmp = (i) ? a : b;
	tmp->next = (i) ? ft_merge(a->next, b) : ft_merge(a, b->next);
	return (tmp);
}

static void			ft_split(t_path **lst, int size)
{
	t_path			*lsta;
	t_path			*lstb;

	if (!(*lst) || !(*lst)->next)
		return ;
	size = size / 2;
	ft_splitlst(*lst, &lsta, &lstb, size);
	ft_split(&lsta, size);
	ft_split(&lstb, size);
	*lst = ft_merge(lsta, lstb);
}

t_path				*ft_sort(t_path *lst, int size_lst)
{
	if (!lst)
		return (lst);
	ft_split(&lst, size_lst);
	return (lst);
}
