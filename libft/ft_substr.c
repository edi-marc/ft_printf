/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:27:22 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/08 20:27:28 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	adj_len(char const *s, unsigned int start, size_t len)
{
	size_t		a_len;
	size_t		s_len;

	a_len = 0;
	s_len = ft_strlen(s);
	if (start < s_len)
	{
		a_len = s_len - start;
		if (a_len > len)
			a_len = len;
	}
	return (a_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	len_s;

	p = NULL;
	if (s)
	{
		len = adj_len(s, start, len);
		p = ft_calloc(len + 1, sizeof(*p));
	}
	if (p)
	{
		len_s = ft_strlen(s);
		i = 0;
		while (start < len_s && i < len)
		{
			p[i] = s[start];
			start++;
			i++;
		}
	}
	return (p);
}
