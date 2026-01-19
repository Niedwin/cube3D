/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:36:59 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:50:55 by mpajot-t         ###   ########.fr       */
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
