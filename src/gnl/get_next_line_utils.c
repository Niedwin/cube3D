/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:22:49 by guviure           #+#    #+#             */
/*   Updated: 2025/01/24 00:16:14 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*ssrc;
	char		*ddest;

	ssrc = (const char *)src;
	ddest = (char *)dest;
	if (!ddest && !ssrc)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ddest[i] = ssrc[i];
		i++;
	}
	return (dest);
}

size_t	ft_realloc(void **buffer, size_t old_size, size_t new_size)
{
	void	*new_buffer;

	new_buffer = malloc(new_size);
	if (!new_size)
		return (0);
	if (*buffer)
	{
		ft_memcpy(new_buffer, *buffer, old_size);
		free(*buffer);
	}
	*buffer = new_buffer;
	return (1);
}
