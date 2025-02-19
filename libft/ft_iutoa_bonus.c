/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iutoa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:53:03 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/19 16:54:17 by emdi-mar         ###   ########.fr       */
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
	size_t	num;

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

static void	convert(unsigned int n, char *p, size_t digits)
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

char	*ft_iutoa(unsigned int n)
{
	char		*p;
	size_t		digits;

	p = NULL;
	digits = count_digits(n);
	p = ft_calloc(digits + 1, sizeof(*p));
	if (p)
		convert(n, p, digits);
	return (p);
}
