/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:09:19 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/08 07:01:04 by midrissi         ###   ########.fr       */
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
	str = (char *)malloc(sizeof(char) * (precision + 1));
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
	if (precision == -2)
		return (ft_itoa(save));
	str = ft_strjoin(ft_strjoin(ft_itoa(save), "."), str);
	return (str);
}
