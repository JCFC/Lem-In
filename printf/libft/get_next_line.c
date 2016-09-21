/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:18:37 by jchen             #+#    #+#             */
/*   Updated: 2016/03/18 18:09:45 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_concat(t_list *lst)
{
	unsigned long		i;
	char				*tmpstr;
	t_list				*tmp;

	i = 0;
	tmp = lst;
	tmpstr = NULL;
	while (tmp)
	{
		i = i + tmp->content_size;
		tmp = tmp->next;
	}
	tmpstr = ft_strnew(i);
	if (tmpstr)
		while (lst)
		{
			tmp = lst;
			tmpstr = ft_strcat(tmpstr, lst->content);
			lst = lst->next;
			free(tmp->content);
			free(tmp);
		}
	return (tmpstr);
}

static int		ft_read(int const fd, char *buf, t_list **lst, char **line)
{
	char			*tmpstr;
	int				ret;

	ret = 1;
	while (ret > 0)
	{
		ret = (int)read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		buf[ret] = 0;
		if (ret == 0 && *lst == NULL)
			return (0);
		else if ((tmpstr = ft_strchr(buf, '\n')))
		{
			ft_lstpush(lst, ft_lstnew(buf, (size_t)tmpstr - (size_t)buf));
			ret = 0;
		}
		else
			ft_lstpush(lst, ft_lstnew(buf, (size_t)ret));
	}
	*line = ft_concat(*lst);
	return (1);
}

static int		ft_after_read(char *buf, t_list **lst, char **line)
{
	size_t		i;
	size_t		y;

	i = 0;
	while (i != BUFF_SIZE)
	{
		if (buf[i] == '\n')
		{
			buf[i++] = 0;
			y = i;
			while (i != BUFF_SIZE && buf[i] != '\n' && buf[i] != '\0')
				i++;
			if (buf[i] == '\n')
			{
				*line = ft_mallocncopy(&buf[y], i - y);
				return (1);
			}
			else if (i - y == 0)
				return (0);
			ft_lstpush(lst, ft_lstnew(&buf[y], i - y));
			return (0);
		}
		buf[i++] = 0;
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_static		statik;
	t_list				*lst;

	*line = NULL;
	lst = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	if (statik.i != fd)
	{
		statik.i = fd;
		ft_memset(statik.buf, 0, BUFF_SIZE);
	}
	else if (ft_after_read(statik.buf, &lst, line))
		return (1);
	return (ft_read(fd, statik.buf, &lst, line));
}
