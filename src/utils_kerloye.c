/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_kerloye.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:51:48 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 07:46:36 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_empty_fields(t_header *header)
{
	if (header->ceiling[3] && header->floor[3] && header->north
		&& header->south && header->east && header->west)
		return (0);
	return (1);
}

char	*skip_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] == c)
		i++;
	return (str + i);
}
