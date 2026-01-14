/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:57:25 by marvin            #+#    #+#             */
/*   Updated: 2026/01/14 13:57:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_ray(t_game *g, t_ray *r, int x)
{
	r->camera_x = 2 * x / (double)screenWidth - 1;
	r->ray_dir_x = g->player.dir_x + g->player.plane_x * r->camera_x;
	r->ray_dir_y = g->player.dir_y + g->player.plane_y * r->camera_x;
	r->map_x = (int)g->player.x;
	r->map_y = (int)g->player.y;
	r->delta_dist_x = fabs(1 / r->ray_dir_x);
	r->delta_dist_y = fabs(1 / r->ray_dir_y);
}
static void	init_step(t_game *g, t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->player.x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - g->player.x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->player.y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - g->player.y) * r->delta_dist_y;
	}
}
static void	perform_dda(t_game *g, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (g->map.map_tab[r->map_y][r->map_x] == '1')
			hit = 1;
	}
}
static void	calc_wall_height(t_ray *r, int *start, int *end)
{
	int	line_height;

	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
	line_height = (int)(screenHeight / r->perp_wall_dist);
	*start = -line_height / 2 + screenHeight / 2;
	*end = line_height / 2 + screenHeight / 2;
	if (*start < 0)
		*start = 0;
	if (*end >= screenHeight)
		*end = screenHeight - 1;
}
static void	draw_wall(t_game *g, int x, int start, int end)
{
	while (start < end)
	{
		put_pixel(&g->img, x, start, 0x00FFFFFF);
		start++;
	}
}
void	raycast(t_game *g)
{
	int		x;
	t_ray	r;
	int		start;
	int		end;

	x = 0;
	while (x < screenWidth)
	{
		init_ray(g, &r, x);
		init_step(g, &r);
		perform_dda(g, &r);
		calc_wall_height(&r, &start, &end);
		draw_wall(g, x, start, end);
		x++;
	}
}





