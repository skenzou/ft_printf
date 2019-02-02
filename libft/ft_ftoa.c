/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:09:19 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/02 22:26:31 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long double		round_num(long double d, int precision)
{
	long double i;
	long double doublesave;
	int			save;
	int			temp;

	i = 1.0;
	doublesave = d;
	save = precision + 1;
	while (precision-- > 0)
		i /= 10.0;
	d -= ((int)d);
	while (save-- > 0)
	{
		d *= 10.0;
		temp = d;
		d -= temp;
	}
	while (temp == 5)
	{
		d *= 10.0;
		temp = d;
		d -= temp;
	}
	return (temp < 5 ? doublesave : doublesave + i);
}

char	*ft_ftoa(long double d, int precision)
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

/*int main (void)
{
	long double d = 127.999;
	printf("ftoa restul test: %s\n", ft_ftoa(d, 34));
	//printf("rounded num: %Lf\n",round_num(d, 31));
	printf("%.34Lf\n", d);
}*/
