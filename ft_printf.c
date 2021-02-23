/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:07:56 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/23 20:34:33 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	LIBRARY: libftprintf
**	SYNOPSIS: Write formatted output to stdout from the format string FMT
**
**	DESCRIPTION:	
*/

#include "libftprintf.h"

int		ft_printf(const char *fmt, ...)
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
			ft_putchar_fd(*p++, STDO);
			flds->printed++;
		}
		if (*p)
			p = check_conv_spec(p, flds);
	}
	va_end(ap);
	return (flds->printed);
}

void	init_fields(t_fields *flds)
{
	flds->printed = 0;
	flds->minus = 0;
	flds->zero = 0;
	flds->star = 0;
	flds->dot = -1;
	flds->type = 0;
}

char	*check_conv_spec(char *p, t_fields *flds)
{
	char	*tmp;

	tmp = ++p;
	while (*p && !(ft_strchr(TYPES, (int)(*p))))
		p++;
	if (!(*p))
		return (tmp);
	else
	{
		p = check_conv(tmp, p, flds);
		return (p);
	}
}

char	*check_conv(char *tmp, char *p, t_fields *flds)
{
	tmp = 0;
	flds = 0;
	return(p);
}

void	print_conv(va_list ap, t_fields *flds)
{
	ap = 0 ;
	flds = 0;
}
