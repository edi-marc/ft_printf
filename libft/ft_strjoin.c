/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:51:29 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/08 21:52:59 by emdi-mar         ###   ########.fr       */
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
