/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:10:02 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 07:48:28 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.1;
	new_x = game->player.pos.x + game->player.dir.x * MOVE_SPEED;
	new_y = game->player.pos.y + game->player.dir.y * MOVE_SPEED;
	if (game->map->map_tab[(int)(new_y + margin)]
			[(int)(new_x + margin)] != '1' &&
			game->map->map_tab[(int)(new_y - margin)]
			[(int)(new_x + margin)] != '1' &&
			game->map->map_tab[(int)(new_y + margin)]
			[(int)(new_x - margin)] != '1' &&
			game->map->map_tab[(int)(new_y - margin)]
			[(int)(new_x - margin)] != '1')
	{
		game->player.pos.x = new_x;
		game->player.pos.y = new_y;
	}
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.1;
	new_x = game->player.pos.x - game->player.dir.x * MOVE_SPEED;
	new_y = game->player.pos.y - game->player.dir.y * MOVE_SPEED;
	if (game->map->map_tab[(int)(new_y + margin)]
		[(int)(new_x + margin)] != '1' &&
		game->map->map_tab[(int)(new_y - margin)]
		[(int)(new_x + margin)] != '1' &&
		game->map->map_tab[(int)(new_y + margin)]
		[(int)(new_x - margin)] != '1' &&
		game->map->map_tab[(int)(new_y - margin)]
		[(int)(new_x - margin)] != '1')
	{
		game->player.pos.x = new_x;
		game->player.pos.y = new_y;
	}
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.1;
	new_x = game->player.pos.x - game->player.dir.y * MOVE_SPEED;
	new_y = game->player.pos.y + game->player.dir.x * MOVE_SPEED;
	if (game->map->map_tab[(int)(new_y + margin)]
	[(int)(new_x + margin)] != '1' &&
	game->map->map_tab[(int)(new_y - margin)]
	[(int)(new_x + margin)] != '1' &&
	game->map->map_tab[(int)(new_y + margin)]
	[(int)(new_x - margin)] != '1' &&
	game->map->map_tab[(int)(new_y - margin)]
	[(int)(new_x - margin)] != '1')
	{
		game->player.pos.x = new_x;
		game->player.pos.y = new_y;
	}
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.1;
	new_x = game->player.pos.x + game->player.dir.y * MOVE_SPEED;
	new_y = game->player.pos.y - game->player.dir.x * MOVE_SPEED;
	if (game->map->map_tab[(int)(new_y + margin)]
		[(int)(new_x + margin)] != '1' &&
		game->map->map_tab[(int)(new_y - margin)]
		[(int)(new_x + margin)] != '1' &&
		game->map->map_tab[(int)(new_y + margin)]
		[(int)(new_x - margin)] != '1' &&
		game->map->map_tab[(int)(new_y - margin)]
		[(int)(new_x - margin)] != '1')
	{
		game->player.pos.x = new_x;
		game->player.pos.y = new_y;
	}
}
