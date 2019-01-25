/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:18:31 by midrissi          #+#    #+#             */
/*   Updated: 2019/01/25 20:26:37 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	int		len;
	int		tmp;
	char	*str;

	len = 0;
	if (value == 0)
		return ("0");
	tmp = value < 0 ? -value : value;
	while (tmp > 0 && ++len)
		tmp /= base;
	len += (value < 0 && base == 10);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp = value < 0 ? -1 : 1;
	value = value < 0 ? -value : value;
	while (value > 0)
	{
		str[--len] = 48 + (value % base);
		str[len] = str[len] > 57 ? 65 + (str[len] - 58) : str[len];
		value /= base;
	}
	(tmp < 0 && base == 10) && (str[--len] = '-');
	return (str);
}

int		main(void)
{
	printf("%s\n", ft_itoa_base(-1, 10));
	printf("%s\n", ft_itoa_base(11, 16));
	printf("%s\n", ft_itoa_base(12, 16));
	printf("%s\n", ft_itoa_base(13, 16));
	printf("%s\n", ft_itoa_base(14, 16));
	printf("%s\n", ft_itoa_base(15, 16));
	printf("%s\n", ft_itoa_base(16, 16));
	printf("%s\n", ft_itoa_base(17, 16));
}
