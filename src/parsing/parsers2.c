/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:03:28 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 23:04:37 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_arround(char **map, int i, int j)
{
	if (checkstrchar(map[i][j + 1], "10ESWN"))
		return (1);
	if (checkstrchar(map[i][j - 1], "10ESWN"))
		return (1);
	if (checkstrchar(map[i + 1][j], "10ESWN"))
		return (1);
	if (checkstrchar(map[i - 1][j], "10ESWN"))
		return (1);
	return (0);
}

int	check_char_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		if (only_charset(game->map->map_tab[i], "01NSEW ") == 0)
			exit_error(" Invalid char in map", game);
		i++;
	}
	return (0);
}

int	check_open_map(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (only_charset(game->map->map_tab[0], "1 ") == 0
		|| only_charset(game->map->map_tab[game->map->height - 1], "1 ") == 0)
		exit_error(" Open Map", game);
	while (i < game->map->height - 1)
	{
		j = 1;
		if (checkstrchar(game->map->map_tab[i][0], "1 ")
			|| checkstrchar(game->map->map_tab[i][game->map->width - 1], "1 "))
			exit_error(" Open Map", game);
		while (j < game->map->width - 1)
		{
			if (checkstrchar(game->map->map_tab[i][j], "0NSEW") == 0
				&& check_arround(game->map->map_tab, i, j) == 1)
				exit_error(" Open Map", game);
			j++;
		}
		i++;
	}
	return (0);
}

int	write_map_line(t_map *map, char	*line, int i)
{
	int	j;

	j = 0;
	while (line[j] && j < map->width)
	{
		if (line[j] == ' ')
		{
			map->map_tab[i][j] = ' ';
		}
		else if (line[j] == '\n')
		{
			map->map_tab[i][j] = ' ';
		}
		else
		{
			map->map_tab[i][j] = line[j];
		}
		j++;
	}
	return (1);
}

void	fill_map(t_game *game, int fd)
{
	char	*line;
	int		map_status;
	int		i;

	i = 0;
	map_status = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line))
			map_status = 1;
		if (map_status)
		{
			if (!write_map_line(game->map, line, i++))
			{
				free(line);
				cleanup(game);
				exit(1);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
