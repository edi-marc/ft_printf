/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:51:24 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/11 18:53:30 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	new_lst = NULL;
	if (lst && f)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp)
		{
			new_lst = temp;
			lst = lst->next;
		}
		while (lst && new_lst)
		{
			temp = ft_lstnew(f(lst->content));
			if (!temp)
				ft_lstclear(&new_lst, del);
			else
			{
				ft_lstadd_back(&new_lst, temp);
				lst = lst->next;
			}
		}
	}
	return (new_lst);
}
