/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:38:34 by midrissi          #+#    #+#             */
/*   Updated: 2019/01/26 14:22:59 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	int			len;
	long long	tmp;
	char		*str;

	if (n == 0)
		return ("0");
	len = 0;
	tmp = n < 0 ? -n : n;
	while (tmp > 0 && ++len)
		tmp /= 10;
	len += (n < 0);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	tmp = n < 0 ? 1 : 0;
	n = n < 0 ? -n : n;
	while (n > 0)
	{
		str[--len] = 48 + n % 10;
		n /= 10;
	}
	if (tmp)
		str[--len] = '-';
	return (str);
}

/*static size_t	get_size(int n)
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

char			*ft_itoa(long long n)
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
}*/
