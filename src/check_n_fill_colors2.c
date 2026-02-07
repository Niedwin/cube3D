/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_fill_colors2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:31:50 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 22:18:39 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_rgb_limit(int r, int g, int b, char **tab_value)
{
	if (!(r >= 0 && r <= 255 && g >= 0 && g <= 255
			&& b >= 0 && b <= 255) || tab_value[3])
	{
		printf("Error\n map ! mauvais valeur RGB\n");
		return (1);
	}
	return (0);
}

void	fill_rgb_data(t_game *game, char **split_rgb,
		char direction, char *line)
{
	int	r;
	int	g;
	int	b;

	if (!split_rgb || !game->map)
		return ;
	r = ft_atoi(split_rgb[0]);
	g = ft_atoi(split_rgb[1]);
	b = ft_atoi(split_rgb[2]);
	if (direction == 'F')
		game->map->f_rgb = (r << 16) | (g << 8) | b;
	else if (direction == 'C')
		game->map->c_rgb = (r << 16) | (g << 8) | b;
	else
	{
		ft_free_split(split_rgb);
		free(line);
		exit_error(" Invalid color", game);
	}
	ft_free_split(split_rgb);
}

int	valid_channels(char *line)
{
	int	i;

	i = 0;
	if (line[i] == ',')
		return (0);
	while (line[i] != ',')
		i ++;
	if (line[i + 1] == ',')
		return (0);
	i++;
	while (line[i] != ',')
		i++;
	if (!line[i + 1])
		return (0);
	return (1);
}

int	valid_ranges(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (ft_isdigit(line[j + i]))
			j++;
		if (j > 3)
			return (0);
		else if (j == 3)
		{
			if (atoi(line + i) <= 255)
				i += j;
			else
				return (0);
		}
		else if (j != 0)
			i += j;
		else
			i ++;
	}
	return (1);
}

void	color_format(t_game *game, char *rgb_line, char *line)
{
	if (!only_charset(rgb_line, "0123456789 ,"))
	{
		free(line);
		free(rgb_line);
		exit_error(" Invalid char format in color", game);
	}
	if (char_count(rgb_line, ',') != 2)
	{
		free(line);
		free(rgb_line);
		exit_error(" Invalid amount of color channels", game);
	}
	if (!valid_channels(rgb_line))
	{
		free(line);
		free(rgb_line);
		exit_error(" Missing values beetween color channels", game);
	}
	if (!valid_ranges(rgb_line))
	{
		free(line);
		free(rgb_line);
		exit_error(" Invalid numeric range in color channels", game);
	}
}
