/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:19:36 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/10 03:44:50 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include <stdio.h>
	#include "ft_printf.h"
	#include <limits.h>
	#include <locale.h>

	#include <stdio.h>
	#include <limits.h>

	int        main()
	{
	   int x;
	    int y;
	    int z;
	    int m;
	    int n;
	    int p;
	    x = 0;
	    y = 1;
	    z = 2;
	    p = ((16 * 16 * 16 * 16 * 16 * 16) + 1);
	    m = 1000000;
	    n = LONG_MAX;

	    printf("\e[1;31m----- Basic ----\n\n");
	    ft_printf("ici bonjour");

	//    printf("\e[1;31m----- Very Difficult ----\n\n");


	    printf("\e[1;35m\n\n----- Difficult ----\n\n");
	    ft_printf("#1 %ll# +++-+-- h00012.3.5.28d\n", 42);
	    printf("#1 %ll# +++-+-- h00012.3.5.28d\n", 42);
	    ft_printf("#2 %d %d %d\n", 542);
	    printf("#2 %d %d %d\n", 542);
	    ft_printf("#3 %+-d\n", 542);
	    printf("#3 %+-d\n", 542);
	    ft_printf("#4 %00.0d\n", 542);
	    printf("#4 %00.0d\n", 542);
	    ft_printf("#5 %00.00d\n", 542);
	    printf("#5 %00.00d\n", 542);
	    ft_printf("#6 %%%%%d\n", 542);
	    printf("#6 %%%%%d\n", 542);
	    ft_printf("#7 %hld\n", INT_MAX);
	    printf("#7 %hld\n", INT_MAX);
	    ft_printf("#8 %lhd\n", INT_MAX);
	    printf("#8 %lhd\n", INT_MAX);
	    ft_printf("#9 %+10d\n", 42);
	    printf("#9 %+10d\n", 42);
	    ft_printf("#10 %++0d\n", 542);
	    printf("#10 %++0d\n", 542);
	    printf("\e[1;34m\n\n----- Medium ----\n\n");
	    ft_printf("#11 %ld\n", n);
	    printf("#11 %ld\n", n);
	    ft_printf("#12 %lhd\n", m);
	    printf("#12 %lhd\n", m);
	    ft_printf("#13 %hld\n", m);
	    printf("#13 %hld\n", m);
	    ft_printf("#14 %lhd\n", n);
	    printf("#14 %lhd\n", n);
	    ft_printf("#15 %hld\n", n);
	    printf("#15 %hld\n", n);
	    ft_printf("#16 %+2.2p\n", z);
	    printf("#16 %+2.2p\n", z);
	    ft_printf("#17 %+2.0p\n", p);
	    printf("#17 %+2.0p\n", p);
	    ft_printf("#18 %+0.0p\n", p);
	    printf("#18 %+0.0p\n", p);
	    printf("\e[1;36m\n\n----- Easy ----\n\n");
	    ft_printf("#19 %.3d\n", z);
	    printf("#19 %.3d\n", z);
	    ft_printf("#20 %#o\n", z);
	    printf("#20 %#o\n", z);
	    ft_printf("#21 %o\n", z);
	    printf("#21 %o\n", z);
	    ft_printf("#22 %0+3d\n", z);
	    printf("#22 %0+3d\n", z);
	    ft_printf("#23 abc%%%0+3d\n", z);
	    printf("#23 abc%%%0+3d\n", z);
	    ft_printf("#24 %.3d\n", z);
	    printf("#24 %.3d\n", z);
	    ft_printf("#25 hello\n", x, y, z);
	    printf("#25 hello\n", x, y, z);
	    ft_printf("#26 %d\n", x, y, z);
	    printf("#26 %d\n", x, y, z);
	    ft_printf("#27 %s\n", x, y, z);
	    printf("#27 %s\n", x, y, z);
	    ft_printf("#28 %%\n");
	    printf("#28 %%\n");
	    ft_printf("#29 %%d%\n", x, y, z);
	    printf("#29 %%d%\n", x, y, z);
	    ft_printf("#30 %y\n", x, y, z);
	    printf("#30 %y\n", x, y, z);
	    ft_printf("#31 %%%d\n", x, y, z);
	    printf("#31 %%%d\n", x, y, z);
	    return (0); 
	}
