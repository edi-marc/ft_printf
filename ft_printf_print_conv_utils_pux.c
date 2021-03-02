/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_pux.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:49:50 by edi-marc          #+#    #+#             */
/*   Updated: 2021/03/02 19:59:35 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FLAG '0' is ignored when flag '-' is present
**	FLAG ' ' is ignored when flag '+' is present
**
**	Conversion specifier 'u':
**		flag '#' results in undefined behavior with 'u'
**		flag '+' results in undefined behavior with 'u'
**		flag ' ' results in undefined behavior with 'u'
**		if a precision is specified, the 0 flag is ignored
*/

#include "libftprintf.h"

static void	print_conv_u_utils(t_fields *flds, char *n, char fill)
{
	if (flds->minus > 0)
	{
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
		while (flds->width-- > 0)
			putchar_ftprintf(SPACE, flds);
	}
	else
	{
		while (flds->width-- > 0)
			putchar_ftprintf(fill, flds);
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
	}
}

void		print_conv_u(t_fields *flds, va_list ap)
{
	char	*n;
	char	fill;
	size_t	n_dgt;

	if (!(n = ft_iutoa(va_arg(ap, unsigned int))))
		flds->printed = ERR;
	else
	{
		if (*n == '0' && !(*(n + 1)) && flds->dot == 0)
			*n = '\0';
		fill = flds->zero > 0 && !(flds->dot > -1) ? ZERO : SPACE;
		n_dgt = ft_strlen(n);
		flds->dot = flds->dot > -1 && (size_t)(flds->dot) > n_dgt ?
			flds->dot - n_dgt : 0;
		flds->width = (size_t)flds->width > (n_dgt + flds->dot) ?
			flds->width - (n_dgt + flds->dot) : 0;
		print_conv_u_utils(flds, n, fill);
		free(n);
	}
}

/*
**	WORK IN PROGRESS
*/

static void	print_conv_x_utils(t_fields *flds, char *n, char fill)
{
	if (flds->minus > 0)
	{
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
		while (flds->width-- > 0)
			putchar_ftprintf(SPACE, flds);
	}
	else
	{
		while (flds->width-- > 0)
			putchar_ftprintf(fill, flds);
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
	}
}

void		print_conv_x(t_fields *flds, va_list ap)
{
	char	*n;
	char	fill;
	size_t	n_dgt;

	if (!(n = ft_iutoa(va_arg(ap, unsigned int))))
		flds->printed = ERR;
	else
	{
		if (*n == '0' && !(*(n + 1)) && flds->dot == 0)
			*n = '\0';
		fill = flds->zero > 0 && !(flds->dot > -1) ? ZERO : SPACE;
		n_dgt = ft_strlen(n);
		flds->dot = flds->dot > -1 && (size_t)(flds->dot) > n_dgt ?
			flds->dot - n_dgt : 0;
		flds->width = (size_t)flds->width > (n_dgt + flds->dot) ?
			flds->width - (n_dgt + flds->dot) : 0;
		print_conv_x_utils(flds, n, fill);
		free(n);
	}
}
