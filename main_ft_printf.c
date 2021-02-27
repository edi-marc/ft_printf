/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:53:54 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/27 13:32:42 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

void	red(void)
{
	printf("\033[0;31m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	magenta(void)
{
	printf("\033[0;35m");
}

void	reset(void)
{
	printf("\033[0m");
}

void	check_printf(int ft, int origin)
{
	printf("\n");
	if (origin == ft)
	{
		green();
		printf("result = [OK]\n");
		reset();
	}
	else
	{
		red();
		printf("result = [KO] -- ft=%d - original=%d\n", ft, origin);
		reset();
	}
}

int		main(void)
{
	int	ft;
	int	origin;

	magenta();
	printf("\n---- TEST START ----\n");
	reset();

	origin = printf("");
	printf("\n");
	ft = ft_printf("");
	check_printf(ft, origin);

	origin = printf("😁🤯_OK");
	printf("\n");
	ft = ft_printf("😁🤯_OK");
	check_printf(ft, origin);

	origin = printf("c\0iao");
	printf("\n");
	ft = ft_printf("c\0iao");
	check_printf(ft, origin);

	origin = printf("\"");
	printf("\n");
	ft = ft_printf("\"");
	check_printf(ft, origin);

	origin = printf("H");
	printf("\n");
	ft = ft_printf("H");
	check_printf(ft, origin);

	origin = printf("Hello_world");
	printf("\n");
	ft = ft_printf("Hello_world");
	check_printf(ft, origin);

	origin = printf("\x43\x69\x61\x6f");
	printf("\n");
	ft = ft_printf("\x43\x69\x61\x6f");
	check_printf(ft, origin);

	origin = printf("\n\t\v\f\r");
	printf("\n");
	ft = ft_printf("\n\t\v\f\r");
	check_printf(ft, origin);

	// Not printable character
	origin = printf("\x7f");
	printf("\n");
	ft = ft_printf("\x7f");
	check_printf(ft, origin);
	
	origin = printf("cia%c", 'o');
	printf("\n");
	ft = ft_printf("cia%c", 'o');
	check_printf(ft, origin);
	
	origin = printf("Hell%c_Wo%cld", 'o', 'r');
	printf("\n");
	ft = ft_printf("Hell%c_Wo%cld", 'o', 'r');
	check_printf(ft, origin);

	int chr = -1;
	unsigned char i = -1;
	origin = printf("%c", i);
	printf("\n");
	ft = ft_printf("%c", i);
	check_printf(ft, origin);
	
	origin = printf("-*#15%c", '%');
	printf("\n");
	ft = ft_printf("-*#15%c", '%');
	check_printf(ft, origin);
	
	origin = printf("cia%c%c", NULL, '\x6f');
	printf("\n");
	ft = ft_printf("cia%c%c", NULL, '\x6f');
	check_printf(ft, origin);

	origin = printf("Hell%00c_Worl%5c", 'o', 'd');
	printf("\n");
	ft = ft_printf("Hell%00c_Worl%5c", 'o', 'd');
	check_printf(ft, origin);

	origin = printf("Hell%-5c_Worl%-5c_", NULL, 'd');
	printf("\n");
	ft = ft_printf("Hell%-5c_Worl%-5c_", NULL, 'd');
	check_printf(ft, origin);

	origin = printf("Hell%05c_Worl%-05c", 'o', 'd');
	printf("\n");
	ft = ft_printf("Hell%05c_Worl%-05c", 'o', 'd');
	check_printf(ft, origin);

	origin = printf("Hell%-1c_Worl%-c", 'o', 'd');
	printf("\n");
	ft = ft_printf("Hell%-1c_Worl%-c", 'o', 'd');
	check_printf(ft, origin);

	origin = printf("[Hell%*c_Worl%*c]", 12, 'o' , -6, 'd');
	printf("\n");
	ft = ft_printf("[Hell%*c_Worl%*c]", 12, 'o' , -6, 'd');
	check_printf(ft, origin);
	
	origin = printf("[Hell%---000*c_Worl%-0*c]", 12, 'o' , -6, 'd');
	printf("\n");
	ft = ft_printf("[Hell%---000*c_Worl%-0*c]", 12, 'o' , -6, 'd');
	check_printf(ft, origin);
	
	return (0);
}
