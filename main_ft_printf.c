/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:53:54 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/21 18:31:23 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	red(void)
{
	printf("\033[0;31m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	check_printf(int ft, int origin)
{
	printf("\n");
	if (origin == ft)
	{
		green();
		printf("result = [OK]\n");
	}
	else
	{
		red();
		printf("result = [KO] -- ft=%d - original=%d\n", ft, origin);
	}
}

int		main(void)
{
	int	ft;
	int	origin;

	origin = printf("ciao");
	printf("\n");
	ft = 4;
	check_printf(ft, origin);
	return (0);
}
