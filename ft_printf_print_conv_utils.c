/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:10:32 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/27 19:48:11 by edi-marc         ###   ########.fr       */
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
**
**	Conversion specifier PH:
**		The complete conversion specification shall be PHPH.
**		This implementation of printf writes PH following
**		the specification of the specifier 'c'
**
**	Conversion specifier 's':
**		flag '0' results in undefined behavior with 'c'
**		flag '+' results in undefined behavior with 'c'
**		flag '#' results in undefined behavior with 'c'
**		flag ' ' results in undefined behavior with 'c'
*/

#include "libftprintf.h"

void		print_conv_c(t_fields *flds, va_list ap)
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

void		print_conv_ph(t_fields *flds)
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

void		print_conv_s(t_fields *flds, va_list ap)
{
	char	*s;
	char	fill;
	int		str_l;

	str_l = ft_strlen(s);
	fill = flds->zero > 0 ? ZERO : SPACE;
	s = (s = va_arg(ap, char *)) ? s : STR_N;
	str_l = str_l > flds->dot ? str_l : flds->dot;
	if (flds->minus > 0)
	{
		while (*s++ && str_l-- > 0)
			putchar_ftprintf(*s, flds);
		while (flds->width - str_l > 0)
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
