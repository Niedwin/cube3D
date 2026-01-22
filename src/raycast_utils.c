/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 02:04:31 by guviure           #+#    #+#             */
/*   Updated: 2026/01/22 17:54:06 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_img	*choose_texture(t_game *g, t_ray *r)
{
	if (r->side == 0 && r->ray_dir.x > 0)
		return (g->tex->no);
	else if (r->side == 0 && r->ray_dir.x < 0)
		return (g->tex->so);
	else if (r->side == 1 && r->ray_dir.y > 0)
		return (g->tex->we);
	else
		return (g->tex->ea);
}

void	get_tex_pos(t_game *g, t_ray *r, t_draw d)
{
	r->tex = choose_texture(g, r);
	if (r->side == 0)
		r->wall_x = g->player.pos.y + r->perp_wall_dist * r->ray_dir.y;
	else
		r->wall_x = g->player.pos.x + r->perp_wall_dist * r->ray_dir.x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (double)(r->tex->height));
	if (r->side == 0 && r->ray_dir.x > 0)
		r->tex_x = r->tex->height - r->tex_x - 1;
	if (r->side == 1 && r->ray_dir.y < 0)
		r->tex_x = r->tex->height - r->tex_x - 1;
	r->stepp = 1.0 * r->tex->height / r->line_height;
	r->tex_pos = (d.start - SCREENHEIGHT / 2 + r->line_height / 2) * r->stepp;
}


void	draw_wall(t_game *g, t_ray *r, t_draw d)
{
	int	y;
	int	color;

	y = d.start;
	if (d.end >= SCREENHEIGHT)
		d.end = SCREENHEIGHT - 1;
	while (y < d.end)
	{
		r->tex_y = (int)r->tex_pos;
		r->tex_pos += r->stepp;
		color = get_pixel(r->tex,
				r->tex_x, r->tex_y);
		if (r->side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(g->mlx->img, d.x, y, color);
		y++;
	}
}

void	draw_floor(t_game *g, t_draw d)
{
	int	y;

	y = d.end;
	while (y < SCREENHEIGHT)
	{
		put_pixel(g->mlx->img, d.x, y, g->map->f_rgb);
		y++;
	}
}

void	draw_ceiling(t_game *g, t_draw d)
{
	int	y;

	y = 0;
	while (y < d.start)
	{
		put_pixel(g->mlx->img, d.x, y, g->map->c_rgb);
		y++;
	}
}
