/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:10:52 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/13 18:53:47 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;
	int		i;

	p = (char *)b;
	i = 0;
	while (((size_t)i < len) && len != 0)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (b);
}
