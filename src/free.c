/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:48:09 by guviure           #+#    #+#             */
/*   Updated: 2026/01/22 17:53:44 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void free_map_tab(t_map *map)
{
    int i;

    if (!map || !map->map_tab)
        return ;
    i = 0;
    while (i < map->heightmap)
    {
        free(map->map_tab[i]);
        i++;
    }
    free(map->map_tab);
    map->map_tab = NULL;
}

void	free_map_paths(t_map *map)
{
	if (!map)
		return;
	free(map->no_path);
	free(map->so_path);
	free(map->we_path);
	free(map->ea_path);
}

void	free_img(t_mlx *mlx, t_img *img)
{
	if (!mlx || !img->img)
		return;
	mlx_destroy_image(mlx->ptr, img->img);
	img->img = NULL;
	img->addr = NULL;
}

void	free_textures(t_game *game)
{
	if (!game)
		return;
	free_img(game->mlx, game->tex->no);
	free_img(game->mlx, game->tex->so);
	free_img(game->mlx, game->tex->we);
	free_img(game->mlx, game->tex->ea);
}

void	free_screen(t_game *game)
{
	if (!game)
		return;
	//free_img(game->mlx, &game->mlx->img);
}

void	ft_free_mlx(t_game *game)
{
	if (game->mlx->img)
	{
		mlx_destroy_image(game->mlx->ptr, game->mlx->img->addr);
		free(game->mlx->img);
	}
	if (game->mlx->win)
		mlx_destroy_window(game->mlx->ptr, game->mlx->win);
	mlx_destroy_display(game->mlx->ptr);
	free(game->mlx->ptr);
	free(game->mlx);
}
void	free_mlx(t_game *game)
{
	if (!game || !game->mlx)
		return;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx->ptr);
	free(game->mlx);
	game->mlx = NULL;
}

void	cleanup(t_game *game)
{
	if (!game)
		return;

	free_map_tab(game->map);
	free_map_paths(game->map);
	free_textures(game);
	free_screen(game);
	free_mlx(game);

	free(game);
}
