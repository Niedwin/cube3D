/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:53:16 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 10:35:49 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	verify_map(t_game *game, t_header *header, char *first)
{
	int		height;
	char	*line;
	char	**map;
	int		max_lines;
	int		j;

	max_lines = 1024;
	map = malloc(sizeof(char *) * max_lines);
	if (!map)
	{
		cleanup(game);
		exit(EXIT_FAILURE);
	}
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
			printf("Error\nLigne %d contient des carateres invalides", height);
			j = 0;
			while (j <= height)
            {
                free(map[j]);
                j++;
            }
			free(map);
            cleanup(game);
            exit(EXIT_FAILURE);
		}
		height++;
	}
	return (height);
}

void	verify_exceptions(t_game *game, char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= height)
	{
		if (map[i][0] == '0')
		{
			printf("Error\nLigne %i nest pas ferme\n", i);
			j = 0;
            while (j <= height)
            {
                free(map[j]);
                j++;
            }
            free(map);
            cleanup(game);
            exit(EXIT_FAILURE);
		}
		i++;
	}
}
