/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:21:20 by guviure           #+#    #+#             */
/*   Updated: 2026/01/18 23:40:00 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int close_window(t_game *game)
{
	cleanup(game);
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
int	get_pixel(t_img *image, int x, int y)
{
	int	pi;

	pi = y * (image->line_len / 4) + x;
	return (((int *)image->addr)[pi]);
}

void put_pixel(t_img *img, int x, int y, int color)
{

	//char	*pixel;
	int	pi;

	if (x < 0 || x >= SCREENWIDTH || y < 0 || y >= SCREENHEIGHT)
		return ;
	//pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	//*(unsigned int *)pixel = color;

	pi = y * (img->line_len / 4) + x;
	((int *)img->addr)[pi] = color;
}

void fill_screen(t_img *img, int color)
{
	int x;
	int y;

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

/* ---------------- TEMP MAP ---------------- */

char **load_test_map(t_map *map)
{
	static char *map_tmp[] = {"111111111111111111111111", "100000000000000000000001",
							  "100000000000000000000001", "10000000000N000000000001",
							  "100000000000000000000001", "111111111111111111111111"};
	char **tab;
	int i;

	map->heightmap = 6;
	map->widthmap = 24;
	tab = malloc(sizeof(char *) * map->heightmap);
	if (!tab)
		exit_error("malloc failed", NULL);
	for (i = 0; i < map->heightmap; i++)
	{
		tab[i] = ft_strdup(map_tmp[i]);
		if (!tab[i])
		{
			while (i-- > 0) // free ce qui a été alloué avant
				free(tab[i]);
			free(tab);
			exit_error("ft_strdup failed", NULL);
		}
	}
	return tab;
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->heightmap)
	{
		printf("%s\n", map->map_tab[i]);
		i++;
	}
	if (map->no_path)
		printf("%s\n", map->no_path);
	if (map->so_path)
		printf("%s\n", map->so_path);
}
/* ---------------- MAIN ---------------- */

void	init_mlx(t_mlx *mlx, t_game *game)
{
	mlx->ptr = mlx_init();
	game->mlx->ptr = mlx->ptr;
	game->mlx->win = mlx_new_window(game->mlx->ptr, SCREENWIDTH,
			SCREENHEIGHT, "CUB3D NxT");
	mlx->img->img = mlx_new_image(mlx->ptr, SCREENWIDTH, SCREENHEIGHT);
	mlx->img->addr = (int *)mlx_get_data_addr(mlx->img->img, &mlx->img->bpp,
			&mlx->img->line_len, &mlx->img->endian);
}



int main(int argc, char **argv)
{
	t_game *game;

	if (check_args_n_fd(argc, argv))
	{
		game = malloc(sizeof(t_game));
		if (!game)
			exit_error("malloc failed", NULL);
		ft_bzero(game, sizeof(t_game));
		game->map = malloc(sizeof(t_map));
		if (!game->map)
			exit_error("malloc failed", NULL);
		game->mlx = malloc(sizeof(t_mlx));
		if (!game->mlx)
			exit_error("malloc failed", NULL);


		game->tex = malloc(sizeof(t_textures));
		if (!game->tex)
			exit_error("malloc failed", NULL);
		game->mlx->img = malloc(sizeof(t_img));
		
		ft_bzero(game->map, sizeof(t_map));
		game->map->c_rgb = -1;
		game->map->f_rgb = -1;
		game->map->heightmap = 0;
		game->map->widthmap = 0;

		// --- map et textures ---
		load_and_read_map(game, argv[1]);
		print_map(game->map);
		/*
		game->map->map_tab = load_test_map(game->map);
		game->map->no_path = ft_strdup("textures/bluestone.xpm");
		game->map->so_path = ft_strdup("textures/purplestone.xpm");
		game->map->we_path = ft_strdup("textures/mossy.xpm");
		game->map->ea_path = ft_strdup("textures/redbrick.xpm");
		game->map->f_rgb = 0x00B8712A; // sol vert
		game->map->c_rgb = 0x0033C6E3; // ciel bleu
		*/
		// --- mlx ---
		init_mlx(game->mlx, game);

		// --- initialisation ---
		init_player(game);

		game->tex->no = malloc(sizeof(t_img));
		game->tex->so = malloc(sizeof(t_img));
		game->tex->we = malloc(sizeof(t_img));
		game->tex->ea = malloc(sizeof(t_img));
		load_all_textures(game); // charge les 4 textures
		render_frame(game);
		init_hooks(game);

		mlx_loop(game->mlx->ptr);
	}
	return (0);
}
