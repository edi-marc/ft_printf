/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_p.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:26:35 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/19 22:34:04 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FLAG '0' is ignored when flag '-' is present
**	FLAG ' ' is ignored when flag '+' is present
**
**	Conversion specifier 'p':
**		flag '0' results in undefined behavior with 'p'
**		flag '#' results in undefined behavior with 'p'
**		flag '+' results in undefined behavior with 'p'
**		flag ' ' results in undefined behavior with 'p'
**		precision used with 'p' conversion specifier,
**			resulting in undefined behavior
*/

#include "libftprintf.h"

static void	print_p_prefix(t_fields *flds)
{
	putchar_ftprintf(ZERO, flds);
	putchar_ftprintf('x', flds);
}

static void	print_conv_p_utils(t_fields *flds, char *n, char fill)
{
	if (flds->minus > 0)
	{
		print_p_prefix(flds);
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
		while (flds->width-- > 0)
			putchar_ftprintf(SPACE, flds);
	}
	else
	{
		if (fill == ZERO)
			print_p_prefix(flds);
		while (flds->width-- > 0)
			putchar_ftprintf(fill, flds);
		if (fill != ZERO)
			print_p_prefix(flds);
		while (flds->dot-- > 0)
			putchar_ftprintf(ZERO, flds);
		while (*n)
			putchar_ftprintf(*n++, flds);
	}
}

void	print_conv_p(t_fields *flds, va_list ap, char *base)
{
	char	*n;
	char	fill;
	size_t	n_dgt;

	n = ft_iultoa_base(va_arg(ap, unsigned long int), base);
	if (!n)
		flds->printed = ERR;
	else
	{
		if (*n == *base && !(*(n + 1)) && flds->dot == 0)
			*n = '\0';
		fill = SPACE;
		if (flds->zero > 0 && !(flds->dot > -1))
			fill = ZERO;
		n_dgt = ft_strlen(n);
		flds->dot = 0;
		if (flds->dot > -1 && ((size_t)(flds->dot) > n_dgt))
			flds->dot = flds->dot - n_dgt;
		flds->width = 0;
		if ((size_t)flds->width > (n_dgt + flds->dot + LEN_PX))
			flds->width = flds->width - (n_dgt + flds->dot + LEN_PX);
		print_conv_p_utils(flds, n, fill);
		free(n);
	}
}
