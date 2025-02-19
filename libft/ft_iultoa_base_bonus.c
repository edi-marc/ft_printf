/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iultoa_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:40:14 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/19 16:48:43 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: libft
** SYNOPSIS: convert an unsigned long int to a string in any base
**
** DESCRIPTION:
** 	The iultoa_base() function converts an unsigned long int
**	to a string in a base specified by the string base.
**	Returns the number represented as ASCII string,
**	NULL otherwise.
**
**	The base 1 case, unary numeral system, is treated as a unique case
*/

#include "libft.h"

static char	*ft_iultoa_unary(unsigned long int n, char *base)
{
	char	*p;

	p = ft_calloc(n + 1, sizeof(*p));
	if (p)
	{
		while (n)
			p[--n] = *base;
	}
	return (p);
}

static size_t	count_digits_b(unsigned long int n, size_t len_b)
{
	size_t	num;

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

static void	convert(unsigned long int n, char *p, size_t digits, char *base)
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

char	*ft_iultoa_base(unsigned long int n, char *base)
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
			p = ft_calloc(digits + 1, sizeof(*p));
			if (p)
				convert(n, p, digits, base);
		}
		else
			p = ft_iultoa_unary(n, base);
	}
	return (p);
}
