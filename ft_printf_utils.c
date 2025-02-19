/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:24:04 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/19 22:24:07 by emdi-mar         ###   ########.fr       */
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
