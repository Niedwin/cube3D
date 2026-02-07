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

int close_window(t_game *game)
{
	cleanup(game); // libère tout proprement
	exit(0);
}

void exit_error(char *msg, t_game *game)
{
	if (game)
		cleanup(game);
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

/* ---------------- DRAWING ---------------- */
int get_pixel(t_img *image, int x, int y)
{
	int pi = y * (image->line_len / 4) + x;
	return (((int *)image->addr)[pi]);
}

void put_pixel(t_img *img, int x, int y, int color)
{
	int pi;

	if (x < 0 || x >= SCREENWIDTH || y < 0 || y >= SCREENHEIGHT)
		return;
	pi = y * (img->line_len / 4) + x;
	((int *)img->addr)[pi] = color;
}

void fill_screen(t_img *img, int color)
{
	int x, y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

/* ---------------- HOOKS ---------------- */
void init_hooks(t_game *game)
{
	ft_bzero(game->key_press, sizeof(int) * KEY_COUNT);
	mlx_hook(game->mlx->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx->ptr, game_loop, game);
}

void print_map(t_map *map)
{
	int i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->map_tab[i]);
		i++;
	}
}

/* ---------------- INIT MLX ---------------- */
void init_mlx(t_mlx *mlx, t_game *game)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		exit_error("MLX initialization failed", game);

	game->mlx->ptr = mlx->ptr;
	game->mlx->win = mlx_new_window(game->mlx->ptr, SCREENWIDTH, SCREENHEIGHT, "CUB3D");
	if (!game->mlx->win)
		exit_error("Window creation failed", game);

	mlx->img->img = mlx_new_image(mlx->ptr, SCREENWIDTH, SCREENHEIGHT);
	if (!mlx->img->img)
		exit_error("Image creation failed", game);

	mlx->img->addr = (int *)mlx_get_data_addr(mlx->img->img, &mlx->img->bpp,
											  &mlx->img->line_len, &mlx->img->endian);
}

/* ---------------- MAIN ---------------- */
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