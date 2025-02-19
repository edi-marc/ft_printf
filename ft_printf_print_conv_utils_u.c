/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_u.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:50:00 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/19 22:50:55 by emdi-mar         ###   ########.fr       */
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
**
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

void	print_conv_u(t_fields *flds, va_list ap)
{
	char	*n;
	char	fill;
	size_t	n_dgt;

	n = ft_iutoa(va_arg(ap, unsigned int));
	if (!n)
		flds->printed = ERR;
	else
	{
		if (*n == '0' && !(*(n + 1)) && flds->dot == 0)
			*n = '\0';
		fill = SPACE;
		if (flds->zero > 0 && !(flds->dot > -1))
			fill = ZERO;
		n_dgt = ft_strlen(n);
		flds->dot = 0;
		if (flds->dot > -1 && ((size_t)(flds->dot) > n_dgt))
			flds->dot = flds->dot - n_dgt;
		flds->width = 0;
		if ((size_t)flds->width > (n_dgt + flds->dot))
			flds->width = flds->width - (n_dgt + flds->dot);
		print_conv_u_utils(flds, n, fill);
		free(n);
	}
}
