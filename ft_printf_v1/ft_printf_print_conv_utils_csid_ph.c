/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_csid_ph.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:50:05 by edi-marc          #+#    #+#             */
/*   Updated: 2021/03/04 18:50:12 by edi-marc         ###   ########.fr       */
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
**
**	Conversion specifier 's':
**		flag '0' results in undefined behavior with 'c'
**		flag '+' results in undefined behavior with 'c'
**		flag '#' results in undefined behavior with 'c'
**		flag ' ' results in undefined behavior with 'c'
**
**	Conversion specifier 'i'/'d':
**		flag '#' results in undefined behavior with 'i'/'d'
**		if a precision is specified, the 0 flag is ignored
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
	size_t	max_s;

	fill = flds->zero > 0 ? ZERO : SPACE;
	if (!(s = va_arg(ap, char *)))
		s = STR_N;
	if ((size_t)flds->dot < (max_s = ft_strlen(s)) && flds->dot > -1)
		max_s = flds->dot;
	flds->width = max_s < (size_t)flds->width ? flds->width - max_s : 0;
	if (flds->minus > 0)
	{
		while (max_s-- > 0)
			putchar_ftprintf(*s++, flds);
		while (flds->width-- > 0)
			putchar_ftprintf(SPACE, flds);
	}
	else
	{
		while (flds->width-- > 0)
			putchar_ftprintf(fill, flds);
		while (max_s-- > 0)
			putchar_ftprintf(*s++, flds);
	}
}

static void	print_conv_i_utils(t_fields *flds, char *n, char fill)
{
	if (flds->minus > 0)
	{
		if (*n == MINUS)
			putchar_ftprintf(*n++, flds);
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
		while (flds->width-- > 0)
			putchar_ftprintf(SPACE, flds);
	}
	else
	{
		if (*n == MINUS && fill == ZERO)
			putchar_ftprintf(*n++, flds);
		while (flds->width-- > 0)
			putchar_ftprintf(fill, flds);
		if (*n == MINUS)
			putchar_ftprintf(*n++, flds);
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
	}
}

void		print_conv_i(t_fields *flds, va_list ap)
{
	char	*n;
	char	fill;
	size_t	max_s;
	size_t	n_dgt;

	if (!(n = ft_itoa(va_arg(ap, int))))
		flds->printed = ERR;
	else
	{
		if (*n == '0' && !(*(n + 1)) && flds->dot == 0)
			*n = '\0';
		fill = flds->zero > 0 && !(flds->dot > -1) ? ZERO : SPACE;
		max_s = ft_strlen(n);
		n_dgt = *n == MINUS && ft_isdigit(*(n + 1)) ? max_s - 1 : max_s;
		flds->dot = flds->dot > -1 && (size_t)(flds->dot) > n_dgt ?
			flds->dot - n_dgt : 0;
		flds->width = (size_t)flds->width > (max_s + flds->dot) ?
			flds->width - (max_s + flds->dot) : 0;
		print_conv_i_utils(flds, n, fill);
		free(n);
	}
}
