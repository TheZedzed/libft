/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:30:04 by azeraoul          #+#    #+#             */
/*   Updated: 2021/01/20 11:21:59 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*elem;

	head = NULL;
	if (lst)
	{
		head = ft_lstnew((*f)(lst->content));
		if (head)
		{
			lst = lst->next;
			while (lst)
			{
				elem = ft_lstnew((*f)(lst->content));
				if (!elem)
					ft_lstclear(&head, del);
				ft_lstadd_back(&head, elem);
				lst = lst->next;
			}
		}
	}
	return (head);
}
