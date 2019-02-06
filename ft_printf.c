/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:10:48 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/06 15:49:51 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	str = !str ? ft_strdup("(null)") : str;
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
	if (fmt->modifier == HH)
		return ((unsigned char)va_arg(ap, unsigned long long));
	else if (fmt->modifier == H)
		return ((unsigned short)va_arg(ap, unsigned long long));
	else if (fmt->modifier == L || fmt->modifier == LL
			|| fmt->conversion == 'p')
		return (va_arg(ap, unsigned long long));
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
		str = ft_itoa_base(get_signed(fmt, ap), fmt->base, !(fmt->conversion > 96));
	else
		str = ft_utoa_base(get_unsigned(fmt, ap), fmt->base, !(fmt->conversion > 96));
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
		if (*str == '%' && *(str + 1) != '%')
		{
			fmt = create_format(str);
			if (check_conversion(&str))
				ret += fmt->handler(fmt, ap);
			free(fmt);
		}
		else if (*str == '%' && *(str + 1) == '%')
		{
			write(1, str, 1);
			str += 2;
			ret++;
		}
		else
		{
			write(1, str++, 1);
			ret++;
		}
	}
	return (ret);
}

t_format	*create_format(char *str)
{
	t_format	*fmt;

	if (!(fmt = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	set_conversion(str, fmt);
	fmt->width = get_width(str);
	fmt->precision = get_precision(str, fmt);
	if (!fmt->modifier)
		fmt->modifier = get_modifier(str);
	set_flags(str, fmt);
	if (ft_strchr("diouxX", fmt->conversion) && ft_strchr(str, '.'))
		fmt->zero = 0;
	if (fmt->conversion == 'c')
		fmt->handler = &handle_char;
	else if (fmt->conversion == 's')
		fmt->handler = &handle_str;
	else
		fmt->handler = &handle_numbers;
	return (fmt);
}

void	set_flags(char *str, t_format *fmt)
{
	fmt->zero = 0;
	fmt->minus = 0;
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
		if ((*str == '#' && (fmt->conversion == 'x' || fmt->conversion == 'X'))
			|| fmt->conversion == 'p')
			fmt->prefixe = 2;
		str++;
	}
}

int		check_conversion(char **str)
{
	(*str)++;
	while (**str && !ft_strchr(CONV, **str))
	{
		if (!ft_strchr("-+ #0lLhzj.", **str) && !ft_isdigit(**str))
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
			return ;
		}
		str++;
	}
	fmt->conversion = 0;
}

short	get_modifier(char *str)
{
	int lcount;
	int hcount;
	int lucount;
	int zcount;
	int jcount;

	lcount = 0;
	hcount = 0;
	lucount = 0;
	zcount = 0;
	jcount = 0;
	while (*str && !ft_strchr(CONV, *str))
	{
		hcount = *str == 'h' ? hcount + 1 : hcount;
		lcount = *str == 'l' ? lcount + 1 : lcount;
		lucount = *str == 'L' ? lucount + 1 : lucount;
		zcount = *str == 'z' ? zcount + 1 : zcount;
		jcount = *str == 'j' ? jcount + 1 : jcount;
		str++;
	}
	if (*str == 'f' && lucount)
		return (LU);
	if (jcount)
		return (J);
	if (zcount)
		return (Z);
	if (lcount && lcount % 2)
		return (L);
	if (lcount)
		return (LL);
	if (hcount && hcount % 2)
		return (H);
	if (hcount)
		return (HH);
	return (0);
}

int		get_precision(char *str, t_format *fmt)
{
	int precision;
	int point;

	precision = 0;
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

int		get_width(char *str)
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
			continue;
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
"maillon numero :%d\nconversion: %c\nwidth:%u\nprecision: %u\nmodifier: \
%hd\nplus: %c\nminus: %c\nzero: %c\nprefixe: %hhd\n",
		i, fmt->conversion,
		fmt->width, fmt->precision, fmt->modifier, fmt->signe, fmt->minus,
		fmt->zero, fmt->prefixe);
}

#include <float.h>


/*int main(void)
{
	//t_list *lst;
	//char *c = NULL;
	//int i;
	//char b = 'l';
	//unsigned int u= 4294967295;
	//i = printf("%# 010o\n%+ ld\n%d\n",   8, 10);
	//float num = 5.4895812300;
	//ft_printf("|%06.2s|\n", "string");
	//printf("|%06.2s|\n", "string");
	//ft_printf("%e");
	//printf(" retour de printf: %d\n", i);
	//printf("%10p\n",  c);
	//ft_printf("%10p\n",   c);
	//long double xd = LDBL_MAX;
	//double lol = 18.6312341234;
	//void *c = "aa";
	//int i, j;
	double num = 126.999;
	//j = ft_printf("%10.2s\n", "coucou");
	ft_printf("|%24.13l14d|\n", 10);
    printf("|%24.13l14d|\n", 10);
	//printf("retour du printf man: %d\n", i);
	//printf("retour de mon printf: %d\n", j);
	//ft_printf("%-20lf\n", xd);
	//printf("%-20Lf	\n", xd);
	//printf("xdddd\n");
	//ft_ftoa(lol, 10);

	return (0);
}*/

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = parse_format((char *)format, ap);
	va_end(ap);
	return (ret);
}
