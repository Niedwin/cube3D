/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:46:58 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 19:47:00 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_l(size_t l, unsigned int start, char const *s)
{
	if (l > ft_strlen(s) - start)
		return (l = ft_strlen(s) - start);
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t l)
{
	size_t	i;
	char	*ns;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		ns = malloc(1);
		if (!ns)
			return (NULL);
		ns[0] = '\0';
		return (ns);
	}
	l = check_l (l, start, s);
	ns = malloc((l + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	while (i < l && s[start + i])
	{
		ns[i] = s[start + i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
/*
#include <stdio.h>
int main()
{
	char a[] = "Hello world";
	char *b = ft_substr(a,4,7);
	printf("Retour : %s\n",b);
}
*/