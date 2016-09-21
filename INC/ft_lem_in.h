/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:51:00 by jchen             #+#    #+#             */
/*   Updated: 2016/04/29 17:51:02 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include <stdio.h>
# include "../printf/INC/ft_printf.h"
# include <limits.h>

typedef struct				s_names_coords
{
	char					*name;
	int						lvl;
	int						x;
	int						y;
	int						nb_link;
	struct s_names_coords	*next;
	struct s_link			*link;
	struct s_names_coords	*parent;
	struct s_names_coords	*tmp;
}							t_names_coords;

typedef struct				s_link
{
	int						*ptr_lvl;
	char					*name;
	t_names_coords			*origin;
	struct s_link			*next;
	struct s_link			*lst_lvl;
}							t_link;

/*
** n_n = number of node;
*/

typedef struct				s_ants
{
	int						i;
	int						color;
	int						way;
	t_names_coords			*pos;
}							t_ants;

typedef struct				s_path

{	t_names_coords			*lst_path;
	int						n_n;
	struct s_path			*next;
	struct s_path			*f_next;
}							t_path;

/*
** q_r = quickest route;
** f_q_r = finak quickest route;
** s = name roooms start;
** e = name rooms end;
** t = turns;
** pw = print_ways; *
** c = color; *
** m = multichemin; *
** w = ways;
*/

typedef struct				s_content
{
	int						nb_ants;
	int						count;
	int						parse_room;
	int						ways;
	int						reset;
	char					*s;
	char					*e;
	int						pw;
	int						t;
	int						c;
	int						m;
	int						r;
	int						w;
	t_ants					*ants;
	t_path					*q_r;
	t_path					*f_q_r;
	t_names_coords			*start;
	t_names_coords			*end;
	t_names_coords			*rooms_names_coords;
}							t_content;

int							ft_atoi2(char *str);
int							ft_atoi3(char *str);
int							ft_nbword(char *s, char c);
void						ft_free(char **str, t_names_coords *lst);
void						ft_free_path(t_path *path);
int							ft_check_double(t_names_coords *new,
									t_names_coords *lst);
t_path						*ft_sort(t_path *lst, int size_lst);

void						ft_start_parsing_rooms(t_content *lst, char *str);
void						ft_parsing_link(char *str, t_content *lst);
void						ft_after_parsing(t_content *lst);
void						ft_path_finding(t_content *lst);
void						ft_connect_list(t_names_coords *lst);
void						ft_print_way(t_path *lst);
void						ft_print_final_way(t_path *lst);
void						ft_cleaning_way(t_path *lst, t_content *info);
void						ft_create_ants(t_ants **lst, int nb_ants);
void						ft_trip(t_path *lst, t_content *info);
void						ft_loop(t_content *lst);

void						ft_push_list_end(t_names_coords **lst,
									t_names_coords *new);
void						ft_push_list_end_link(t_link **lst,
									t_link *new);
void						ft_push_list_end_link2(t_link **lst,
									t_link *new);
void						ft_push_list_top(t_names_coords **lst,
									t_names_coords *new);
void						ft_push_list_end_path(t_path **lst,
									t_path *new);

#endif
