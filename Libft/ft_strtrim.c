/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:46:52 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 19:46:54 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*ns;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_find_set(s1[start], set))
		start++;
	while (s1[end] && ft_find_set(s1[end], set))
		end--;
	if (end < start)
		end = start - 1;
	ns = malloc((end - start + 2) * sizeof(char));
	if (!ns)
		return (NULL);
	while (start <= end)
	{
		ns[i] = s1[start];
		i++;
		start++;
	}
	ns[i] = '\0';
	return (ns);
}
/*
#include <stdio.h>
int main()
{
	char a[] = "tripouille   xxx";
	char b[] = "x";
	char *res = ft_strtrim(a,b);
	printf("Retour : %sd\n",res);
}
*/