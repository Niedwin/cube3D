/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_fill_colors3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:33:08 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 20:33:37 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	parsing_rgb(t_game *game, char *line, char direction)
{
	char	*new_rgb_line;
	char	**split_rgb;

	if (!game->map || !line)
		return ;
	new_rgb_line = ft_strtrim(line + 1, " \n\t");
	color_format(game, new_rgb_line, line);
	if (!new_rgb_line)
	{
		printf("Error\n la ligne nest pas au format RGB \n");
		return ;
	}
	split_rgb = ft_split(new_rgb_line, ',');
	free(new_rgb_line);
	if (!split_rgb)
		return ;
	fill_rgb_data(game, split_rgb, direction, line);
}

void	fill_floor(t_map *map, char *line, int i)
{
	line = skip_char(line + 2, ' ');
	(void)i;
	(void)map;
}

void	fill_ceiling(t_map *map, char *line, int i)
{
	line = skip_char(line + 2, ' ');
	(void)i;
	(void)map;
}
