/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:27:19 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/05 23:41:41 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned long long nb, unsigned base, int uppercase)
{
	int					len;
	unsigned long long	tmp;
	char				*str;

	len = 1;
	tmp = nb;
	while (tmp >= base && ++len)
		tmp /= base;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	tmp = uppercase ? 55 : 87;
	while (len--)
	{
		str[len] = nb % base > 9 ? tmp + (nb % base) : 48 + (nb % base);
		nb /= base;
	}
	return (str);
}
