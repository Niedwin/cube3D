/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:42:15 by mpajot-t          #+#    #+#             */
/*   Updated: 2026/01/17 19:16:45 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	*ns;
	unsigned char	nc;

	ns = (unsigned char *)s;
	nc = (unsigned char)c;
	len = ft_strlen((s));
	while (len >= 0)
	{
		if (nc == ns[len])
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char a[] = "helllo";
	int b = 111;
	printf("Retour : %s\n", ft_strchr(a,b));
}
*/