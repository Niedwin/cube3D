/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:58:28 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 07:47:11 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(-ROT_SPEED)
		- game->player.dir.y * sin(-ROT_SPEED);
	game->player.dir.y = old_dir_x * sin(-ROT_SPEED)
		+ game->player.dir.y * cos(-ROT_SPEED);
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(-ROT_SPEED)
		- game->player.plane.y * sin(-ROT_SPEED);
	game->player.plane.y = old_plane_x * sin(-ROT_SPEED)
		+ game->player.plane.y * cos(-ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(ROT_SPEED)
		- game->player.dir.y * sin(ROT_SPEED);
	game->player.dir.y = old_dir_x * sin(ROT_SPEED)
		+ game->player.dir.y * cos(ROT_SPEED);
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(ROT_SPEED)
		- game->player.plane.y * sin(ROT_SPEED);
	game->player.plane.y = old_plane_x * sin(ROT_SPEED)
		+ game->player.plane.y * cos(ROT_SPEED);
}
