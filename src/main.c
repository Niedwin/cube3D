/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:21:20 by guviure           #+#    #+#             */
/*   Updated: 2025/12/15 19:01:06 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}


void	fill_screen(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
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
	mlx_hook(game->win, 2, 1L<<0, key_press, game);
	mlx_hook(game->win, 3, 1L<<1, key_release, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}

void put_pixel(t_img *img, int x, int y, int color)
{
    if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight)
        return;
    char *pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)pixel = color;
}

char **map_tab_malloc(int height, int width, char *map_tab_src[])
{
    int i;
    char **tab = malloc(sizeof(char*) * height);
    if (!tab)
        exit(1);
    for (i = 0; i < height; i++)
    {
        tab[i] = malloc(sizeof(char) * (width + 1));
        if (!tab[i])
            exit(1);
        ft_strlcpy(tab[i], map_tab_src[i], width + 1);
    }
    return tab;
}


int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;

	char *map_tab_src[] = {
    "111111111111111111111111",
    "100000000000000000000001",
    "100000000000000000000001",
    "10000000000N000000000001",
    "100000000000000000000001",
    "111111111111111111111111",
};

game.map.Heightmap = 6;
game.map.Widthmap = 24;
game.map.map_tab = map_tab_malloc(game.map.Heightmap, game.map.Widthmap, map_tab_src);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, screenWidth, screenHeight, "cube3D");
	game.img.img = mlx_new_image(game.mlx, screenWidth, screenHeight);
	game.img.addr = mlx_get_data_addr(game.img.img,
			&game.img.bpp, &game.img.line_len, &game.img.endian);

	init_player(&game);   // ← maintenant il verra le 'N'

	init_hooks(&game);

	printf("Player pos: %.2f %.2f\n", game.player.x, game.player.y);
	printf("Dir: %.2f %.2f\n", game.player.dir_x, game.player.dir_y);
	printf("Plane: %.2f %.2f\n", game.player.plane_x, game.player.plane_y);

	render_frame(&game);  // pour afficher la première frame

	mlx_loop(game.mlx);
	return (0);
}



