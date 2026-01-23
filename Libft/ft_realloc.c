/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:34:53 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 17:58:00 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_realloc(void **buffer, size_t old_size, size_t new_size)
{
	void	*new_buffer;

	if(new_size == 0)
		return (0);
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
