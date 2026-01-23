/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 02:05:09 by guviure           #+#    #+#             */
/*   Updated: 2026/01/19 02:05:09 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#include "cube.h"

static void	init_ray(t_game *g, t_ray *r, int x)
{
	r->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	r->ray_dir.x = g->player.dir.x + g->player.plane.x * r->camera_x;
	r->ray_dir.y = g->player.dir.y + g->player.plane.y * r->camera_x;
	r->map.x = (int)g->player.pos.x;
	r->map.y = (int)g->player.pos.y;
	if (r->ray_dir.x == 0)
		r->delta_dist.x = 1e30;
	else
		r->delta_dist.x = fabs(1 / r->ray_dir.x);
	if (r->ray_dir.y == 0)
		r->delta_dist.y = 1e30;
	else
		r->delta_dist.y = fabs(1 / r->ray_dir.y);
}

static void	init_step(t_game *g, t_ray *r)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (g->player.pos.x - r->map.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->map.x + 1.0 - g->player.pos.x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (g->player.pos.y - r->map.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->map.y + 1.0 - g->player.pos.y) * r->delta_dist.y;
	}
}

static void	perform_dda(t_game *g, t_ray *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map.y += r->step.y;
			r->side = 1;
		}
		if (r->map.x < 0 || r->map.y < 0
			|| r->map.x >= g->map->widthmap
			|| r->map.y >= g->map->heightmap)
			exit_error("Error\nRay went out of map bounds", g);
		if (g->map->map_tab[(int)r->map.y][(int)r->map.x] == '1')
			hit = 1;
	}
}

static void	calc_wall_height(t_ray *r, t_draw *d)
{
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist.x - r->delta_dist.x;
	else
		r->perp_wall_dist = r->side_dist.y - r->delta_dist.y;
	r->line_height = (int)(SCREENHEIGHT / r->perp_wall_dist);
	d->start = -r->line_height / 2 + SCREENHEIGHT / 2;
	if (d->start < 0)
		d->start = 0;
	d->end = r->line_height / 2 + SCREENHEIGHT / 2;
	if (d->end >= SCREENHEIGHT)
		d->end = SCREENHEIGHT - 1;
}

void	raycast(t_game *g)
{
	t_ray	r;
	t_draw	d;

	d.x = 0;
	while (d.x < SCREENWIDTH)
	{
		init_ray(g, &r, d.x);
		init_step(g, &r);
		perform_dda(g, &r);
		calc_wall_height(&r, &d);
		get_tex_pos(g, &r, d);
		draw_wall(g, &r, d);
		draw_floor(g, d);
		draw_ceiling(g, d);
		d.x++;
	}
}
