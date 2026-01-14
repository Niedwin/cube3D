/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:16:34 by marvin            #+#    #+#             */
/*   Updated: 2026/01/14 14:16:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_direction(t_game *g, char c)
{
	if (c == 'N')
	{
		g->player.dir_x = 0;
		g->player.dir_y = -1;
		g->player.plane_x = 0.66;
		g->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		g->player.dir_x = 0;
		g->player.dir_y = 1;
		g->player.plane_x = -0.66;
		g->player.plane_y = 0;
	}
	else if (c == 'E')
	{
		g->player.dir_x = 1;
		g->player.dir_y = 0;
		g->player.plane_x = 0;
		g->player.plane_y = 0.66;
	}
	else if (c == 'W')
	{
		g->player.dir_x = -1;
		g->player.dir_y = 0;
		g->player.plane_x = 0;
		g->player.plane_y = -0.66;
	}
}

void	init_player(t_game *g)
{
	int		x;
	int		y;
	int		found;
	char	c;

	found = 0;
	y = 0;
	while (y < g->map.Heightmap)
	{
		x = 0;
		while (x < g->map.Widthmap)
		{
			c = g->map.map_tab[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (found++)
					exit_error("Error\nMultiple players");
				g->player.x = x + 0.5;
				g->player.y = y + 0.5;
				set_direction(g, c);
				g->map.map_tab[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (!found)
		exit_error("Error\nNo player");
}