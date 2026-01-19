/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:10:02 by guviure           #+#    #+#             */
/*   Updated: 2026/01/19 01:46:16 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.5;
	new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
	if (game->map.map_tab[(int)(new_y + margin)]
			[(int)(new_x + margin)] != '1' &&
			game->map.map_tab[(int)(new_y - margin)]
			[(int)(new_x + margin)] != '1' &&
			game->map.map_tab[(int)(new_y + margin)]
			[(int)(new_x - margin)] != '1' &&
			game->map.map_tab[(int)(new_y - margin)]
			[(int)(new_x - margin)] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.5;
	new_x = game->player.x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.y - game->player.dir_y * MOVE_SPEED;
	if (game->map.map_tab[(int)(new_y + margin)]
		[(int)(new_x + margin)] != '1' &&
		game->map.map_tab[(int)(new_y - margin)]
		[(int)(new_x + margin)] != '1' &&
		game->map.map_tab[(int)(new_y + margin)]
		[(int)(new_x - margin)] != '1' &&
		game->map.map_tab[(int)(new_y - margin)]
		[(int)(new_x - margin)] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.5;
	new_x = game->player.x - game->player.dir_y * MOVE_SPEED;
	new_y = game->player.y + game->player.dir_x * MOVE_SPEED;
	if (game->map.map_tab[(int)(new_y + margin)]
	[(int)(new_x + margin)] != '1' &&
	game->map.map_tab[(int)(new_y - margin)]
	[(int)(new_x + margin)] != '1' &&
	game->map.map_tab[(int)(new_y + margin)]
	[(int)(new_x - margin)] != '1' &&
	game->map.map_tab[(int)(new_y - margin)]
	[(int)(new_x - margin)] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.5;
	new_x = game->player.x + game->player.dir_y * MOVE_SPEED;
	new_y = game->player.y - game->player.dir_x * MOVE_SPEED;
	if (game->map.map_tab[(int)(new_y + margin)]
		[(int)(new_x + margin)] != '1' &&
		game->map.map_tab[(int)(new_y - margin)]
		[(int)(new_x + margin)] != '1' &&
		game->map.map_tab[(int)(new_y + margin)]
		[(int)(new_x - margin)] != '1' &&
		game->map.map_tab[(int)(new_y - margin)]
		[(int)(new_x - margin)] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}
