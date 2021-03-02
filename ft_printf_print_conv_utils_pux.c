/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_conv_utils_pux.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:49:50 by edi-marc          #+#    #+#             */
/*   Updated: 2021/03/02 15:56:58 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FLAG '0' is ignored when flag '-' is present
**	FLAG ' ' is ignored when flag '+' is present
**
**	Conversion specifier '':
**		flag '0' results in undefined behavior with 'c'
**		flag '+' results in undefined behavior with 'c'
**		flag '#' results in undefined behavior with 'c'
**		flag ' ' results in undefined behavior with 'c'
**		precision used with 'c', resulting in undefined behavior
**
**	Conversion specifier 'i'/'d':
**		flag '#' results in undefined behavior with 'i'/'d'
**		if a precision is specified, the 0 flag is ignored
*/

#include "libftprintf.h"

void	print_conv_u(t_fields *flds, va_list ap)
{
	flds = 0;
	ap = 0;
}
