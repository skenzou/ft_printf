/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:19:36 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/02 22:26:27 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
	double num = 9.146555553;
//ft_printf("%.4f\n", num);
//printf("%.4f\n", num);
	//printf("%5%");
	ft_printf("@moulitest: %#.o\n", 0);
	printf("@moulitest: %#.o\n", 0);
	//printf("string: |%%%%%%|\n");
	//ft_printf("string: |%%%%%%|\n");

	//printf("%10s is a string", "this");
}

/*long double    ft_round(long double fl, long precision)
{
    long double    diviseur;

    diviseur = 5;
    if (!precision)
        return (fl + (fl > 0.0 ? 0.5 : -0.5));
    while (precision-- >= 0)
        diviseur /= 10;
    return (fl + (fl > 0.0 ? diviseur : -diviseur));
}

9.1465
+
0.0005
*/
