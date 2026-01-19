/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 02:04:31 by guviure           #+#    #+#             */
/*   Updated: 2026/01/19 02:50:24 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_img	*choose_texture(t_game *g, t_ray *r)
{
	if (r->side == 0 && r->ray_dir_x > 0)
		return (&g->tex_no);
	else if (r->side == 0 && r->ray_dir_x < 0)
		return (&g->tex_so);
	else if (r->side == 1 && r->ray_dir_y > 0)
		return (&g->tex_we);
	else
		return (&g->tex_ea);
}

int	calc_tex_x(t_ray *r, t_img *tex, t_game *g)
{
	double	wall_x;
	int		tex_x;

	if (r->side == 0)
		wall_x = g->player.y + r->perp_wall_dist * r->ray_dir_y;
	else
		wall_x = g->player.x + r->perp_wall_dist * r->ray_dir_x;
	wall_x -= (int)wall_x;
	tex_x = (int)(wall_x * tex->width);
	if ((r->side == 0 && r->ray_dir_x > 0)
		|| (r->side == 1 && r->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

int	get_tex_color(t_game *g, t_ray *r, t_draw d, int y)
{
	t_img	*tex;
	int		tex_x;
	int		tex_y;
	int		line_height;

	line_height = d.end - d.start;
	tex = choose_texture(g, r);
	tex_x = calc_tex_x(r, tex, g);
	tex_y = (y - d.start) * tex->height / line_height;
	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	return (*(unsigned int *)(tex->addr + tex_y
		* tex->line_len + tex_x * (tex->bpp / 8)));
}

void	draw_floor_ceiling(t_game *g, t_draw d)
{
	int	y;

	y = 0;
	while (y < d.start && y < SCREENHEIGHT)
	{
		put_pixel(&g->img, d.x, y, g->map.c_rgb);
		y++;
	}
	y = d.end;
	while (y < SCREENHEIGHT)
	{
		put_pixel(&g->img, d.x, y, g->map.f_rgb);
		y++;
	}
}

void	draw_wall(t_game *g, t_ray *r, t_draw d)
{
	int	y;
	int	line_height;
	int	color;

	y = d.start;
	line_height = d.end - d.start;
	while (y < d.end && y < SCREENHEIGHT)
	{
		color = get_tex_color(g, r, d, y);
		put_pixel(&g->img, d.x, y, color);
		y++;
	}
}
