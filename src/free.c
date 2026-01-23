/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:26:54 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 12:23:25 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_map_tab(t_map *map)
{
	int	i;

	if (!map || !map->map_tab)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->map_tab[i])
		{
			free(map->map_tab[i]);
			map->map_tab[i] = NULL;
		}
		i++;
	}
	free(map->map_tab);
	map->map_tab = NULL;
}

void	free_map_paths(t_map *map)
{
	if (!map)
		return ;
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
}

void	free_rgb_split(char **split)
{
	if (!split)
		return ;
	if (split[0])
		free(split[0]);
	if (split[1])
		free(split[1]);
	if (split[2])
		free(split[2]);
	free(split);
}

void free_img(t_mlx *mlx, t_img *img)
{
    if (!mlx || !mlx->ptr || !img)
        return;
    if (img->img)
    {
        mlx_destroy_image(mlx->ptr, img->img);
        img->img = NULL;
        img->addr = NULL;
    }
}

void	free_textures(t_game *game)
{
	if (!game || !game->tex)
		return ;
	free_img(game->mlx, game->tex->no);
	free_img(game->mlx, game->tex->so);
	free_img(game->mlx, game->tex->we);
	free_img(game->mlx, game->tex->ea);
	if (game->tex->no)
		free(game->tex->no);
	if (game->tex->so)
		free(game->tex->so);
	if (game->tex->we)
		free(game->tex->we);
	if (game->tex->ea)
		free(game->tex->ea);
	game->tex->no = NULL;
	game->tex->so = NULL;
	game->tex->we = NULL;
	game->tex->ea = NULL;
}