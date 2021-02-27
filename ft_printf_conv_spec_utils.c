/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_spec_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:12:27 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/27 17:03:16 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This implementation tries to decode the conversion specification also
**	if you put duplicated flags.
**	Symbols in the width or precision field needs to be only numerical digits.
**	The type is mandatory, if a symbol different from the types supported
**	appears in the type field, ERR is returned, and the write is stopped.
*/

#include "libftprintf.h"

void	get_flag(char c, t_fields *flds)
{
	if (c == '-')
		flds->minus++;
	else if (c == '0')
		flds->zero++;
}

char	*get_width(char *p, t_fields *flds, va_list ap)
{
	int	width;

	if (ft_isdigit(*p))
	{
		flds->width += ft_atoi(p);
		while (*p && ft_isdigit(*p))
			p++;
	}
	else if (*p == STAR)
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			flds->minus++;
			width = -width;
		}
		flds->width = width;
		p++;
	}
	return (p);
}

char	*get_precision(char *p, t_fields *flds, va_list ap)
{
	int	prec;

	if (*p == PREC)
	{
		prec = 0;
		p++;
		if (ft_isdigit(*p))
		{
			prec = ft_atoi(p);
			while (*p && ft_isdigit(*p))
				p++;
		}
		else if (*p == STAR)
		{
			prec = va_arg(ap, int);
			if (prec < 0)
				prec = -1;
			p++;
		}
		flds->dot = prec;
	}
	return (p);
}

char	*get_types(char *p, t_fields *flds)
{
	char	*type;

	if (*p && (type = ft_strchr(TYPES, *p)))
	{
		flds->type = *type;
		p++;
	}
	else
		flds->printed = ERR;
	return (p);
}
