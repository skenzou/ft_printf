/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:11:51 by midrissi          #+#    #+#             */
/*   Updated: 2019/01/30 22:51:21 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# define CONV "diouxXcspf"
# define H 1
# define HH	2
# define L	3
# define LL	4
# define LU	5
# define ABS(x) x < 0 ? -x : x;

typedef struct	s_format
{
	char			conversion;
	unsigned int	width;
	int				precision;
	short			modifier;
	char			signe;
	char			minus;
	char			zero;
	char			prefixe;
	int				base;
	int				(*handler)(struct s_format *fmt, va_list ap);
}				t_format;

int			ft_printf(const char *restrict format, ...);
t_format	*create_format(char *str);
int			parse_format(char *str, va_list ap);
int			check_conversion(char **str);
void		set_conversion(char *str, t_format *fmt);
short		get_modifier(char *str);
int			get_precision(char *str);
int			get_width(char *str);
short		get_signe(char *str);
char		get_zero(char *str);
char		get_space(char *str);
int			ft_printf(const char *restrict format, ...);
void		set_flags(char *str, t_format *fmt);
int			handle_char(t_format *fmt, va_list ap);
int			handle_numbers(t_format *fmt, va_list ap);
int			handle_str(t_format *fmt, va_list ap);
long long	get_number(t_format *fmt, va_list ap);
int			print_numbers(t_format *fmt, char *str, int len);
void		print_format(t_format *fmt);

#endif
