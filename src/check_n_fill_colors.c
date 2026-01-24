/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_fill_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:04:21 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/23 15:49:16 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void check_floor(t_map *map, char *line, int i)
{
	if (map->f_rgb == -1)				 // verify said field to proceed only if empty
		parsing_rgb(map, line, line[0]); // fill associated field
	else
	{
		printf("Error\nMultiple attribution de 'F' a la ligne %i\n", i);
		exit(EXIT_FAILURE); // TODO exit normalement
	}
}

void check_ceilling(t_map *map, char *line, int i)
{
	if (map->c_rgb == -1)				 // verify said field to proceed only if empty
		parsing_rgb(map, line, line[0]); // fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'C' at line %i\n", i);
		exit(EXIT_FAILURE); // TODO exit normalement
	}
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

void fill_rgb_data(t_map *map, char **split_rgb, char direction)
{
	int r;
	int g;
	int b;

	if (!split_rgb || !map)
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
				map->f_rgb = (r << 16) | (g << 8) | b;
			else if (direction == 'C')
				map->c_rgb = (r << 16) | (g << 8) | b;
			else
			{
				printf("Error \n Pas une couleur RGB : %c\n", direction);
				ft_free_split(split_rgb);
				exit(1); // TODO exit normalement
			}
		}
		else
		{
			printf("Error\n Le RGB n'est pas bon\n"); // TODO exit normalement
			ft_free_split(split_rgb);
			exit(1);
		}
	}
	else
	{
		printf("\nGROS NUMBER RGB PAS VALIDE\n");
		ft_free_split(split_rgb);
		exit(1); // TODO exit normalement
	}
	ft_free_split(split_rgb);
}

void parsing_rgb(t_map *map, char *line, char direction)
{
	char *new_rgb_line;
	char **split_rgb;

	if (!map || !line)
		return;
	if (direction == 'C')
		new_rgb_line = ft_strtrim(line, " \n\tC");
	else
		new_rgb_line = ft_strtrim(line, " \n\tF");
	if (!new_rgb_line)
	{
		printf("Error\n la ligne nest pas au format RGB \n");
		return;
	}
	split_rgb = ft_split(new_rgb_line, ',');
	free(new_rgb_line); // libération ici
	if (!split_rgb)
		return;
	fill_rgb_data(map, split_rgb, direction);
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

