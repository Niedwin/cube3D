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
		p->dir.x = 0;
		p->dir.y = -1;
		p->plane.x = 0.66;
		p->plane.y = 0;
	}
	else if (c == 'S')
	{
		p->dir.x = 0;
		p->dir.y = 1;
		p->plane.x = -0.66;
		p->plane.y = 0;
	}
}

static void	set_ew_direction(t_player *p, char c)
{
	if (c == 'E')
	{
		p->dir.x = 1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = 0.66;
	}
	else if (c == 'W')
	{
		p->dir.x = -1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = -0.66;
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
	g->player.pos.x = x + 0.5;
	g->player.pos.y = y + 0.5;
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
					exit_error("Error\nMultiple players", g);
				set_player(g, x, y, c);
			}
			x++;
		}
		y++;
	}
	if (!found)
		exit_error("Error\nNo player", g);
}
