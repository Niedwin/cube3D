/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:48:07 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 10:48:07 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_textures_structure(t_game *game)
{
	game->tex = malloc(sizeof(t_textures));
	if (!game->tex)
		exit_error("malloc failed", game);
	ft_bzero(game->tex, sizeof(t_textures));
	game->tex->no = ft_calloc(sizeof(t_img), 1);
	game->tex->so = ft_calloc(sizeof(t_img), 1);
	game->tex->we = ft_calloc(sizeof(t_img), 1);
	game->tex->ea = ft_calloc(sizeof(t_img), 1);
}

void	init_mlx_structure(t_game *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		exit_error("malloc failed", game);
	ft_bzero(game->mlx, sizeof(t_mlx));
	game->mlx->img = malloc(sizeof(t_img));
	if (!game->mlx->img)
		exit_error("malloc failed", game);
}

void	init_map_structure(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		exit_error("malloc failed", game);
	ft_bzero(game->map, sizeof(t_map));
	game->map->c_rgb = -1;
	game->map->f_rgb = -1;
	game->map->height = 0;
	game->map->width = 0;
}

t_game	*init_game_structure(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_error("malloc failed", NULL);
	ft_bzero(game, sizeof(t_game));
	init_map_structure(game);
	init_mlx_structure(game);
	init_textures_structure(game);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!check_args_n_fd(argc, argv))
		exit_error("Invalid arguments", NULL);
	game = init_game_structure();
	load_and_read_map(game, argv[1]);
	print_map(game->map);
	init_mlx(game->mlx, game);
	init_player(game);
	load_all_textures(game);
	render_frame(game);
	init_hooks(game);
	mlx_loop(game->mlx->ptr);
	cleanup(game);
	return (0);
}
/*
int main(int argc, char **argv)
{
	t_game *game;

	if (!check_args_n_fd(argc, argv))
		exit_error("Invalid arguments", NULL);

	game = malloc(sizeof(t_game));
	if (!game)
		exit_error("malloc failed", NULL);
	ft_bzero(game, sizeof(t_game));

	game->map = malloc(sizeof(t_map));
	if (!game->map)
		exit_error("malloc failed", game);
	ft_bzero(game->map, sizeof(t_map));
	game->map->c_rgb = -1;
	game->map->f_rgb = -1;

	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		exit_error("malloc failed", game);
	ft_bzero(game->mlx, sizeof(t_mlx));
	game->tex = malloc(sizeof(t_textures));
	if (!game->tex)
		exit_error("malloc failed", game);
	ft_bzero(game->tex, sizeof(t_textures));
	game->mlx->img = malloc(sizeof(t_img));
	if (!game->mlx->img)
		exit_error("malloc failed", game);

	game->map->height = 0;
	game->map->width = 0;
	game->tex->no = ft_calloc(sizeof(t_img), 1);
	game->tex->so = ft_calloc(sizeof(t_img), 1);
	game->tex->we = ft_calloc(sizeof(t_img), 1);
	game->tex->ea = ft_calloc(sizeof(t_img), 1);
	// --- map et textures ---
	load_and_read_map(game, argv[1]);
	print_map(game->map);

	// --- initialisation mlx ---
	init_mlx(game->mlx, game);

	// --- initialisation joueur ---
	init_player(game);

	// --- allocation textures img ---

	load_all_textures(game); // charge les 4 textures

	render_frame(game);
	init_hooks(game);

	mlx_loop(game->mlx->ptr);

	// sécurité : jamais atteint, mais propre
	cleanup(game);
	return (0);
}
*/