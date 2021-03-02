/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:53:54 by edi-marc          #+#    #+#             */
/*   Updated: 2021/03/02 18:24:49 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include "limits.h"

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
	
	magenta();
	printf("\n---- TESTING c ----\n");
	reset();

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

	origin = printf("Hell%.*c_Wor%.0cd", -1, 'o', 'l');
	printf("\n");
	ft = ft_printf("Hell%.*c_Wor%.0cd", -1, 'o', 'l');
	check_printf(ft, origin);
	
	origin = printf("[%5c]_[%-0c]" , NULL , "");
	printf("\n");
	ft = ft_printf("[%5c]_[%-0c]" , NULL , "");
	check_printf(ft, origin);

	magenta();
	printf("\n---- TESTING placeholder ----\n");
	reset();

	origin = printf("%-%%-0%%0%%-5%%5%%000%%-0.1%%-02%%-3%");
	printf("\n");
	ft = ft_printf("%-%%-0%%0%%-5%%5%%000%%-0.1%%-02%%-3%");
	check_printf(ft, origin);
	
	origin = printf("%-%");
	printf("\n");
	ft = ft_printf("%-%");
	check_printf(ft, origin);
	
	origin = printf("%005%_%.c", '1');
	printf("\n");
	ft = ft_printf("%005%_%.c", '1');
	check_printf(ft, origin);
	
	magenta();
	printf("\n---- TESTING s ----\n");
	reset();

	origin = printf("[%-8.5s]_%s" , NULL, "Hello_World");
	printf("\n");
	ft = ft_printf("[%-8.5s]_%s", NULL, "Hello_World");
	check_printf(ft, origin);
	
	origin = printf("[%0-6s][%4c][%.s]", "Hello", '\32', "World");
	printf("\n");
	ft = ft_printf("[%0-6s][%4c][%.s]", "Hello", '\32', "World");
	check_printf(ft, origin);

	origin = printf("[%05.1s][%-4c][%-.3s]", "Hello", '\32', "World");
	printf("\n");
	ft = ft_printf("[%05.1s][%-4c][%-.3s]", "Hello", '\32', "World");
	check_printf(ft, origin);
	
	origin = printf("[%3.7s]_[%7.7s]" , "Hello" , "World");
	printf("\n");
	ft = ft_printf("[%3.7s]_[%7.7s]", "Hello" , "World");
	check_printf(ft, origin);

	magenta();
	printf("\n---- TESTING i / d ----\n");
	reset();

	origin = printf("[%-5i]_[%-0i]" , 1 , 2);
	printf("\n");
	ft = ft_printf("[%-5i]_[%-0i]" , 1 , 2);
	check_printf(ft, origin);

	origin = printf("[%-i]_[%-i]" , NULL , 0);
	printf("\n");
	ft = ft_printf("[%-i]_[%-i]" , NULL , 0);
	check_printf(ft, origin);

	//	Workaround for INT_MIN considering int as 4 bytes
	origin = printf("[%-015i]_[%-020.15i]" ,-1 - 2147483647, INT_MAX);
	printf("\n");
	ft = ft_printf("[%-015i]_[%-020.15i]" ,-1 - 2147483647, INT_MAX);
	check_printf(ft, origin);
	
	origin = printf("[%06i]_[%06.d]_[%10i]_[%05.i]" , 42 , 2, 0, 0);
	printf("\n");
	ft = ft_printf("[%06i]_[%06.d]_[%10i]_[%05.i]" , 42 , 2, 0, 0);
	check_printf(ft, origin);
	
	origin = printf("[%-04.3i]_[%-4.5i]_[%07d]_[%07.d]_[%7.2i]" , -2 , -42, -155, -155, -155);
	printf("\n");
	ft = ft_printf("[%-04.3i]_[%-4.5i]_[%07d]_[%07.d]_[%7.2i]" , -2 , -42, -155, -155, -155);
	check_printf(ft, origin);
	
	origin = printf("[%0.0i]_[%1.0i]_[%d]" , 42, 42, 0);
	printf("\n");
	ft = ft_printf("[%0.0i]_[%1.0i]_[%d]" , 42, 42, 0);
	check_printf(ft, origin);
	
	origin = printf("[%*.*i]_[%*.*i]_[%*d]" , -2, 0, 42, 2, 3, 42, 0, 0);
	printf("\n");
	ft = ft_printf("[%*.*i]_[%*.*i]_[%*d]" , -2, 0, 42, 2, 3, 42, 0, 0);
	check_printf(ft, origin);
	
	magenta();
	printf("\n---- TESTING u ----\n");
	reset();

	origin = printf("[%-5u]_[%-0u]" , 1 , 2);
	printf("\n");
	ft = ft_printf("[%-5u]_[%-0u]" , 1 , 2);
	check_printf(ft, origin);

	origin = printf("[%-u]_[%-u]" , NULL , 0);
	printf("\n");
	ft = ft_printf("[%-u]_[%-u]" , NULL , 0);
	check_printf(ft, origin);

	//	Workaround for INT_MIN considering int as 4 bytes
	origin = printf("[%-015u]_[%-020.15u]_[%u]_[%u]-[%u]" ,-1 - 2147483647, INT_MAX, INT_MAX + 1, INT_MIN - 1, -1);
	printf("\n");
	ft = ft_printf("[%-015u]_[%-020.15u]_[%u]_[%u]_[%u]" ,-1 - 2147483647, INT_MAX, INT_MAX + 1, INT_MIN - 1, -1);
	check_printf(ft, origin);
	
	origin = printf("[%06u]_[%06.u]_[%10u]_[%05.u]" , 42 , 2, 0, 0);
	printf("\n");
	ft = ft_printf("[%06u]_[%06.u]_[%10u]_[%05.u]" , 42 , 2, 0, 0);
	check_printf(ft, origin);
	
	origin = printf("[%-04.3u]_[%-4.5u]_[%07u]_[%07.u]_[%7.2u]" , -2 , -42, -155, -155, -155);
	printf("\n");
	ft = ft_printf("[%-04.3u]_[%-4.5u]_[%07u]_[%07.u]_[%7.2u]" , -2 , -42, -155, -155, -155);
	check_printf(ft, origin);
	
	origin = printf("[%0.0u]_[%1.0u]_[%u]" , 42, 42, 0);
	printf("\n");
	ft = ft_printf("[%0.0u]_[%1.0u]_[%u]" , 42, 42, 0);
	check_printf(ft, origin);
	
	origin = printf("[%*.*u]_[%*.*u]_[%*u]" , -2, 0, 42, 2, 3, 42, 0, 0);
	printf("\n");
	ft = ft_printf("[%*.*u]_[%*.*u]_[%*u]" , -2, 0, 42, 2, 3, 42, 0, 0);
	check_printf(ft, origin);
	
	origin = printf("[%*.*u]_[%*.*u]_[%*u]" , -2, 0, UINT_MAX, 2, 3, UINT_MAX + 1, 0, 0);
	printf("\n");
	ft = ft_printf("[%*.*u]_[%*.*u]_[%*u]" , -2, 0, UINT_MAX, 2, 3, UINT_MAX + 1, 0, 0);
	check_printf(ft, origin);

	return (0);
}
