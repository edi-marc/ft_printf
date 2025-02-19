/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:56:52 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/08 21:57:27 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	len;
	size_t	i;

	p = NULL;
	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		p = ft_calloc(len + 1, sizeof(*p));
		if (p)
		{
			while (i < len)
			{
				p[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (p);
}
