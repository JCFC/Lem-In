/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:23:07 by jchen             #+#    #+#             */
/*   Updated: 2015/12/21 11:54:00 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lststrsplit(char *str, char c)
{
	t_list	*lst;
	char	*tmp;
	char	*tmp2;
	int		i;

	lst = NULL;
	while (*str)
	{
		tmp = str;
		i = ft_cut_str(&str, c);
		tmp2 = ft_mallocncopy(tmp, i);
		ft_lstpush(&lst, ft_lstnew(tmp2, i));
		free(tmp2);
		ft_strpush(&str, c);
	}
	return (lst);
}
