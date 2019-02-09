/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:09:19 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/08 23:00:24 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double		round_num(long double d, int precision)
{
	long double		diviseur;

	diviseur = 5;
	if (!precision)
		return (d + (d > 0.0 ? 0.5 : -0.5));
	while (precision-- >= 0)
		diviseur /= 10;
	return (d + (d > 0.0 ? diviseur : -diviseur));
}

static	char			*create_string(long long save, char **decimal, int prec)
{
	char *str;
	char *integer;

	if (prec == -2)
	{
		ft_strdel(decimal);
		return (ft_itoa(save));
	}
	integer = ft_itoa(save);
	str = ft_strjoin(integer, ".");
	ft_strdel(&integer);
	integer = str;
	str = ft_strjoin(str, *decimal);
	ft_strdel(&integer);
	ft_strdel(decimal);
	return (str);
}

char					*ft_ftoa(long double d, int precision)
{
	long long	temp;
	int			i;
	long long	save;
	char		*str;

	d = round_num(d, precision);
	save = d;
	d -= save;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (precision + 1))))
		return (NULL);
	str[precision] = '\0';
	d = d < 0 ? -d : d;
	precision = !precision ? -1 : precision;
	while (precision-- > 0)
	{
		d *= 10.0;
		temp = d;
		str[i++] = temp + 48;
		d -= temp;
	}
	return (create_string(save, &str, precision));
}
