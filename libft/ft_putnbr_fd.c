/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:01:22 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/08 22:02:02 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put(int c, int fd)
{
	char	r;

	r = c + 48;
	ft_putchar_fd(r, fd);
}

static	void	divide(long int numbr, int fd)
{
	long int	num;

	num = numbr;
	if (numbr / 10)
	{
		num = numbr % 10;
		numbr = numbr / 10;
		divide(numbr, fd);
		put(num, fd);
	}
	else
		put(num, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	lnb;

	lnb = n;
	if (lnb < 0)
	{
		lnb = lnb * -1;
		ft_putchar_fd(45, fd);
	}
	divide(lnb, fd);
}
