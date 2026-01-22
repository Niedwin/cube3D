/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_fill_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:04:21 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/22 17:53:27 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void check_floor(t_map *map, char *line, int i)
{
	if (map->f_rgb == -1)		 // verify said field to proceed only if empty
		parsing_rgb(map, line, line[0]); // fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'F' at line %i\n", i);
	}
}

void check_ceilling(t_map *map, char *line, int i)
{
	if (map->c_rgb == -1)	   // verify said field to proceed only if empty
		parsing_rgb(map, line, line[0]); // fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'C' at line %i\n", i);
	}
}

void	ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
}

int	ft_verif_digit(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_rgb_value(char *new_value, char **tab_value)
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

int	check_rgb_limit(int r, int g, int b, char **tab_value)
{
	if (!(r >= 0 && r <= 255 && g >= 0 && g <= 255
			&& b >= 0 && b <= 255) || tab_value[3])
	{
		printf("Error map ! Please enter a valid RGB value\n");
		return (1);
	}
	return (0);
}

void	fill_rgb_data(t_map *map, char **split_rgb, char direction)
{
	int r;
	int g;
	int b;

	if (ft_verif_digit(split_rgb[0]) && ft_verif_digit(split_rgb[1])
		&& ft_verif_digit(split_rgb[2]))
	{
		r = ft_atoi(split_rgb[0]);
		g = ft_atoi(split_rgb[1]);
		b = ft_atoi(split_rgb[2]);
		if (check_rgb_limit(r, g, b, split_rgb) == 1)
			return ;// a modifier
		else
		{
			if (direction == 'F')
				map->f_rgb = (r << 16) | (g << 8) | b;
			else if (direction == 'C')
				map->c_rgb = (r << 16) | (g << 8) | b;
		}
	}
	ft_free(split_rgb);
	free(split_rgb);
}

void	parsing_rgb(t_map *map, char *line, char direction)
{
	char *new_rgb_line;
	char	**split_rgb;
	
	new_rgb_line = ft_strtrim(line, " \n\tFC");
	split_rgb = ft_split(new_rgb_line, ',');
	fill_rgb_data(map, split_rgb, direction);
}


void fill_floor(t_map *map, char *line, int i)
{
	line = skip_char(line + 2, ' ');
	(void)i;
	(void)map;
	//if (!floor_color_format(header, line))
	//{
	//	printf("Error\nwrong floor color format at line %i\n", i);
	//	return;
	//}
}

void fill_ceiling(t_map *map, char *line, int i)
{
	line = skip_char(line + 2, ' ');
	(void)i;
	(void)map;
	//if (!ceiling_color_format(header, line))
	//{
	//	printf("Error\nwrong ceiling color format at line %i\n", i);
	//	return;
	//}
}
