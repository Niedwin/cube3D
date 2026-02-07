/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:44:09 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 22:42:15 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newelem;
	void	*content;

	if (!f || !lst)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		newelem = ft_lstnew(content);
		if (!newelem)
		{
			del(content);
			ft_lstclear(&new, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new, newelem);
		lst = lst->next;
	}
	return (new);
}
