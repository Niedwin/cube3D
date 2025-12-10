/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:46:00 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:41:52 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
/*
#include <stdio.h>
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}
int main()
{
    t_list *lst = NULL;
    int nb1 = 42;
    int nb2 = 24;
    int nb3 = 84;

    // Création du premier nœud
    lst = ft_lstnew(&nb1);
    printf("Liste après création du premier nœud : ");
    print_list(lst);

    // Ajout du deuxième nœud
    ft_lstadd_back(&lst, ft_lstnew(&nb2));
    printf("Liste après ajout du deuxième nœud : ");
    print_list(lst);

    // Ajout du troisième nœud
    ft_lstadd_back(&lst, ft_lstnew(&nb3));
    printf("Liste après ajout du troisième nœud : ");
    print_list(lst);

    // Libération de la mémoire
    while (lst)
    {
        t_list *temp = lst;
        lst = lst->next;
        free(temp);
    }

    return (0);
}
*/