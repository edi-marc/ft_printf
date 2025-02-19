/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:04:41 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/08 22:45:13 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: libft
**
** DESCRIPTION:
**	Applies the function 'f' on each character of the string passed as
**	argument, passing its index as first argument.
**	Each character is passed by address to 'f' to be modified if necessary.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			len;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		while ((size_t)i < len)
		{
			f(i, &(s[i]));
			i++;
		}
	}
}
