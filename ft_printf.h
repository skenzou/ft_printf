/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:11:51 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/08 06:21:55 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# define CONV "diouxXcspfDOUb%"
# define H 1
# define HH	2
# define L	3
# define LL	4
# define LU	5
# define Z	6
# define J  7

typedef struct		s_format
{
	char			conversion;
	int				width;
	int				precision;
	short			modifier;
	char			signe;
	char			minus;
	char			zero;
	char			prefixe;
	int				base;
	int				(*handler)(struct s_format *fmt, va_list ap);
}					t_format;

int					ft_printf(const char *restrict format, ...);
t_format			*create_format(char *str, va_list ap);
int					parse_format(char *str, va_list ap);
int					check_conversion(char **str);
void				set_conversion(char *str, t_format *fmt);
short				get_modifier(char *str, t_format *fmt);
int					get_precision(char *str, t_format *fmt, va_list ap);
int					get_width(char *str, va_list ap, t_format *fmt);
short				get_signe(char *str);
char				get_zero(char *str);
char				get_space(char *str);
void				set_flags(char *str, t_format *fmt);
int					handle_char(t_format *fmt, va_list ap);
int					handle_numbers(t_format *fmt, va_list ap);
int					handle_str(t_format *fmt, va_list ap);
int					handle_percent(t_format *fmt, va_list ap);
intmax_t			get_signed(t_format *fmt, va_list ap);
uintmax_t			get_unsigned(t_format *fmt, va_list ap);
int					print_numbers(t_format *fmt, char *str, int len);
void				print_format(t_format *fmt);
char				*get_string(t_format *fmt, va_list ap);

#endif
