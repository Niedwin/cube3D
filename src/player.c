/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:32:40 by guviure           #+#    #+#             */
/*   Updated: 2026/01/14 22:32:40 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_ns_direction(t_player *p, char c)
{
	if (c == 'N')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (c == 'S')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
}

static void	set_ew_direction(t_player *p, char c)
{
	if (c == 'E')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (c == 'W')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
}

void	set_direction(t_game *g, char c)
{
	if (c == 'N' || c == 'S')
		set_ns_direction(&g->player, c);
	else if (c == 'E' || c == 'W')
		set_ew_direction(&g->player, c);
}

static void	set_player(t_game *g, int x, int y, char c)
{
	g->player.x = x + 0.5;
	g->player.y = y + 0.5;
	set_direction(g, c);
	g->map.map_tab[y][x] = '0';
}

void	init_player(t_game *g)
{
	int		x;
	int		y;
	int		found;
	char	c;

	y = 0;
	found = 0;
	while (y < g->map.heightmap)
	{
		x = 0;
		while (x < g->map.widthmap)
		{
			c = g->map.map_tab[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (found++)
					exit_error("Error\nMultiple players");
				set_player(g, x, y, c);
			}
			x++;
		}
		y++;
	}
	if (!found)
		exit_error("Error\nNo player");
}
