/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_p.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:47:34 by edi-marc          #+#    #+#             */
/*   Updated: 2021/03/04 16:47:18 by edi-marc         ###   ########.fr       */
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

void		print_conv_p(t_fields *flds, va_list ap, char *base)
{
	char	*n;
	char	fill;
	size_t	n_dgt;

	if (!(n = ft_iultoa_base(va_arg(ap, unsigned long int), base)))
		flds->printed = ERR;
	else
	{
		if (*n == *base && !(*(n + 1)) && flds->dot == 0)
			*n = '\0';
		fill = flds->zero > 0 && !(flds->dot > -1) ?
			ZERO : SPACE;
		n_dgt = ft_strlen(n);
		flds->dot = flds->dot > -1 && (size_t)(flds->dot) > n_dgt ?
			flds->dot - n_dgt : 0;
		flds->width = (size_t)flds->width > (n_dgt + flds->dot + LEN_PX) ?
			flds->width - (n_dgt + flds->dot + LEN_PX) : 0;
		print_conv_p_utils(flds, n, fill);
		free(n);
	}
}
