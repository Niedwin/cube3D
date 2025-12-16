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

void	put_pixel(char *addr, int line_len, int bpp, int x, int y, int color)
{
	char *pixel;

	pixel = addr + (y * line_len + x * (bpp / 8));
	*(unsigned int *)pixel = color;
}

void	fill_screen(char *addr, int line_len, int bpp, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			put_pixel(addr, line_len, bpp, x, y, color);
			x++;
		}
		y++;
	}
}

	
int	main(int argc, char **argv)
{
	//int	fd;
	(void)argc;
	(void)argv;
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, screenWidth, screenHeight, "cube3D");
	mlx_hook(mlx_win, 17, 0, close_window, NULL);
	fill_screen(addr, line_len, bpp, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
	img = mlx_new_image(mlx, screenWidth, screenHeight);
	addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);

	//fd = check_args_n_fd(argc, argv);
	//read header -> try open n read textures associated
	//read n process map
	//minilibX time
	return (0);
}
