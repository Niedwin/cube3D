/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:43:19 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 19:43:21 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int a)
{
	int	i;

	i = 0;
	if (a < 0)
	{
		a = -a;
		i++;
	}
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char	*ft_convert_nb(int nb, char *str, int nblen)
{
	int		isnegative;

	isnegative = 0;
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
		isnegative = 1;
	}
	str[nblen] = '\0';
	while (nblen > isnegative)
	{
		str[nblen - 1] = (nb % 10) + '0';
		nb = nb / 10;
		nblen--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nblen;

	nblen = ft_intlen(n);
	if (n == -2147483648)
	{
		str = malloc(12 * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = malloc((nblen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_convert_nb(n, str, nblen));
}
/*
#include <stdio.h>
int main()
{
	int a = -24558;
	char *b = ft_itoa(a);
	printf("Retour : %s\n",b);
}
*/