/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iutoa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:43:59 by edi-marc          #+#    #+#             */
/*   Updated: 2021/03/02 17:39:59 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: libft
** SYNOPSIS: convert an unsigned int to ASCII
**
** DESCRIPTION:
** 	The iutoa() function converts an unsigned int to ASCII,
**	returns the number represented as ASCII string,
**	NULL otherwise.
*/

#include "libft.h"

static size_t	count_digits(unsigned int n)
{
	size_t num;

	num = 0;
	if (!n)
		num = 1;
	while (n)
	{
		n = n / 10;
		num++;
	}
	return (num);
}

static void		convert(unsigned int n, char *p, size_t digits)
{
	if (!n)
		*p = 48;
	while (n)
	{
		p[digits - 1] = n % 10 + '0';
		n = n / 10;
		digits--;
	}
}

char			*ft_iutoa(unsigned int n)
{
	char		*p;
	size_t		digits;

	p = NULL;
	digits = count_digits(n);
	if ((p = ft_calloc(digits + 1, sizeof(*p))))
		convert(n, p, digits);
	return (p);
}
