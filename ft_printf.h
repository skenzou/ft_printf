/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:11:51 by midrissi          #+#    #+#             */
/*   Updated: 2019/01/23 19:23:37 by midrissi         ###   ########.fr       */
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

typedef struct	s_format
{
	char			conversion;
	unsigned int	width;
	int				precision;
	short			modifier;
	char			plus;
	char			minus;
	char			zero;
	char			space;
	char			prefixe;
}				t_format;

int				ft_printf(const char *restrict format, ...);
t_format	*create_format(char **str);
t_list		*parse_format(char *str, va_list ap);
int		check_conversion(char *str);
char	get_conversion(char *str);
short	get_modifier(char *str);
int		get_precision(char *str);
int		get_width(char *str);
short		get_signe(char *str);
char	get_zero(char *str);
char	get_space(char *str);
int		ft_printf(const char *restrict format, ...);
void	set_flags(char *str, t_format *fmt);
void print_format(t_format *fmt); //remove

#endif
