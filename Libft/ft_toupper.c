/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:47:16 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 19:47:18 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && 'z' >= c)
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
int main()
{
	char a = 'a';
	a = ft_toupperr(a);
	printf("result = %c",a);
}
*/