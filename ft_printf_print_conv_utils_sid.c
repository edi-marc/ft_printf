/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_sid.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:36:06 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/19 23:46:35 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**      FLAG '0' is ignored when flag '-' is present
**      FLAG ' ' is ignored when flag '+' is present
**
**      Conversion specifier 's':
**              flag '0' results in undefined behavior with 'c'
**              flag '+' results in undefined behavior with 'c'
**              flag '#' results in undefined behavior with 'c'
**              flag ' ' results in undefined behavior with 'c'
**
**      Conversion specifier 'i'/'d':
**              flag '#' results in undefined behavior with 'i'/'d'
**              if a precision is specified, the 0 flag is ignored
*/

#include "ft_printf.h"

static void	print_conv_s_2(t_fields *flds, size_t max_s, char *s, char fill)
{
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

void	print_conv_s(t_fields *flds, va_list ap)
{
	char	*s;
	char	fill;
	size_t	max_s;

	fill = SPACE;
	if (flds->zero > 0)
		fill = ZERO;
	s = va_arg(ap, char *);
	if (!s)
		s = STR_N;
	max_s = ft_strlen(s);
	if ((size_t)flds->dot < max_s && flds->dot > -1)
		max_s = flds->dot;
	flds->width = 0;
	if (max_s < (size_t)flds->width)
		flds->width = flds->width - max_s;
	print_conv_s_2(flds, max_s, s, fill);
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

static char	print_conv_i_2(char *n, t_fields *flds, char fill)
{
	size_t	max_s;
	size_t	n_dgt;

	if (*n == '0' && !(*(n + 1)) && flds->dot == 0)
		*n = '\0';
	fill = SPACE;
	if (flds->zero > 0 && !(flds->dot > -1))
		fill = ZERO;
	max_s = ft_strlen(n);
	n_dgt = max_s;
	if (*n == MINUS && ft_isdigit(*(n + 1)))
		n_dgt = max_s - 1;
	flds->dot = 0;
	if (flds->dot > -1 && (size_t)(flds->dot) > n_dgt)
		flds->dot = flds->dot - n_dgt;
	flds->width = 0;
	if ((size_t)flds->width > (max_s + flds->dot))
		flds->width = (flds->width - (max_s + flds->dot));
	return (fill);
}

void	print_conv_i(t_fields *flds, va_list ap)
{
	char	*n;
	char	fill;

	fill = SPACE;
	n = ft_itoa(va_arg(ap, int));
	if (!n)
		flds->printed = ERR;
	else
	{
		fill = print_conv_i_2(n, flds, fill);
		print_conv_i_utils(flds, n, fill);
		free(n);
	}
}
