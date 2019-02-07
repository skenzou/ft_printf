/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:19:36 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/08 00:03:25 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int		main(int argc, char **argv)
{
	unsigned long	t;
	long double a = 18.464645;
	long double a_ = -18.464645;
	if (argc != 2)
		t = 0x7fff5875ca4c;
	/*else
		t = atol(argv[1]);*/
	//char *str = "aa";
	ft_printf("{%L.*.4f}\n", 10, a);
	printf("{%L.*.4f}\n", 10,a);
	ft_printf("{%L.*.4f}\n",10, a_);
	printf("{%L.*.4f}\n",10, a_);
	// ft_printf("ft_printf: \e[1;34m[%lx]\e[0m\n", t);
	// printf("printf :   [%lx]\n", t);
	// printf("----------\n");
	// ft_printf("ft_printf: [%lo]\n", t);
	// printf("printf :   [%lo]\n", t);
	// printf("----------\n");
	// ft_printf("ft_printf: [%#lx]\n", t);
	// printf("printf :   [%#lx]\n", t);
	// printf("----------\n");
	// ft_printf("ft_printf: [%#lo]\n", t);
	// printf("printf :   [%#lo]\n", t);
	// printf("----------\n");
	// ft_printf("ft_printf: [%-20lX]\n", t);
	// printf("printf :   [%-20lX]\n", t);
	// printf("----------\n");
	// ft_printf("ft_printf: [%%]\n");
	// printf("printf:    [%%]\n");
	// printf("----------\n");
	// ft_printf("ft_printf: [%s]\n", "cheveux");
	// printf("printf :   [%s]\n", "cheveux");
	// printf("----------\n");
	// ft_printf("ft_printf: [%.5s]\n", "cheveux");
	// printf("printf :   [%.5s]\n", "cheveux");
	// printf("----------\n");
	// ft_printf("ft_printf: [%p]\n", &t);
	// printf("printf :   [%p]\n", &t);
	// printf("----------\n");
	// setlocale(LC_ALL, "");
	// ft_printf("ft_printf: [%15C]\n", 65537);
	// printf("printf :   [%15C]\n", 65537);
	// printf("----------\n");
	// ft_printf("ft_printf: [%ls]\n", L"މތ");
	// printf("printf :   [%ls]\n", L"މތ");
	// printf("----------\n");
	// ft_printf("ft_printf: salut [%#.o]\n", 0);
	// printf("printf :   salut [%#.o]\n", 0);
	// printf("----------\n");
	// char c;
	// ft_printf("ft_printf: [%s %d %p %% %S %i %o %O %u %x %X %c %C]\n","bonjour", 42, &c, L"暖炉", 42, 42, 42, 100000,  42, 42, 'c', L'플');
	// printf("printf :   [%s %d %p %% %S %i %o %O %u %x %X %c %C]\n","bonjour", 42, &c, L"暖炉",  42, 42, 42, 100000, 42, 42, 'c', L'플');
	// printf("----------\n");
	// ft_printf("ft_printf: [%ld]\n", LONG_MAX);
	// printf("printf :   [%ld]\n", LONG_MAX);
	// printf("----------\n");
	//ft_printf("ft_printf: [%hhS, %hhS]\n", 0, L"米米");
	//printf("printf :   [%hhS, %hhS]\n", 0, L"米米");
	//ft_printf("%d\n", printf("%S\n", NULL));
	//FAIRE CES TROIS TESTS POUR MONTRER LA DEBILITE D ESSAYER DE GERER DES CAS
	//INDETERMINES
	//printf("{%10Rsalut}\n");
	//printf("{%10qwerty}\n");
	//printf("{%10qsalut}\n");
	//ft_printf("{%10Rsalut}\n");
	// //ft_printf("{%#.O}\n", 0);
	// ft_printf("%#.4O\n", 1);
	// printf("%#.4O\n", 1);
	//printf("{%05.c}", 0);
	return (0);
}
// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>
//
// int main (void)
// {
// 	//double num = 9.146555553;
// 	//unsigned long u_max= 8446744073709551615;
// //ft_printf("%.4f\n", num);
// //printf("%.4f\n", num);
// 	//printf("%5%");
// 	int i;
// 	int j;
// //	int x = 10000;
// 	//size_t u = 5;
// 	//char t = 2345;
// 	int d = 14356;
// 	char *str;
// 	str =NULL;
// 	//ft_utoa_base(ULONG_MAX, 10, 0);
// 	//printf("%s\n", ft_itoa_base(u_max, 10, 0));
// 	//ft_printf("%#x\n", 0);
// 	i = 0;
// 	// i = ft_printf("%*.*d\n", 0, 3, 0);
// 	// j = printf("%*.*d\n", 0, 3, 0);
// 	i = ft_printf("%s\n", str);
// 	j = printf("%s\n", str);
// 	//ft_printf("%#o\n", 0);
// 	//printf("%#o\n", 0);
// 	//ft_printf("%.#x\n", 0);
// 	//printf("%.#x\n", 0);
// 	printf("valeur de retour de mon ptf: %d\n", i);
// 	printf("valeur de retour du printf stdio: %d\n", j);
// 	//-fsanitize=address
//
// 	// i = ft_printf("a%ob%oc%od\n",0, 55555, 100000);
// 	// j = printf("a%ob%oc%od\n", 0, 55555, 100000);
// 	// ft_printf("%o%o%o%o%o\n",1, 100, 999, 42, 999988888);
// 	// ft_printf("before %o after\n", 42);
// 	// printf("before %o after\n", 42);
// 	// printf("%o%o%o%o%o\n",1, 100, 999, 42, 999988888);
//
// 	//printf("string: |%%%%%%|\n");
// 	//ft_printf("string: |%%%%%%|\n");
// 	/*char *str_ = "|%+0.1f|\n";
// 	double n = 3.944545454;
// 	double n_ = -3.944545454;
// 	printf(str_, n);
// 	ft_printf(str_, n);
// 	printf(str_, n_);
// 	ft_printf(str_, n_);
// 	ft_putchar('\n');
// 	char *str = "|%+0.1d|\n";
// 	long long int nb = 96529;
// 	long long nb_ = 96529;
// 	printf(str, nb);
// 	ft_printf(str, nb);
// 	printf(str, nb_);
// 	ft_printf(str, nb_);*/
//
//
//
//
//
// 	//printf("%10s is a string", "this");
//
//
//
// }
//
// /*long double    ft_round(long double fl, long precision)
// {
//     long double    diviseur;
//
//     diviseur = 5;
//     if (!precision)
//         return (fl + (fl > 0.0 ? 0.5 : -0.5));
//     while (precision-- >= 0)
//         diviseur /= 10;
//     return (fl + (fl > 0.0 ? diviseur : -diviseur));
// }
//
// 9.1465
// +
// 0.0005
// */
