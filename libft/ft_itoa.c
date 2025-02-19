/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:56:13 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/08 21:56:25 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_sign(long int n)
{
	size_t	s;

	s = 0;
	if (n < 0)
		s++;
	return (s);
}

static size_t	count_digits(long int n)
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

static void	convert(long int n, char *p, size_t s, size_t len)
{
	if (!n)
		*p = 48;
	while (n)
	{
		p[len - 2] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	if (s)
		*p = 45;
}

char	*ft_itoa(int n)
{
	char		*p;
	size_t		len;
	size_t		s;
	size_t		digits;
	long int	ln;

	p = NULL;
	ln = n;
	s = check_sign(ln);
	if (s)
		ln = ln * -1;
	digits = count_digits(ln);
	len = s + digits + 1;
	p = ft_calloc(len, sizeof(*p));
	if (p)
		convert(ln, p, s, len);
	return (p);
}
