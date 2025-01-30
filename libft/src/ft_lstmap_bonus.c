/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:14:15 by agaga             #+#    #+#             */
/*   Updated: 2024/11/12 13:09:37 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (newnode == NULL)
		{
			ft_lstclear(&newlist, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
