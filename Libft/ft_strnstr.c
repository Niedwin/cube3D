/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:37:04 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/11/06 14:10:37 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1,	const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i] == s2[j] && s1[i] && i < len)
		{
			i++;
			j++;
		}
		if (!s2[j])
			return ((char *)&s1[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char a[] = "Hello world";
	char b[] = "";
	printf("Retour : %s\n",ft_strnstr(a,b,7));
}
*/