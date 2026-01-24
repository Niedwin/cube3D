/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:51:07 by mpajot-t          #+#    #+#             */
/*   Updated: 2026/01/22 09:14:35 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return ((void *)&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char a[] = "defg";
	int b = 102;
	printf("Retour : %p\n",ft_memchr(a,b,4));
}
*/