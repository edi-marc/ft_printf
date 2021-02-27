/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:07:56 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/27 17:03:14 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	LIBRARY: libftprintf
**	SYNOPSIS: Write formatted output to stdout from the format string FMT
**
**	DESCRIPTION:
**	Writes the C string pointed by format to the standard output (stdout).
**	If format includes format specifiers (subsequences beginning with %),
**	the additional arguments following format are formatted and inserted
**	in the resulting string replacing their respective specifiers.
**
**	ISSUES:
**	This implementation can't handle int overflow on width and/or precision
*/

#include "libftprintf.h"

static char	*get_conv_spec(char *p, t_fields *flds, va_list ap)
{
	while (*++p && ft_strchr(FLAGS, *p))
		get_flag(*p, flds);
	p = get_width(p, flds, ap);
	p = get_precision(p, flds, ap);
	p = get_types(p, flds);
	return (p);
}

static void	print_conv(t_fields *flds, va_list ap)
{
	if (flds->printed != ERR)
	{
		if (flds->type == 'c')
			print_conv_c(flds, ap);
		else if (flds->type == PH)
			print_conv_ph(flds);
		reset_fields(flds);
	}
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*p;
	t_fields	fld;
	t_fields	*flds;

	va_start(ap, fmt);
	p = (char *)fmt;
	flds = &fld;
	init_fields(flds);
	while (*p && flds->printed != ERR)
	{
		while (*p && *p != PH)
		{
			putchar_ftprintf(*p, flds);
			p++;
		}
		if (*p)
		{
			p = get_conv_spec(p, flds, ap);
			print_conv(flds, ap);
		}
	}
	va_end(ap);
	return (flds->printed);
}
