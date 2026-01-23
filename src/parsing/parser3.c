/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:53:16 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 08:03:13 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	verify_map(t_header *header, char *first)
{
	int		height;
	char	*line;
	char	**map;
	int		max_lines;

	max_lines = 1024;
	map = malloc(sizeof(char *) * max_lines);
	if (!map)
		return (-1); // erreur malloc
	height = 1;
	map[0] = first;
	while (1)
	{
		line = ft_get_next_line(header->fd);
		if (!line)
			break ;
		map[height] = line;
		if (!only_charset(map[height], " 01NSEW\n"))
		{
			printf("Error\nLine %d contains invalid characters", height);
		}
		height++;
	}
	return (height);
}

/*
 * verify the map when there are no whitespaces, such as no open spaces in
 * column 0, no open spaces at max width'
 *
 */
void	verify_exceptions(char **map, int height)
{
	int	i;

	i = 0;
	while (i <= height)
	{
		if (map[i][0] == '0')
		{
			printf("Error\nLine %i is not closed\n", i);
		}
		i++;
	}
}
