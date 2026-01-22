/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:15:39 by guviure           #+#    #+#             */
/*   Updated: 2026/01/19 01:15:26 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode >= 0 && keycode < 256)
		game->key_press[keycode] = 1;
	if (keycode == KEY_LEFT_ARROW)
		game->rot_left = 1;
	if (keycode == KEY_RIGHT_ARROW)
		game->rot_right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < KEY_COUNT)
		game->key_press[keycode] = 0;
	if (keycode == KEY_LEFT_ARROW)
		game->rot_left = 0;
	if (keycode == KEY_RIGHT_ARROW)
		game->rot_right = 0;
	return (0);
}

static int	handle_movement_keys(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->key_press[KEY_W])
	{
		move_forward(game);
		moved = 1;
	}
	if (game->key_press[KEY_S])
	{
		move_backward(game);
		moved = 1;
	}
	if (game->key_press[KEY_A])
	{
		move_left(game);
		moved = 1;
	}
	if (game->key_press[KEY_D])
	{
		move_right(game);
		moved = 1;
	}
	return (moved);
}

static int	handle_rotation_keys(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->rot_left)
	{
		rotate_left(game);
		moved = 1;
	}
	if (game->rot_right)
	{
		rotate_right(game);
		moved = 1;
	}
	return (moved);
}

int	game_loop(t_game *game)
{
	int	moved;

	moved = 0;
	moved |= handle_movement_keys(game);
	moved |= handle_rotation_keys(game);
	if (moved)
		render_frame(game);
	return (0);
}
