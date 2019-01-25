/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:38:34 by midrissi          #+#    #+#             */
/*   Updated: 2018/10/11 11:15:32 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t size;

	size = 0;
	while (n > 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char		*allocate_mem(int *n, int *i)
{
	char	*str;
	int		signe;

	signe = 0;
	*i = 0;
	if (*n < 0)
	{
		signe = 1;
		*n = -(*n);
	}
	if (signe)
	{
		str = (char *)malloc(sizeof(char) * (get_size(*n) + 2));
		if (!str)
			return (NULL);
		str[(*i)++] = '-';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (get_size(*n) + 1));
		if (!str)
			return (NULL);
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = allocate_mem(&n, &i);
	if (!str)
		return (NULL);
	i = i + get_size(n) - 1;
	if (n == 0)
		return (ft_strdup("0"));
	str[i + 1] = '\0';
	while (n > 0)
	{
		str[i--] = 48 + n % 10;
		n = n / 10;
	}
	return (str);
}
