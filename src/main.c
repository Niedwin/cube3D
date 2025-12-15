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
	
int	main(int argc, char **argv)
{
	//int	fd;
	(void)argc;
	(void)argv;
	void	*mlx;
	void	*mlx_win;
	//void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, screenWidth, screenHeight, "cube3D");
	mlx_hook(mlx_win, 17, 0, close_window, NULL);
	mlx_loop(mlx);

	//fd = check_args_n_fd(argc, argv);
	//read header -> try open n read textures associated
	//read n process map
	//minilibX time
	return (0);
}
