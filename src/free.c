/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:26:54 by guviure           #+#    #+#             */
/*   Updated: 2026/01/22 20:39:50 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void free_map_tab(t_map *map)
{
    int i;

    if (!map || !map->map_tab)
        return;
    i = 0;
    while (i < map->heightmap)
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

void free_map_paths(t_map *map)
{
    if (!map)
        return;
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

void free_rgb_split(char **split)
{
    if (!split)
        return;
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
    if (!mlx || !img)
        return;
    if (img->img)
    {
        mlx_destroy_image(mlx->ptr, img->img);
        img->img = NULL;
        img->addr = NULL;
    }
}

void free_textures(t_game *game)
{
    if (!game || !game->tex)
        return;
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

void free_mlx(t_game *game)
{
    if (!game || !game->mlx)
        return;
    if (game->mlx->img)
    {
        if (game->mlx->img->img)
            mlx_destroy_image(game->mlx->ptr, game->mlx->img->img);
        free(game->mlx->img);
        game->mlx->img = NULL;
    }
    if (game->mlx->win)
        mlx_destroy_window(game->mlx->ptr, game->mlx->win);
    if (game->mlx->ptr)
    {
        mlx_destroy_display(game->mlx->ptr);
        free(game->mlx->ptr);
        game->mlx->ptr = NULL;
    }
    free(game->mlx);
    game->mlx = NULL;
}

void ft_free_split(char **split)
{
    int i = 0;
    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void cleanup(t_game *game)
{
    if (!game)
        return;
    free_map_tab(game->map);
    free_map_paths(game->map);
    free_textures(game);
    free_mlx(game);
    if (game->map)
    {
        free(game->map);
        game->map = NULL;
    }
    if (game->tex)
    {
        free(game->tex);
        game->tex = NULL;
    }
    free(game);
}
