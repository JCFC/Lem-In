/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:02:31 by jchen             #+#    #+#             */
/*   Updated: 2016/02/18 15:43:43 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdint.h>

# define L_M -9223372036854775807

typedef struct				s_lst
{
	char					*str;
	char					ct;
	int						s_str;
	struct s_lst			*next;
}							t_lst;

typedef struct				s_count
{
	t_lst					*lst;
	int						nbstr;
	int						convz;
	int						pcs;
	int						plus;
	int						z;
	int						z2;
	int						s;
	int						less;
	int						h;
	char					hl;
	int						nprintz;
	int						ps;
	int						flags;
	int						neg;
	int						xh;
	int						ml;
	int						ml_h;
	int						ml_j;
	int						ml_l;
	int						ml_z;
	int						al;
	int						l;
	int						i;
	int						nb;
	int						znb;
	int						pcsnb;
	int						pnb;
	long long int			cpynb;
	int						tmp;
	char					*format;
	char					*tmpfmt;
}							t_count;

typedef struct				s_conv
{
	char					f;
	void					(*p)(va_list ap, t_count *va);
}							t_conv;

void						ft_free_lst(t_lst **lst);
void						ft_print_flags(t_count *va);
void						ft_reset_flags(t_count *va);
void						ft_create_wo_l(t_count *va, int u, char *str,\
		int i);
void						ft_fill_conv(t_count *va, int u, char *str);
void						ft_fill_lst(t_lst **lst, const char *str, int size\
		, t_count *va);
char						*ft_strchr_p(const char *s, int c, t_lst **lst\
		, t_count *va);
void						ft_strncat2(char *dest, size_t d, const char *src\
		, size_t s);
long long int				ft_modify(va_list ap, t_count *va);
unsigned long long int		ft_modify_unsigned(va_list ap, t_count *va);
unsigned long long int		ft_modify_unsigned_dm(va_list ap, t_count *va);

int							ft_write_u(t_count *va, int unit,\
		unsigned int wchar, char *str);

void						ft_hash(va_list ap, t_count *va);
void						ft_plus(va_list ap, t_count *va);
void						ft_less(va_list ap, t_count *va);
void						ft_space(va_list ap, t_count *va);
void						ft_precision(va_list ap, t_count *va);
void						ft_number(va_list ap, t_count *va, int c);
void						ft_percent(va_list ap, t_count *va);
void						ft_s(va_list ap, t_count *va);
void						ft_sm(va_list ap, t_count *va);
void						ft_cm(va_list ap, t_count *va);
void						ft_o(va_list ap, t_count *va);
void						ft_om(va_list ap, t_count *va);
void						ft_d(va_list ap, t_count *va);
void						ft_dm(va_list ap, t_count *va);
void						ft_u(va_list ap, t_count *va);
void						ft_um(va_list ap, t_count *va);
void						ft_c(va_list ap, t_count *va);
void						ft_p(va_list ap, t_count *va);
void						ft_x(va_list ap, t_count *va);
void						ft_xm(va_list ap, t_count *va);
void						ft_h(va_list ap, t_count *va);
void						ft_l(va_list ap, t_count *va);
void						ft_j(va_list ap, t_count *va);
void						ft_z(va_list ap, t_count *va);

char						*ft_ullitoa_base(unsigned long long int n,\
		int base, char l, int *u);
char						*ft_llitoa_base(long long int n, int base, int *u);
int							ft_check_va(char *format, t_count *v, va_list ap);
int							ft_printf(const char *format, ...);

#endif
