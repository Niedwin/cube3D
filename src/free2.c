/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 07:56:49 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 15:42:38 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void free_mlx(t_game *game)
{
    if (!game || !game->mlx)
        return ;
    if (game->mlx->img)
    {
        if (game->mlx->ptr && game->mlx->img->img)
            mlx_destroy_image(game->mlx->ptr, game->mlx->img->img);
        free(game->mlx->img);
        game->mlx->img = NULL;
    }
    if (game->mlx->ptr && game->mlx->win)
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

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	cleanup(t_game *game)
{
	if (!game)
		return ;
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

