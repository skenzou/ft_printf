/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:19:36 by midrissi          #+#    #+#             */
/*   Updated: 2019/02/10 04:02:31 by midrissi         ###   ########.fr       */
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
		float d= -0.5;
		printf("{%-15.f}\n", d);
		ft_printf("{%-15.f}\n", d);
	}
