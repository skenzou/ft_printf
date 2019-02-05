/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:18:31 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/05 16:48:53 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long n, int base, int uppercase)
{
	char *nb;

	nb = ft_utoa_base(ABS(n), base, uppercase);
	return (n < 0 ? ft_strjoin("-", nb) : nb);
}
