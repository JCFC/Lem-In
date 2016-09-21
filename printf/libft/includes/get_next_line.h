/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:17:11 by jchen             #+#    #+#             */
/*   Updated: 2016/01/21 22:06:56 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 100000

typedef struct			s_static
{
	int		i;
	char	buf[BUFF_SIZE + 1];
}						t_static;

int						get_next_line(const int fd, char **line);

#endif
