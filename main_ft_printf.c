/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:53:54 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/19 18:19:37 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	check_printf(int ft, int origin)
{
	if (origin == ft)
		printf("result = [OK]\n");
	else
		printf("result = [KO] -- ft=%d - original=%d\n", ft, origin);
}

int		main(void)
{
	int	ft;
	int	origin;

	origin = printf("ciao%%%%%%%%");
	printf("\n");
	ft = 0;
	check_printf(ft, origin);
	return (0);
}
