/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:10:48 by midrissi          #+#    #+#             */
/*   Updated: 2019/01/24 16:16:19 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static	ft_putsubstr(char *str, char c)
{
	int i;

	 i = 0;
	 while(str[i] && str[i] != c)
	 	write(1,str + i, 1);
}*/
/*	c = 0;
	s = 0;
	if (fmt->modifier == HH)
	{
		c = (char) va_arg(ap, int);
		ft_putstr(ft_itoa((int)c));
	}
	else if (fmt->modifier == H)
	{
		s = (short) va_arg(ap, int);
		ft_putstr(ft_itoa((int)s));
	}
	else
	{*/

#include <stdio.h>
void		process_int(t_format *fmt, va_list ap)
{
	int		i;
	char *str;
	char fill;
	char *prec;
	int		len;

	fill = fmt->zero ? fmt->zero : ' ';
	i = va_arg(ap, int);
	str = ft_itoa(i);
	if ((fmt->plus || fmt->space) && i >= 0)
		fmt->precision++;
	len = fmt->width - fmt->precision;
	fmt->precision-=ft_strlen(str);
	fmt->precision = fmt->precision < 0 ? 0 : fmt->precision;
	prec = ft_strnew(fmt->precision);
	ft_memset(prec, '0', fmt->precision);
	prec[0] = fmt->space ? fmt->space : '0';
	if (fmt->plus)
		prec[0] = fmt->plus;
	str = ft_strjoin(prec, str);
	if (fmt->minus)
		ft_putstr(str);
	while (len > 0)
	{
		ft_putchar(fill);
		len--;
	}
	if (!fmt->minus)
		ft_putstr(str);
}

void 		process_conversion(t_format *fmt, va_list ap)
{
	//print_format(fmt);
	if (fmt->conversion == 'd' || fmt->conversion == 'i')
		process_int(fmt, ap);
	/*else if ((fmt->conversion == 'd' || fmt->conversion == 'i')
		&& fmt->modifier == HH)
		process_char(fmt, ap);
	else if ((fmt->conversion == 'd' || fmt->conversion == 'i')
		&& fmt->modifier == H)
		process_short(fmt, ap);
	if (fmt->conversion == 'o')
		process_oct(fmt, ap);
	if (fmt->conversion == 'u')
		process_unsigned(fmt, ap);
	if (fmt->conversion == 'x' || fmt->conversion == 'X')
		process_hex(fmt, ap);
	if (fmt->conversion == 'c')
		process_char(fmt, ap);
	if (fmt->conversion == 's')
		process_str(fmt, ap);
	if (fmt->conversion == 'p')
		process_pointer(fmt, ap);
	if (fmt->conversion == 'f')
		process_float(fmt, ap);*/

}

t_list		*parse_format(char *str, va_list ap)
{
	//t_list	*lst;
	//t_format *fmt;


	//lst = NULL;
	while (*str)
	{
		if(*str == '%' && *(str + 1) != '%')
		{
			if (!check_conversion(str))
			{
				str++;
				continue;
			}else{
				process_conversion(create_format(&str), ap);
				/*if(!lst)
					lst = create_format(&str), sizeof(t_format));
				else
					ft_lstpushfront(&lst, ft_lstnew(create_format(&str), sizeof(t_format)));*/
			}
		} else if (*str == '%' && *(str + 1) == '%')
			{
			write(1, str, 1);
			str+=2;
			}
			else
				write(1, str++, 1);
	}
	return (NULL);
}
#include <stdio.h>
t_format	*create_format(char **str)
{
	t_format	*fmt;
	if(!(fmt = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	fmt->conversion = get_conversion(*str);
	fmt->width = get_width(*str);
	fmt->precision = get_precision(*str);
	fmt->modifier = get_modifier(*str);
	set_flags(*str, fmt);
	while(**str && !ft_strchr(CONV, **str))
		(*str)++;
	(*str)++;
	return (fmt);
}

void 	set_flags(char *str, t_format *fmt)
{
	fmt->zero = 0;
	fmt->minus = 0;
	fmt->plus = 0;
	fmt->prefixe = 0;
	fmt->space = 0;
	while (*str && !ft_strchr(CONV, *str))
	{
		if (*str == '0' && !ft_isdigit(*(str - 1)) && !fmt->precision)
			fmt->zero = '0';
		if (*str == ' ')
			fmt->space = ' ';
		if (*str == '+')
		{
			fmt->space = 0;
			fmt->plus = '+';
		}
		if (*str == '-')
			fmt->minus = '-';
		if (*str == '#')
			fmt->prefixe = '#';
		str++;
	}
}
int		check_conversion(char *str)
{
	str++;
	while(*str && !ft_strchr(CONV, *str))
	{
		if(!ft_strchr("-+ 0lLh.", *str) && !ft_isdigit(*str))
			return (0);
		str++;
	}
	if (!*str)
		return (0);
	return(1);
}

char	get_conversion(char *str)
{
	while(*str)
	{
		if(ft_strchr(CONV, *str))
			return (*str);
		str++;
	}
	return (0);
}

short	get_modifier(char *str)
{
	int lcount;
	int hcount;
	int lucount;

	lcount = 0;
	hcount = 0;
	lucount = 0;
	while(*str && !ft_strchr(CONV, *str))
	{
		if(*str == 'h')
			hcount++;
		if(*str == 'l')
			lcount++;
		if(*str == 'L')
			lucount++;
		str++;
	}
	if(*str == 'f' && lucount)
		return (LU);
	if(lcount && lcount % 2)
		return (L);
	if(lcount)
		return (LL);
	if(hcount && hcount % 2)
		return (H);
	if(hcount)
		return (HH);
	return(0);
}

int		get_precision(char *str)
{
	int precision;

	precision = 0;
	while(*str && !ft_strchr(CONV, *str))
	{
		if(*str == '.')
		{
			precision = 0;
			str++;
			while(ft_isdigit(*str))
			{
				precision*=10;
				precision = precision + (*str - 48);
				str++;
			}
			continue;
		}
		str++;
	}
	return (precision);
}

int		get_width(char *str)
{
	int width;

	width = 0;
	while (*str && !ft_strchr(CONV, *str))
	{
		if(*str == '.')
		{
			str++;
			while(ft_isdigit(*str))
				str++;
			continue;
		}
		if(ft_isdigit(*str))
		{
			width = 0;
			while(ft_isdigit(*str))
			{
				width*=10;
				width = width + (*str - 48);
				str++;
			}
			continue;
		}
		str++;
	}
	return (width);
}
/*short		get_signe(char *str)
{
	short	signe;

	signe = 0;
	while(*str && !ft_strchr(CONV, *str))
	{
		if(!signe && *str == '+')
			signe = 1;
		if(!signe && *str == '-')
			signe = 2;
		if ((signe == 1 && *str == '-') || (signe == 2 && *str == '+'))
			signe = 3;
		str++;
	}
	return (signe);
}

char	get_zero(char *str)
{
	while(*str && !ft_strchr(CONV, *str))
	{
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			return '0';
		str++;
	}
	return (0);
}

char	get_space(char *str)
{
	while(*str && !ft_strchr(CONV, *str))
	{
		if(*str == ' ')
			return (' ');
		str++;
	}
	return (0);
}*/
#include <stdio.h>
void print_format(t_format *fmt)
{
	int i;

	i = 1;
		printf(
"maillon numero :%d\nconversion: %c\nwidth:%u\nprecision: %u\nmodifier: %hd\nplus: %c\nminus: %c\nzero: %c\nspace: %c",
		i, fmt->conversion,
		fmt->width, fmt->precision, fmt->modifier, fmt->plus, fmt->minus, fmt->zero, fmt->space);
}
int main(void)
{
	//t_list *lst;
	printf("abcd%- kd", 12);
	//printf("abcd%-+ 010.55llllld\nici:%d%3km1", 10, 20);
	//lst = parse_format("%-+ 010.55llllld%+0120.49Lf");
	//print_format(lst);
	return (0);
}
int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;

	va_start(ap, format);
	parse_format((char *)format, ap);
	va_end(ap);
	return (0);
}

/*void handle_flag(va_list list, const char *restrict format)
{
		if ()
}*/
