/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:36:30 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/26 16:12:39 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put(int c, int fd)
{
	char r;

	r = c + 48;
	ft_putchar_fd(r, fd);
}

static	void	divide(long int numbr, int fd)
{
	long int num;

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

void			ft_putnbr_fd(int n, int fd)
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
