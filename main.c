/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:19:36 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/08 06:58:41 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "includes/ft_printf.h"
#include <limits.h>
#include <locale.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	unsigned long	t;

	if (argc != 2)
		t = 0x7fff5875ca4c;
	/*else
		t = atol(argv[1]);*/
	printf("ft_printf: \e[1;34m[%lx]\e[0m\n", t);

	printf("ft_printf: [%lo]\n", t);
	printf("ft_printf: [%#lx]\n", t);
	printf("ft_printf: [%#lo]\n", t);
	printf("ft_printf: [%-20lX]\n", t);
	printf("ft_printf: [%%]\n");
	printf("ft_printf: [%s]\n", "cheveux");
	printf("ft_printf: [%.5s]\n", "cheveux");
	printf("ft_printf: [%p]\n", &t);
		ft_printf("ft_printf: [%p]\n", &t);

	printf("ft_printf: salut [%#.o]\n", 0);
	char c;
	printf("ft_printf: [%s %d %p %% %i %o %O %u %x %X %c]\n","bonjour", 42, &c, 42, 42, 42, 100000,  42, 42, 'c');
	ft_printf("ft_printf: [%s %d %p %% %i %o %O %u %x %X %c]\n","bonjour", 42, &c, 42, 42, 42, 100000,  42, 42, 'c');
	printf("ft_printf: [%ld]\n", LONG_MAX);
	//ft_printf("ft_printf: [%hhS, %hhS]\n", 0, L"米米");
	//printf("printf :   [%hhS, %hhS]\n", 0, L"米米");
	//ft_printf("%d\n", printf("%S\n", NULL));
	//FAIRE CES TROIS TESTS POUR MONTRER LA DEBILITE D ESSAYER DE GERER DES CAS
	//INDETERMINES
	//printf("{%10Rsalut}\n");
	//printf("{%10qwerty}\n");
	//printf("{%10qsalut}\n");
	//ft_printf("{%10Rsalut}\n");
	//ft_printf("{%#.O}\n", 0);
	printf("%#.4O\n", 1);
	//printf("{%05.c}", 0);
	return (0);
}
