/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:30:52 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/27 16:06:16 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = ft_calloc(1, sizeof(*new_elem));
	if (new_elem)
	{
		new_elem->content = content;
		new_elem->next = NULL;
	}
	return (new_elem);
}
