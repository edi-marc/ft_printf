/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:07:04 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/21 15:58:33 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;

	p = NULL;
	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		p = ft_calloc(len_s1 + len_s2 + 1, sizeof(*p));
		if (p)
		{
			ft_strlcat(p, s1, len_s1 + 1);
			ft_strlcat(p, s2, len_s1 + 1 + len_s2 + 1);
		}
	}
	return (p);
}
