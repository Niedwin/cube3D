/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:37 by kguillem          #+#    #+#             */
/*   Updated: 2026/02/07 22:55:45 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	is_map(char *line)
{
	int	map_status;

	map_status = 0;
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		return (0);
	while (*line)
	{
		if (*line == '0' || *line == '1' || *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W' || *line == ' ')
			map_status = 1;
		line++;
	}
	return (map_status);
}

void	calc_size_map(t_map *map, char *line)
{
	int	size;

	size = 0;
	map->height++;
	size = ft_strlen(line) - 1;
	if (map->width < size)
		map->width = size;
}

int	fill_fields(t_game *game, int *map_status, char *line)
{
	if (is_map(line))
		*map_status = 1;
	if (*map_status)
	{
		calc_size_map(game->map, line);
		return (0);
	}
	if (line[0] == 'F' && line[1] == ' ')
		check_floor(game, line);
	else if (line[0] == 'C' && line[1] == ' ')
		check_ceilling(game, line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		check_north(game, game->map, line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		check_south(game, game->map, line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		check_west(game, game->map, line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		check_east(game, game->map, line);
	else if (only_charset(line, "\n"))
		return (1);
	else
		exit_error_free_line(" Invalid Line", game, line);
	return (0);
}

int	read_data_file(t_game *game, int fd)
{
	char	*line;
	int		i;
	int		map_status;

	map_status = 0;
	i = 1;
	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		fill_fields(game, &map_status, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	if (game->map->f_rgb == -1 || game->map->c_rgb == -1)
		exit_error(" Missing Color RGB", game);
	if (!game->map->no_path || !game->map->so_path
		|| !game->map->we_path || !game->map->ea_path)
		exit_error(" Miss Texture", game);
	return (0);
}

int	checkstrchar(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
