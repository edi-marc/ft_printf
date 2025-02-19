/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_x.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:53:52 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/19 23:47:10 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FLAG '0' is ignored when flag '-' is present
**	FLAG ' ' is ignored when flag '+' is present
**
**	Conversion specifier 'x'\'X':
**		flag '+' results in undefined behavior with 'x'\'X'
**		flag ' ' results in undefined behavior with 'x'\'X'
**		if a precision is specified, the 0 flag is ignored
*/

#include "ft_printf.h"

static void	print_hash_prefix(t_fields *flds)
{
	putchar_ftprintf(ZERO, flds);
	putchar_ftprintf(flds->type, flds);
}

static void	print_conv_x_utils(t_fields *flds, char *n, char fill)
{
	if (flds->minus > 0)
	{
		if (flds->hash > 0)
			print_hash_prefix(flds);
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
		while (flds->width-- > 0)
			putchar_ftprintf(SPACE, flds);
	}
	else
	{
		if (flds->hash > 0 && fill == ZERO)
			print_hash_prefix(flds);
		while (flds->width-- > 0)
			putchar_ftprintf(fill, flds);
		if (flds->hash > 0 && fill != ZERO)
			print_hash_prefix(flds);
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
	}
}

static void	print_conv_x_2(t_fields *flds, char *n)
{
	size_t	n_dgt;

	n_dgt = ft_strlen(n);
	flds->dot = 0;
	if (flds->dot > -1 && ((size_t)(flds->dot) > n_dgt))
		flds->dot = flds->dot - n_dgt;
	flds->width = 0;
	if ((size_t)flds->width > (n_dgt + flds->dot))
		flds->width = flds->width - (n_dgt + flds->dot);
	if (flds->hash > 0)
		flds->width -= LEN_PX;
}

void	print_conv_x(t_fields *flds, va_list ap, char *base)
{
	char	*n;
	char	fill;

	n = ft_iutoa_base(va_arg(ap, unsigned int), base);
	if (!n)
		flds->printed = ERR;
	else
	{
		if (*n == *base && !(*(n + 1)))
		{
			flds->hash = 0;
			if (flds->dot == 0)
				*n = '\0';
		}
		fill = SPACE;
		if (flds->zero > 0 && !(flds->dot > -1))
			fill = ZERO;
		print_conv_x_2(flds, n);
		print_conv_x_utils(flds, n, fill);
		free(n);
	}
}
