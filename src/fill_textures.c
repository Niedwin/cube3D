/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:50 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/19 01:34:18 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	load_texture(t_game *g, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(g->mlx,
			path, &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len, &tex->endian);
}

void	load_all_textures(t_game *g)
{
	load_texture(g, &g->tex_no, g->map.no_path);
	load_texture(g, &g->tex_so, g->map.so_path);
	load_texture(g, &g->tex_we, g->map.we_path);
	load_texture(g, &g->tex_ea, g->map.ea_path);
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

// Parsing des textures et couleurs
void	parse_textures_colors(t_map *map, char *cub_path)
{
	int		fd;
	char	*line;

	fd = open(cub_path, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening .cub file");
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "NO ", 3))
			map->no_path = ft_strdup(line + 3);
		else if (!ft_strncmp(line, "SO ", 3))
			map->so_path = ft_strdup(line + 3);
		else if (!ft_strncmp(line, "WE ", 3))
			map->we_path = ft_strdup(line + 3);
		else if (!ft_strncmp(line, "SE ", 3))
			map->ea_path = ft_strdup(line + 3);
		else if (line[0] == 'F')
			map->f_rgb = parse_rgb(line + 2);
		else if (line[0] == 'C')
			map->c_rgb = parse_rgb(line + 2);
		free(line);
	}
	close(fd);
}
