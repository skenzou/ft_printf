/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:09:19 by midrissi          #+#    #+#             */
/*   Updated: 2019/01/30 22:51:17 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_ftoa(long double d, int precision)
{
	long long	temp;
	int			i;
	long long	save;
	char		*str;

	save = d;
	d -= save;
	i = 0;
	str = (char *)malloc(sizeof(char) * (precision + 1));
	str[precision] = '\0';
	d = d < 0 ? -d : d;
	while (precision-- > 0)
	{
		d *= 10.0;
		temp = d;
		str[i++] = temp + 48;
		d -= temp;
	}
	str = ft_strjoin(ft_strjoin(ft_itoa(save), "."), str);
	return (str);
}
