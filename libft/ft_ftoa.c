/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:09:19 by midrissi          #+#    #+#             */
/*   Updated: 2019/01/29 20:09:29 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_ftoa(double d, int precision)
{
	long long	temp;
	long long	c;
	long long	save;
	char		*str;

	save = d;
	d -= save;
	c = 0;
	temp = 0;
	str =
	while (precision-- > 0)
	{
		// c *= 10;
		// d *= 10.0;
		// c += temp;
		// temp = d;
		// d -= temp;
		c *= 10;
		d *= 10.0;
		temp = d;
		c += temp;
		d -= temp;

	}
	str = ft_strjoin(ft_strjoin(ft_itoa(save), "."), ft_itoa(c));
	return (str);
}
