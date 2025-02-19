/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 00:15:33 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/09/25 21:32:02 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	while (((size_t)i < n) && n != 0)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (s);
}
