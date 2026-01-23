/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:50 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/23 08:32:09 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	load_texture(t_game *g, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(g->mlx->ptr,
			path, &tex->width, &tex->height);
	tex->addr = (int *)mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len, &tex->endian);
}

void	load_all_textures(t_game *g)
{
	load_texture(g, g->tex->no, g->map->no_path);
	load_texture(g, g->tex->so, g->map->so_path);
	load_texture(g, g->tex->we, g->map->we_path);
	load_texture(g, g->tex->ea, g->map->ea_path);
}

int	parse_rgb(char *line)
{
	int	r;
	int	g;
	int	b;

	while (*line == ' ')
		line++;
	r = atoi(line);
	while (*line && *line != ',')
		line++;
	if (*line == ',')
		line++;
	g = atoi(line);
	while (*line && *line != ',')
		line++;
	if (*line == ',')
		line++;
	b = atoi(line);
	return ((r << 16) | (g << 8) | b);
}
