/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:23:52 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/27 19:48:09 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_fields(t_fields *flds)
{
	flds->printed = 0;
	flds->minus = 0;
	flds->plus = 0;
	flds->zero = 0;
	flds->space = 0;
	flds->hash = 0;
	flds->width = 0;
	flds->dot = -1;
	flds->type = 0;
}

void	reset_fields(t_fields *flds)
{
	flds->minus = 0;
	flds->plus = 0;
	flds->zero = 0;
	flds->space = 0;
	flds->hash = 0;
	flds->width = 0;
	flds->dot = -1;
	flds->type = 0;
}

void	putchar_ftprintf(char c, t_fields *flds)
{
	ft_putchar_fd(c, STDO);
	(flds->printed)++;
}
