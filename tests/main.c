/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:19:36 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/09 03:59:49 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "includes/ft_printf.h"
#include <limits.h>
#include <locale.h>
#include "ft_printf.h"

void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

void	sp_putchar(unsigned char const *ptr)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t a;
	unsigned char const *ptr = addr;

	i = 0;
	while (i < size)
	{
		a = 0;
		while (a < 16 && a + i < size)
		{
			ft_putnbr_hex(*(ptr + i + a), 2);
			if (a % 2)
				write(1, " ", 1);
			a++;
		}
		while (a < 16)
		{
			write(1, "  ", 2);
			if (a % 2)
				write(1, " ", 1);
			a++;
		}
		a = 0;
		while (a < 16 && a + i < size)
		{
			sp_putchar(ptr + a + i);
			a++;
		}
		write(1, "\n", 1);
		i += 16;
	}
}

int		main(int argc, char **argv)
{
	unsigned long	t;

	if (argc != 2)
		t = 0x7fff5875ca4c;
	int	tab[10] = {82, 23, 150, 255,
	              10, 11259375,  21, 65};

	print_memory(tab, sizeof(tab));
// 	double d = 10.0;
// 	char *string = "|%020p|\n";
// int n =  110;
// int n_ = -3;
// ft_printf(string,  n);
// printf(string, n);
// ft_printf(string,  n_);
// printf(string,  n_);
	/*els
		t = atol(argv[1]);*/
	// 	double d = 11.5456456456;
	// //  ft_printf("ft_printf: [%10.0f]\n", d);
	// //  printf("   printf: [%10.0f]\n", d);
	// //  ft_printf("ft_printf: [%.50f]\n", d);
	// // printf("   printf: [%.50f]\n", d);
	// ft_printf("ft_printf: [%10f]\n", -0.5);
    // printf("   printf: [%10f]\n", -0.5);
   //  ft_printf("ft_printf: [%.50f]\n", 10.5);
   // printf("   printf: [%.50f]\n", 10.5);


	// int n = 1100;

	// int n = 1100;
	// int n_ = -1100;
	// ft_printf("%-+#15o\n", n);
	// printf("%-+#15o\n", n);
	// ft_printf("%-+#15o\n", n_);
	// printf("%-+#15o\n", n_);
	// char *string = "|%-#15.10x|%-#15.10X|%-#15.10u|%-#15.10o|%-+1#5.10p|%-15.10P|\n";
    // int n =  110;
    // int n_ = -3;
    // ft_printf(string, n, n, n, n, n, n);
    // printf(string, n, n, n, n, n, n);
    // ft_printf(string, n_,n_, n_, n_, n_, n_);
    // printf(string, n_,n_,n_, n_, n_, n_);
	// printf("ft_printf: \e[1;34m[%lx]\e[0m\n", t);
	//
	// printf("ft_printf: [%lo]\n", t);
	// printf("ft_printf: [%#lx]\n", t);
	// printf("ft_printf: [%#lo]\n", t);
	// printf("ft_printf: [%-20lX]\n", t);
	// printf("ft_printf: [%%]\n");
	// printf("ft_printf: [%s]\n", "cheveux");
	// printf("ft_printf: [%.5s]\n", "cheveux");
	// printf("ft_printf: [%p]\n", &t);
	// 	ft_printf("ft_printf: [%p]\n", &t);
	//
	// printf("ft_printf: salut [%#.o]\n", 0);
	// char c;
	// printf("ft_printf: [%s %d %p %% %i %o %O %u %x %X %c]\n","bonjour", 42, &c, 42, 42, 42, 100000,  42, 42, 'c');
	// ft_printf("ft_printf: [%s %d %p %% %i %o %O %u %x %X %c]\n","bonjour", 42, &c, 42, 42, 42, 100000,  42, 42, 'c');
	// printf("ft_printf: [%ld]\n", LONG_MAX);
	// //ft_printf("ft_printf: [%hhS, %hhS]\n", 0, L"米米");
	// //printf("printf :   [%hhS, %hhS]\n", 0, L"米米");
	// //ft_printf("%d\n", printf("%S\n", NULL));
	// //FAIRE CES TROIS TESTS POUR MONTRER LA DEBILITE D ESSAYER DE GERER DES CAS
	// //INDETERMINES
	// //printf("{%10Rsalut}\n");
	// //printf("{%10qwerty}\n");
	// //printf("{%10qsalut}\n");
	// //ft_printf("{%10Rsalut}\n");
	// //ft_printf("{%#.O}\n", 0);
	// //printf("%#.4O\n", 1);
	// //printf("{%05.c}", 0);
	return (0);
}
