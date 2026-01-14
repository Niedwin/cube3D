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

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
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

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;

	/* ==========================
	   PARSING DÉJÀ FAIT AILLEURS
	   ========================== */

	// mlx
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, screenWidth, screenHeight, "cube3D");

	// image
	game.img.img = mlx_new_image(game.mlx, screenWidth, screenHeight);
	game.img.addr = mlx_get_data_addr(game.img.img,
			&game.img.bpp, &game.img.line_len, &game.img.endian);

	// joueur (map déjà prête)
	init_player(&game);

	// DEBUG joueur
	printf("Player pos: %.2f %.2f\n", game.player.x, game.player.y);
	printf("Dir: %.2f %.2f\n", game.player.dir_x, game.player.dir_y);
	printf("Plane: %.2f %.2f\n",
		game.player.plane_x, game.player.plane_y);

	// écran test
	fill_screen(&game.img, 0x00333333);
	mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);

	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);
	return (0);
}


