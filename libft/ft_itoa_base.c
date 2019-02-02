/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:18:31 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/02 22:26:35 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(long long nb, int base, int uppercase)
{
	int			len;
	long long	tmp;
	char		*str;

	len = 0;
	if (base == 10)
		return (ft_itoa(nb));
	if (nb == 0)
		return (ft_strdup("0"));
	tmp = nb;
	while (tmp > 0 && ++len)
		tmp /= base;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	tmp = uppercase ? 55 : 87;
	while (nb > 0)
	{
		str[--len] = nb % base > 9 ? tmp + (nb % base) : 48 + (nb % base);
		nb /= base;
	}
	return (str);
}
