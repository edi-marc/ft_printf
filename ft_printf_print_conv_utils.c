/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:10:32 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/27 15:17:39 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FLAG '0' is ignored when flag '-' is present
**
**	Conversion specifier 'c':
**		flag '0' results in undefined behavior with 'c'
**		flag '+' results in undefined behavior with 'c'
**		flag '#' results in undefined behavior with 'c'
**		flag ' ' results in undefined behavior with 'c'
**		precision used with 'c', resulting in undefined behavior
*/

#include "libftprintf.h"

void	print_conv_c(t_fields *flds, va_list ap)
{
	char	c;
	char	fill;

	fill = flds->zero > 0 ? ZERO : SPACE;
	c = va_arg(ap, int);
	if (flds->minus > 0)
	{
		putchar_ftprintf(c, flds);
		while (flds->width - 1 > 0)
		{
			putchar_ftprintf(SPACE, flds);
			(flds->width)--;
		}
	}
	else
	{
		while (flds->width - 1 > 0)
		{
			putchar_ftprintf(fill, flds);
			(flds->width)--;
		}
		putchar_ftprintf(c, flds);
	}
}

void	print_conv_ph(t_fields *flds)
{
	char	fill;

	fill = flds->zero > 0 ? ZERO : SPACE;
	if (flds->minus > 0)
	{
		putchar_ftprintf(PH, flds);
		while (flds->width - 1 > 0)
		{
			putchar_ftprintf(SPACE, flds);
			(flds->width)--;
		}
	}
	else
	{
		while (flds->width - 1 > 0)
		{
			putchar_ftprintf(fill, flds);
			(flds->width)--;
		}
		putchar_ftprintf(PH, flds);
	}
}
