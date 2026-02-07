/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:59:04 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 21:03:39 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
}

int	get_pixel(t_img *image, int x, int y)
{
	int	pi;

	pi = y * (image->line_len / 4) + x;
	return (((int *)image->addr)[pi]);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	pi;

	if (x < 0 || x >= SCREENWIDTH || y < 0 || y >= SCREENHEIGHT)
		return ;
	pi = y * (img->line_len / 4) + x;
	((int *)img->addr)[pi] = color;
}

void	fill_screen(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->map_tab[i]);
		i++;
	}
}
