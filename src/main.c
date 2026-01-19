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

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= SCREENWIDTH || y < 0 || y >= SCREENHEIGHT)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	fill_screen(t_img *img, int color)
{
	int	x;
	int	y;

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

void	init_hooks(t_game *game)
{
	ft_bzero(game->key_press, sizeof(int) * KEY_COUNT);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}

// ---------------- TEMP MAP ----------------
char	**load_test_map(t_map *map)
{
	static char	*map_tmp[] = {
        "111111111111111111111111",
        "100000000000000000000001",
        "100000000000000000000001",
        "10000000000N000000000001",
        "100000000000000000000001",
        "111111111111111111111111"
    };
    int i;
    char **tab;

    map->heightmap = 6;
    map->widthmap = 24;
    tab = malloc(sizeof(char *) * map->heightmap);
    if (!tab)
        exit(1);
    i = 0;
    while (i < map->heightmap)
    {
        tab[i] = ft_strdup(map_tmp[i]);
        i++;
    }
    return tab;
}

// ---------------- MAIN ----------------
int main(int argc, char **argv)
{
    t_game game;

    (void)argc;
    (void)argv;
    ft_bzero(&game, sizeof(t_game));

    // --- map et textures ---
    game.map.map_tab = load_test_map(&game.map);
    game.map.no_path = "textures/bluestone.xpm";
    game.map.so_path = "textures/purplestone.xpm";
    game.map.we_path = "textures/mossy.xpm";
    game.map.ea_path = "textures/redbrick.xpm";
    game.map.f_rgb = 0x00B8712A; // sol vert
    game.map.c_rgb = 0x0033C6E3; // ciel bleu

    // --- mlx ---
    game.mlx = mlx_init();
    if (!game.mlx)
        exit_error("mlx_init failed");
    game.win = mlx_new_window(game.mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
    game.img.img = mlx_new_image(game.mlx, SCREENWIDTH, SCREENHEIGHT);
    game.img.addr = mlx_get_data_addr(game.img.img,
            &game.img.bpp, &game.img.line_len, &game.img.endian);

    // --- initialisation ---
    init_player(&game);
    load_all_textures(&game); // charge les 4 textures
    render_frame(&game);
    init_hooks(&game);

    mlx_loop(game.mlx);
    return (0);
}
