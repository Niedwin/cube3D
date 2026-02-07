/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_fill_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:04:21 by kguillem          #+#    #+#             */
/*   Updated: 2026/02/07 19:30:59 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void check_floor(t_game *game, char *line)
{
	if (game->map->f_rgb == -1)				 // verify said field to proceed only if empty
		parsing_rgb(game, line, line[0]); // fill associated field
	else
		exit_error(" Multiple F iteration", game); // TODO exit normalement
}

void check_ceilling(t_game *game, char *line)
{
	if (game->map->c_rgb == -1)				 // verify said field to proceed only if empty
		parsing_rgb(game, line, line[0]); // fill associated field
	else
		exit_error(" Multiple C iteration", game);
}

void ft_free(char **result)
{
	int i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
}

int ft_verif_digit(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);

    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_rgb_value(char *new_value, char **tab_value)
{
	if (new_value)
		free(new_value);
	if (!tab_value[0] || !tab_value[1] || !tab_value[2] || tab_value[3])
	{
		ft_free(tab_value);
		free(tab_value);
		return (1);
	}
	return (0);
}

int check_rgb_limit(int r, int g, int b, char **tab_value)
{
	if (!(r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) || tab_value[3])
	{
		printf("Error\n map ! mauvais valeur RGB\n");
		return (1);
	}
	return (0);
}

void fill_rgb_data(t_game *game, char **split_rgb, char direction, char *line)
{
	int r;
	int g;
	int b;

	if (!split_rgb || !game->map)
		return;
	if (ft_verif_digit(split_rgb[0]) && ft_verif_digit(split_rgb[1]) &&
		ft_verif_digit(split_rgb[2]))
	{
		r = ft_atoi(split_rgb[0]);
		g = ft_atoi(split_rgb[1]);
		b = ft_atoi(split_rgb[2]);
		if (check_rgb_limit(r, g, b, split_rgb) == 0)
		{
			if (direction == 'F')
				game->map->f_rgb = (r << 16) | (g << 8) | b;
			else if (direction == 'C')
				game->map->c_rgb = (r << 16) | (g << 8) | b;
			else
			{
				ft_free_split(split_rgb);
				free(line);
				exit_error(" Not a RGB value", game);
			}
		}
		else
		{
			ft_free_split(split_rgb);
			free(line);
			exit_error(" Wrong RGB value1", game);
		}
	}
	else
	{
		ft_free_split(split_rgb);
		free(line);
		exit_error(" Wrong RGB value2", game);
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
	i ++;
	while (line[i] != ',')
		i ++;
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
		while (ft_isdigit(line[i]))
			j++;
		if (j > 3)
			return (0);
		else if (j == 3)
		{
			if (line[i] <= '2' && line[i + 1] <= '5' && line[i + 2] <= '5')
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

void parsing_rgb(t_game *game, char *line, char direction)
{
	char *new_rgb_line;
	char **split_rgb;

	if (!game->map || !line)
		return;
	new_rgb_line = ft_strtrim(line + 1, " \n\t");
	color_format(game, new_rgb_line, line);
	if (!new_rgb_line)
	{
		printf("Error\n la ligne nest pas au format RGB \n");
		return;
	}
	split_rgb = ft_split(new_rgb_line, ',');
	free(new_rgb_line); // libération ici
	if (!split_rgb)
		return;
	fill_rgb_data(game, split_rgb, direction, line);
}

void fill_floor(t_map *map, char *line, int i)
{
	line = skip_char(line + 2, ' ');
	(void)i;
	(void)map;
}

void fill_ceiling(t_map *map, char *line, int i)
{
	line = skip_char(line + 2, ' ');
	(void)i;
	(void)map;
}

