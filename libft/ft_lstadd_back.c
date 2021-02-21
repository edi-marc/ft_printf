/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:54:22 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/29 11:42:49 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *elem;

	if (lst && new)
	{
		elem = ft_lstlast(*lst);
		if (!elem)
			ft_lstadd_front(lst, new);
		else
			elem->next = new;
	}
}
