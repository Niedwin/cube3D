/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:34:00 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 22:17:44 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_args_n_fd(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("Error\n Wrong amount of arguments\n");
		exit(1);
	}
	if (!check_postfix(argv[1], ".cub"))
	{
		printf("Error\n Invalid file extension, must be '.cub'\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n Cannot open the given '.cub'\n");
		exit(1);
	}
	return (1);
}

void	init_hooks(t_game *game)
{
	ft_bzero(game->key_press, sizeof(int) * KEY_COUNT);
	mlx_hook(game->mlx->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx->ptr, game_loop, game);
}

void	init_mlx(t_mlx *mlx, t_game *game)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		exit_error("MLX initialization failed", game);
	game->mlx->ptr = mlx->ptr;
	game->mlx->win = mlx_new_window(game->mlx->ptr,
			SCREENWIDTH, SCREENHEIGHT, "CUB3D");
	if (!game->mlx->win)
		exit_error("Window creation failed", game);
	mlx->img->img = mlx_new_image(mlx->ptr, SCREENWIDTH, SCREENHEIGHT);
	if (!mlx->img->img)
		exit_error("Image creation failed", game);
	mlx->img->addr = (int *)mlx_get_data_addr(mlx->img->img, &mlx->img->bpp,
			&mlx->img->line_len, &mlx->img->endian);
}
