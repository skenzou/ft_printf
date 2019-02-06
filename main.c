/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:19:36 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/06 15:48:08 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
	//double num = 9.146555553;
	//unsigned long u_max= 8446744073709551615;
//ft_printf("%.4f\n", num);
//printf("%.4f\n", num);
	//printf("%5%");
	int i;
	int j;
//	int x = 10000;
	size_t u = 5;
	char *str;
	str ="aha";
	//ft_utoa_base(ULONG_MAX, 10, 0);
	//printf("%s\n", ft_itoa_base(u_max, 10, 0));
	//ft_printf("%#x\n", 0);

	i = ft_printf("%ju\n", ULLONG_MAX);
	j = printf("%ju\n", ULLONG_MAX);
	//ft_printf("%#o\n", 0);
	//printf("%#o\n", 0);
	//ft_printf("%.#x\n", 0);
	//printf("%.#x\n", 0);
	printf("valeur de retour de mon ptf: %d\n", i);
	printf("valeur de retour du printf stdio: %d\n", j);
	//-fsanitize=address

	// i = ft_printf("a%ob%oc%od\n",0, 55555, 100000);
	// j = printf("a%ob%oc%od\n", 0, 55555, 100000);
	// ft_printf("%o%o%o%o%o\n",1, 100, 999, 42, 999988888);
	// ft_printf("before %o after\n", 42);
	// printf("before %o after\n", 42);
	// printf("%o%o%o%o%o\n",1, 100, 999, 42, 999988888);

	//printf("string: |%%%%%%|\n");
	//ft_printf("string: |%%%%%%|\n");
	/*char *str_ = "|%+0.1f|\n";
	double n = 3.944545454;
	double n_ = -3.944545454;
	printf(str_, n);
	ft_printf(str_, n);
	printf(str_, n_);
	ft_printf(str_, n_);
	ft_putchar('\n');
	char *str = "|%+0.1d|\n";
	long long int nb = 96529;
	long long nb_ = 96529;
	printf(str, nb);
	ft_printf(str, nb);
	printf(str, nb_);
	ft_printf(str, nb_);*/





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
