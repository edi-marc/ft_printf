/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:33:16 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/17 16:40:44 by edi-marc         ###   ########.fr       */
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
			p = (char*)s;
			found = 1;
		}
		s++;
	}
	if (*s == '\0' && c == 0)
		p = (char *)s;
	return (p);
}
