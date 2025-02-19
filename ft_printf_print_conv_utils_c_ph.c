/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_c_ph.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:42:59 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/19 23:45:36 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FLAG '0' is ignored when flag '-' is present
**	FLAG ' ' is ignored when flag '+' is present
**
**	Conversion specifier 'c':
**		flag '0' results in undefined behavior with 'c'
**		flag '+' results in undefined behavior with 'c'
**		flag '#' results in undefined behavior with 'c'
**		flag ' ' results in undefined behavior with 'c'
**		precision used with 'c', resulting in undefined behavior
**
**	Conversion specifier PH:
**		The complete conversion specification shall be PHPH.
**		This implementation of printf writes PH following
**		the specification of the specifier 'c'
*/

#include "ft_printf.h"

void	print_conv_c(t_fields *flds, va_list ap)
{
	char	c;
	char	fill;

	fill = SPACE;
	if (flds->zero > 0)
		fill = ZERO;
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

	fill = SPACE;
	if (flds->zero > 0)
		fill = ZERO;
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
