/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:10:48 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/08 00:06:09 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		handle_percent(t_format *fmt, va_list ap)
{
	char	c;

	(void)ap;
	c = '%';
	if (fmt->minus)
	{
		ft_putchar(c);
		ft_nputchar(' ', fmt->width - 1);
	}
	else
	{
		ft_nputchar(fmt->zero ? '0' : ' ', fmt->width - 1);
		ft_putchar(c);
	}
	return (fmt->width > 0 ? fmt->width : 1);
}

int		handle_char(t_format *fmt, va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (fmt->minus)
	{
		ft_putchar(c);
		ft_nputchar(' ', fmt->width - 1);
	}
	else
	{
		ft_nputchar(fmt->zero ? '0' : ' ', fmt->width - 1);
		ft_putchar(c);
	}
	return (fmt->width > 0 ? fmt->width : 1);
}

int		handle_str(t_format *fmt, va_list ap)
{
	char	*str;
	int		ret;

	str = va_arg(ap, char*);
	str = !str ? "(null)" : str;
	if (fmt->precision >= 0 && ((size_t)fmt->precision < ft_strlen(str)))
	{
		str = ft_strsub(str, 0, (size_t)fmt->precision);
		fmt->precision = -5;
	}
	str == NULL ? exit(1) : NULL;
	ret = ft_strlen(str);
	if (fmt->minus)
	{
		ft_putstr(str);
		ft_nputchar(' ', fmt->width - ret);
	}
	else
	{
		ft_nputchar(fmt->zero ? '0' : ' ', fmt->width - ret);
		ft_putstr(str);
	}
	if (fmt->precision == -5)
		ft_strdel(&str);
	return (ret < fmt->width ? fmt->width : ret);
}

intmax_t	get_signed(t_format *fmt, va_list ap)
{
	if (fmt->modifier == HH)
		return ((char)va_arg(ap, long long));
	else if (fmt->modifier == H)
		return ((short)va_arg(ap, long long));
	else if (fmt->modifier == L || fmt->modifier == LL)
		return (va_arg(ap, long long));
	else if (fmt->modifier == Z)
		return (va_arg(ap, size_t));
	else if (fmt->modifier == J)
		return (va_arg(ap, intmax_t));
	else
		return (va_arg(ap, int));
	return (0);
}

uintmax_t	get_unsigned(t_format *fmt, va_list ap)
{
	if (fmt->modifier == L || fmt->modifier == LL
			|| fmt->conversion == 'p')
		return (va_arg(ap, unsigned long long));
	else if (fmt->modifier == H)
		return ((unsigned short)va_arg(ap, unsigned long long));
	else if (fmt->modifier == HH)
		return ((unsigned char)va_arg(ap, unsigned long long));
	else if (fmt->modifier == Z)
		return (va_arg(ap, size_t));
	else if (fmt->modifier == J)
		return (va_arg(ap, uintmax_t));
	else
		return (va_arg(ap, unsigned int));
	return (0);
}

int		print_prefixe(char c)
{
	int i;

	i = 0;
	c = c == 'p' ? 'x' : c;
	if (c == 'o' || c == 'x' || c == 'X')
	{
		ft_putchar('0');
		i++;
	}
	if (c == 'x' || c == 'X')
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int	print_numbers(t_format *fmt, char *str, int len)
{
	int ret;

	ret = 0;
	if (fmt->minus)
	{
		fmt->signe ? ft_putchar(fmt->signe) : NULL;
		if (fmt->prefixe)
			ret = print_prefixe(fmt->conversion);
		ft_nputchar('0', fmt->precision);
		ft_putstr(str);
		ft_nputchar(' ', len);
	}
	else
	{
		!fmt->zero ? ft_nputchar(' ', len) : NULL;
		fmt->signe ? ft_putchar(fmt->signe) : NULL;
		if (fmt->prefixe)
			ret = print_prefixe(fmt->conversion);
		fmt->zero ? ft_nputchar(fmt->zero, len) : NULL;
		ft_nputchar('0', fmt->precision);
		ft_putstr(str);
	}
	len = len < 0 ? 0 : len;
	return (ret + ft_strlen(str) + len + fmt->precision + (fmt->signe != 0));
}

char	*get_string(t_format *fmt, va_list ap)
{
	char *str;

	str = NULL;
	if (fmt->conversion == 'f')
	{
		if (fmt->modifier == LU)
			str = ft_ftoa(va_arg(ap, long double), fmt->precision);
		else
			str = ft_ftoa(va_arg(ap, double), fmt->precision);
		fmt->precision = 0;
	}
	else if (fmt->conversion == 'd' || fmt->conversion == 'i')
		str =
		ft_itoa_base(get_signed(fmt, ap), fmt->base, !(fmt->conversion > 96));
	else
		str =
		ft_utoa_base(get_unsigned(fmt, ap), fmt->base, !(fmt->conversion > 96));
	str == NULL ? exit(1) : NULL;
	return (str);
}

int		handle_numbers(t_format *fmt, va_list ap)
{
	char		*str;
	int			len;

	str = get_string(fmt, ap);
	if (!fmt->precision && str[0] == '0' && fmt->conversion != 'f')
	{
		if (fmt->conversion == 'x' || fmt->conversion == 'X')
			fmt->prefixe = 0;
		str[0] = '\0';
	}
	if (fmt->conversion != 'p')
		fmt->prefixe = *str == '0' ? 0 : fmt->prefixe;
	if (*str == '-')
		fmt->signe = *(str++);
	fmt->precision -= ft_strlen(str);
	fmt->precision = fmt->prefixe == 1 ? fmt->precision - 1 : fmt->precision;
	fmt->precision = fmt->precision < 0 ? 0 : fmt->precision;
	len = fmt->width - ft_strlen(str) - (fmt->signe ? 1 : 0) - fmt->precision;
	len -= fmt->prefixe;
	len = print_numbers(fmt, str, len);
	fmt->signe == '-' ? free(--str) : ft_strdel(&str);
	return (len);
}

int		parse_format(char *str, va_list ap)
{
	t_format	*fmt;
	int			ret;

	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			fmt = create_format(++str, ap);
			if (check_conversion(&str))
				ret += fmt->handler(fmt, ap);
			free(fmt);
		}
		else
		{
			write(1, str++, 1);
			ret++;
		}
	}
	return (ret);
}

t_format	*create_format(char *str, va_list ap)
{
	t_format	*fmt;

	if (!(fmt = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	fmt->minus = 0;
	set_conversion(str, fmt);
	fmt->width = get_width(str, ap, fmt);
	fmt->precision = get_precision(str, fmt, ap);
	if (!fmt->modifier)
		fmt->modifier = get_modifier(str);
	set_flags(str, fmt);
	if (ft_strchr("diouxXbp", fmt->conversion) && fmt->precision != -1)
		fmt->zero = 0;
	if (fmt->conversion == 'c')
		fmt->handler = &handle_char;
	else if (fmt->conversion == 's')
		fmt->handler = &handle_str;
	else if (fmt->conversion == '%')
		fmt->handler = &handle_percent;
	else
		fmt->handler = &handle_numbers;
	return (fmt);
}

void	set_flags(char *str, t_format *fmt)
{
	fmt->zero = 0;
	fmt->minus = fmt->minus == '-' ? fmt->minus : 0;
	fmt->signe = 0;
	fmt->prefixe = 0;
	while (*str && !ft_strchr(CONV, *str))
	{
		if (*str == '0' && !ft_isdigit(*(str - 1)) && *(str - 1) != '.')
			fmt->zero = '0';
		if (*str == ' ' && !fmt->signe && ft_strchr("dif", fmt->conversion))
			fmt->signe = ' ';
		if (*str == '+' && ft_strchr("dif", fmt->conversion))
			fmt->signe = '+';
		fmt->minus = *str == '-' ? '-' : fmt->minus;
		if (*str == '#' && fmt->conversion == 'o')
			fmt->prefixe = 1;
		if ((*str == '#' && (fmt->conversion == 'x' || fmt->conversion == 'X')))
			fmt->prefixe = 2;
		str++;
	}
	if (fmt->conversion == 'p')
		fmt->prefixe = 2;
}

int		check_conversion(char **str)
{
	while (**str && !ft_strchr(CONV, **str))
	{
		if (!ft_strchr("-+ #0lLhzj*.", **str) && !ft_isdigit(**str))
			return (0);
		(*str)++;
	}
	if (!(**str))
		return (0);
	(*str)++;
	return (1);
}

void	set_conversion(char *str, t_format *fmt)
{
	fmt->modifier = 0;
	while (*str)
	{
		if (ft_strchr(CONV, *str))
		{
			fmt->conversion = *str;
			if (ft_strchr("DOU", fmt->conversion))
			{
				fmt->modifier = L;
				fmt->conversion = ft_tolower(fmt->conversion);
			}
			fmt->base = 10;
			if (fmt->conversion == 'x' || fmt->conversion == 'X'
				|| fmt->conversion == 'p')
				fmt->base = 16;
			fmt->base = fmt->conversion == 'o' ? 8 : fmt->base;
			fmt->base = fmt->conversion == 'b' ? 2 : fmt->base;
			return ;
		}
		str++;
	}
	fmt->conversion = 0;
}

short	get_modifier(char *str)
{
	int counts[5];
	int i;

	i = 0;
	while (i < 5)
		counts[i++] = 0;
	while (*str && !ft_strchr(CONV, *str))
	{
		counts[0] = *str == 'h' ? counts[0] + 1 : counts[0];
		counts[1] = *str == 'l' ? counts[1] + 1 : counts[1];
		counts[2] = *str == 'L' ? counts[2] + 1 : counts[2];
		counts[3] = *str == 'z' ? counts[3] + 1 : counts[3];
		counts[4] = *str == 'j' ? counts[4] + 1 : counts[4];
		str++;
	}
	if (*str == 'f' && counts[2])
		return (LU);
	if (counts[4])
		return (J);
	if (counts[3])
		return (Z);
	if (counts[1] && counts[1] % 2)
		return (L);
	if (counts[1])
		return (LL);
	if (counts[0] && counts[0] % 2)
		return (H);
	return (counts[0] ? HH : 0);
}

int		get_precision(char *str, t_format *fmt, va_list ap)
{
	int precision;
	int point;

	point = 0;
	while (*str && !ft_strchr(CONV, *str))
	{
		if (*str == '.')
		{
			point = 1;
			precision = 0;
			str++;
			while (ft_isdigit(*str))
			{
				precision *= 10;
				precision = precision + (*str - 48);
				str++;
			}
			if (*str == '*' && *(str - 1) == '.' && str++)
			{
				precision = va_arg(ap, int);
				point = precision < 0 ? 0 : point;
			}
			continue;
		}
		str++;
	}
	if (!point)
		precision = -1;
	if (!point && fmt->conversion == 'f')
		precision = 6;
	return (precision);
}

int		get_width(char *str, va_list ap, t_format *fmt)
{
	int width;
	int temp;

	width = 0;
	while (*str && !ft_strchr(CONV, *str))
	{
		if (*str == '.')
		{
			str++;
			while (ft_isdigit(*str))
				str++;
			str += (*str == '*' && *(str - 1) == '.');
			continue;
		}
		if (*str == '*')
		{
			width = va_arg(ap, int);
			fmt->minus = width < 0 ? '-' : 0;
			width = ABS(width);
		}
		if (ft_isdigit(*str))
		{
			temp = 0;
			while (ft_isdigit(*str))
			{
				temp *= 10;
				temp += (*(str++) - 48);
			}
			width = temp ? temp : width;
			continue;
		}
		str++;
	}
	return (width);
}

void	print_format(t_format *fmt)
{
	int i;

	i = 1;
	printf(
"maillon numero :%d\nconversion: %c\nwidth:%u\nprecision: %d\nmodifier: \
%hd\nsigne: %c\nminus: %c\nzero: %hhd\nprefixe: %hhd\n",
		i, fmt->conversion,
		fmt->width, fmt->precision, fmt->modifier, fmt->signe, fmt->minus,
		fmt->zero, fmt->prefixe);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = parse_format((char *)format, ap);
	va_end(ap);
	return (ret);
}
