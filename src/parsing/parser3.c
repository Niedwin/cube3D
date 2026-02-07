/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:48:00 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 22:37:20 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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

void	create_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->height == 0 || game->map->width == 0)
	{
		exit_error("No map in File", game);
		return ;
	}
	game->map->map_tab = malloc(sizeof(char *) * game->map->height);
	if (!game->map->map_tab)
		return ;
	while (i < game->map->height)
	{
		game->map->map_tab[i] = malloc(sizeof(char) * (game->map->width + 1));
		if (!game->map->map_tab[i])
			return ;
		ft_memset(game->map->map_tab[i], ' ', game->map->width);
		game->map->map_tab[i][game->map->width] = '\0';
		i++;
	}
}

void	load_and_read_map(t_game *game, char *filename)
{
	int	fd;
	int	in_fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(" Cannot open map file", game);
	if (read_data_file(game, fd))
	{
		close(fd);
		exit_error(" Error reading map file", game);
	}
	create_map(game);
	close(fd);
	in_fd = open(filename, O_RDONLY);
	if (in_fd < 0)
		exit_error("Cannot reopen map file", game);
	fill_map(game, in_fd);
	check_char_map(game);
	check_open_map(game);
}
