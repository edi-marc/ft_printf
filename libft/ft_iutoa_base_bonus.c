/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iutoa_base_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:29:06 by edi-marc          #+#    #+#             */
/*   Updated: 2021/03/03 15:16:50 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: libft
** SYNOPSIS: convert an unsigned int to a string in any base
**
** DESCRIPTION:
** 	The iutoa_base() function converts an unsigned int to a string in a base
**	specified by the string base.
**	Returns the number represented as ASCII string,
**	NULL otherwise.
**
**	The base 1 case, unary numeral system, is treated as a unique case
*/

#include "libft.h"

static char		*ft_iutoa_unary(unsigned int n, char *base)
{
	char	*p;

	if ((p = ft_calloc(n + 1, sizeof(*p))))
	{
		while (n)
			p[--n] = *base;
	}
	return (p);
}

static size_t	count_digits_b(unsigned int n, size_t len_b)
{
	size_t num;

	num = 0;
	if (!n)
		num = 1;
	while (n)
	{
		n = n / len_b;
		num++;
	}
	return (num);
}

static void		convert(unsigned int n, char *p, size_t digits, char *base)
{
	size_t	len_b;

	len_b = ft_strlen(base);
	if (!n)
		*p = base[n];
	while (n)
	{
		p[digits - 1] = base[n % len_b];
		n = n / len_b;
		digits--;
	}
}

char			*ft_iutoa_base(unsigned int n, char *base)
{
	char		*p;
	size_t		digits;
	size_t		len_b;

	p = NULL;
	if (base && *base)
	{
		len_b = ft_strlen(base);
		if (len_b > 1)
		{
			digits = count_digits_b(n, len_b);
			if ((p = ft_calloc(digits + 1, sizeof(*p))))
				convert(n, p, digits, base);
		}
		else
			p = ft_iutoa_unary(n, base);
	}
	return (p);
}
