/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:45:07 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/08 17:46:17 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	ch;
	int		found;

	p = 0;
	ch = c;
	found = 0;
	while (*s != '\0' && !found)
	{
		if (*s == ch)
		{
			p = (char *)s;
			found = 1;
		}
		s++;
	}
	if (*s == '\0' && c == 0)
		p = (char *)s;
	return (p);
}
