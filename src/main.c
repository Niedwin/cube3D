/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:21:20 by guviure           #+#    #+#             */
/*   Updated: 2025/12/12 17:29:44 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	int	fd;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 840, 640, "Hello worlds");
	mlx_loop(mlx);

	fd = check_args_n_fd(argc, argv);
	//read header -> try open n read textures associated
	//read n process map
	//minilibX time
	return (0);
}
