/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:55:10 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/08 21:55:48 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: libft
** SYNOPSIS: split string, with specified character as delimiter, into an array
**			of strings
**
** DESCRIPTION:
**	Allocates (with malloc(3)) and returns an array of strings obtained by
**	splitting ’s’ using the character ’c’ as a delimiter. The array must be
**	ended by a NULL pointer.
*/

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	int		trig;

	i = 0;
	trig = 0;
	while (*s)
	{
		if (*s != c && !trig)
		{
			trig = 1;
			i++;
		}
		else if (*s == c)
			trig = 0;
		s++;
	}
	return (i);
}

static	size_t	count_symbols(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	free_all(char **p)
{
	size_t	i;
	size_t	trig;

	i = 0;
	trig = 2;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (trig);
}

static	size_t	malloc_write_word(size_t len, char **p, char const *s)
{
	size_t	trig;

	trig = 1;
	while (*p)
		p++;
	*p = ft_calloc(len + 1, sizeof(**p));
	if (*p)
		ft_strlcpy(*p, s, len + 1);
	else
		trig = free_all(p);
	return (trig);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	trig;

	p = NULL;
	trig = 0;
	p = ft_calloc(count_words(s, c) + 1, sizeof(*p));
	if (s && p)
	{
		i = 0;
		while (s[i] && trig != 2)
		{
			if (s[i] != c && trig == 0)
				trig = malloc_write_word(count_symbols(&s[i], c), p, &s[i]);
			else if (s[i] == c)
				trig = 0;
			i++;
		}
		if (trig == 2)
			p = NULL;
	}
	return (p);
}
